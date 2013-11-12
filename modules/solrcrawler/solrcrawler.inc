<?php
use Symfony\Component\DomCrawler\Crawler;
use Symfony\Component\DomCrawler\Link;
use Symfony\Component\CssSelector\CssSelector;

/**
 * Build Solr document.
 *
 * @param string $pagekey
 * @param string $url
 * @param string $title
 * @param string $body
 * @param string $path
 * @return ApacheSolrDocument
 */
function solrcrawler_build_document($pagekey, $url, $title, $body) {
  module_load_include('inc', 'apachesolr', 'apachesolr.index');

  $document = new ApacheSolrDocument();
  $document->id = apachesolr_document_id($pagekey, 'solrcrawler');
  $document->site = url(NULL, array('absolute' => TRUE));
  $document->hash = apachesolr_site_hash();
  $document->entity_id = 1;
  $document->entity_type = 'solrcrawler';
  $document->bundle = 'page';
  $document->bundle_name = t('Page');
  $document->language = LANGUAGE_NONE;
  $document->url = $url;

  $document->addField('label', $title);
  $document->addField('content', strip_tags($body));

  $document->addField('domain_id', 1);
  $document->addField('domain_site', 1);

  // Allow other modules to alter the document.
  $context = array('pagekey' => $pagekey);
  drupal_alter('solrcrawler_document', $document, $context);

  return $document;
}

/**
 * DOMCrawler doesn't have a exclude function yet see:
 * https://github.com/symfony/symfony/pull/9157
 *
 * @param Crawler $crawler
 */
function _solrcrawler_domcrawler_exclude(Crawler $crawler, $excludeSelectors) {
  $document = new \DOMDocument('1.0', 'UTF-8');
  $root = $document->appendChild($document->createElement('_root'));
  $crawler->rewind();
  $root->appendChild($document->importNode($crawler->current(), true));
  $domxpath = new \DOMXPath($document);

  foreach ($excludeSelectors as $selector) {
    $crawlerInverse = $domxpath->query(CssSelector::toXPath($selector));
    foreach ($crawlerInverse as $elementToRemove) {
      $parent = $elementToRemove->parentNode;
      $parent->removeChild($elementToRemove);
    }
  }
  $crawler->clear();
  $crawler->add($document);
}

/**
 * Find links in the crawler and add them to the solrcrawler_page table.
 *
 * @param object $site
 * @param array $pagedata
 * @param Crawler $nodeCrawler
 * @param string $from_url
 */
function _solrcrawler_index_page_crawl($site, $pagedata, $nodeCrawler, $from_url) {
  // Retrieve links for indexing and adding to page table.
  $new_depth = $pagedata['depth']+1;
  if ($new_depth <= $site->max_depth) {
    $linkNodes = $nodeCrawler->filter('a');
    foreach ($linkNodes as $linkNode) {
      // Link already creates absolute links for us.
      $link = new Link($linkNode, $from_url);

      // Only start crawling the page if it's from current domain.
      $link_data = parse_url($link->getUri());
      $url_data = parse_url($from_url);
      if ($link_data['host'] == $url_data['host']) {
        $new_pagedata = _solrcrawler_get_pagedata(
          _solrcrawler_generate_pagekey($site, $link->getUri()),
          array(
            'site_id' => $site->site_id,
            'url' => $link->getUri(),
            'title' => trim(strip_tags($linkNode->nodeValue)),
            'depth' => $new_depth,
          )
        );

        db_merge('solrcrawler_page')
          ->key(array('pagekey' => $new_pagedata['pagekey']))
          ->fields($new_pagedata)
          ->execute();
      }
    };
  }
}

/**
 * Fetch page and update Solr index.
 *
 * @param string $url
 * @param object $site
 */
function _solrcrawler_index_page($url, $site) {
  // Load required libaries.
  solrcrawler_load_vendor();

  // Define a pagekey for use in the db.
  $pagekey = _solrcrawler_generate_pagekey($site, $url);
  $pagedata = _solrcrawler_get_pagedata($pagekey, array('url' => $url, 'site_id' => $site->site_id));

  // Retrieve the page.
  $result = drupal_http_request($url, array('max_redirects' => 2));

  if ($result->code == 200 && $result->data) {
    // Setup basic document.
    $document = array();
    $document['url'] = $url;
    $document['title'] = $pagedata['title'];
    $document['body'] = '';

    if (strpos($result->headers['content-type'], 'text/html') !== FALSE) {
      $crawler = new Crawler($result->data);

      if ($site->content_include) {
        $included = $crawler->filter($site->content_include)->each(function (Crawler $nodeCrawler, $i) {
          return $nodeCrawler;
        });
      }
      else {
        $included = array($crawler);
      }

      // Set the page title.
      $document['title'] = $crawler->filter('title')->text();

      foreach ($included as $nodeCrawler) {
        if ($site->exclude) {
          // Remove from excluded.
          _solrcrawler_domcrawler_exclude($nodeCrawler, explode(',', $site->content_exclude));
        }

        // Add HTML for the index.
        $document['body'] .= $nodeCrawler->html();

        // Crawl for new pages.
        _solrcrawler_index_page_crawl($site, $pagedata, $nodeCrawler, $url);
      }
    }

    // Set latest crawl data.
    $pagedata['date'] = time();

    // Allow other modules to interact.
    module_invoke_all('solrcrawler_index', $site, $result, $pagedata, $document);

    // add to solr
    solrcrawler_save_page($pagedata, $document);
  }
  else if ($result->code == 404) {
    // Page not found. Delete from solr index and page table.
    solrcrawler_delete_page($pagekey);
  }
  else {
    watchdog('solrcrawler', 'There was an error crawling !pagekey.<pre>@data</pre>', array('!pagekey' => $pagekey, '@data' => print_r($result, TRUE)), WATCHDOG_ERROR);
  }
}