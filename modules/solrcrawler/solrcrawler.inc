<?php

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
function solrcrawler_build_document($pagekey, $url, $title, $body, $path = NULL) {
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

  if ($path) {
    $document->addField('path', $path);
    $document->addField('path_alias', drupal_get_path_alias($path));
  }

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
 * Fetch page and update Solr index.
 *
 * @param string $url
 * @param object $site
 */
function _solrcrawler_index_page($url, $site) {
  $pagekey = 'crawler/' . $site->name . '/' . md5($url);
  if ($page = _solrcrawler_fetch_page($url, $site)) {
    solrcrawler_save_page($pagekey, $url, $page->title, $page->content);
  }
  else {
    solrcrawler_delete_page($pagekey);
  }
}

/**
 * Fetch title, content and links from page.
 *
 * @param string $url
 * @param object $site
 * @return object
 *   ->title (string)
 *   ->content (string)
 *   ->links = array(
 *     'http://...',
 *     ...,
 *   )
 * @todo make configurable
 */
function _solrcrawler_fetch_page($url, $site) {
  $data = drupal_http_request($url);
  if ($data->code == 200) {
    $html = $data->data;

    $title = '';
    if (preg_match('/\\<title\\>(.*?)\\<\\/title\\>/si', $html, $match)) {
      $title = html_entity_decode($match[1]);
    }

    // @todo: Extract content from $html.
    // @todo: Remove content content_filter



    $output = new stdClass();
    $output->title = $title;
    $output->content = $html;
    $output->links = array();
    return $output;
  }
  return FALSE;
}

/**
 * Extract part of HTML.
 *
 * @param string $html
 * @param string $open
 */
function _solrcrawler_get_content($html, $open = '<div id="content">') {
  $output = '';
  if (!preg_match('/^<([a-z0-9]+)[^a-z0-9]/si', $open, $match)) {
    return FALSE;
  }
  $tag = $match[1];
  $html = explode($open, $html, 2);
  if (isset($html[1])) {
    $parts = preg_split('/(\<\/?' . preg_quote($tag, '/') . ')/', $html[1], -1, PREG_SPLIT_DELIM_CAPTURE);
    $open = 0;
    foreach ($parts as $part) {
      switch ($part) {
        case "<$tag":
          ++$open;
          break;
        case "</$tag":
          --$open;
          if ($open < 0) {
            return $output;
          }
          break;
      }
      $output .= $part;
    }
  }
  return $output;
}
