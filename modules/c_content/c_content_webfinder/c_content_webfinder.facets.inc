<?php

/**
 * Build and render the available facet options.
 * @return type
 */
function _c_content_webfinder_build_facets() {
  // Retrieve the static search results for this request.
  $search_results = _c_content_webfinder_do_search_query();

  if (!$search_results) {
    return FALSE;
  }

  $content = '';

  $facets = $search_results->xpath('//mylex:facet');
  $active = _c_content_webfinder_get_active_facet_items();
  $items = $active['facets'];
  $facet_names = $active['facet_names'];
  foreach ($facets as $facet) {
    foreach ($facet->children('mylex', TRUE)->facetOption as $facet_option) {
      $attributes = $facet_option->attributes();

      if (empty($attributes['text']) || $attributes['text'] == '0001') {
        // In some odd cases the facet has no text, set it to unknown.
        $attributes['text'] = t('Unknown');
      }

      $facet_text = $attributes['text'];
      if (strpos($facet_text, 'lijst') !== FALSE) {
        // Strip list (lijst) from the facet text.
        $facet_text = str_replace('lijst', '', $facet_text);
      }
      $facet_text = ucfirst(trim($facet_text));

      // Save every facet option to store the options between requests.
      db_merge('c_content_webfinder_facets')
          ->key(array('uuid' => $attributes['id']))
          ->fields(array(
            'text' => $facet_text,
            'source_name' => (string) $facet['id'],
            'source_human_name' => (string) $facet['text'],
          ))
          ->execute();

      // Build the text representation of the facet.
      $text = html_entity_decode($facet_text . ' (' . $attributes['totalResults'] . ')');

      // Extract the 'refine' parameter value for the facet.
      $output_array = array();
      preg_match('/&refine=(.*)(?=&search)/', $attributes['href'], $output_array);

      $path = current_path();
      $items[(string) $facet['id']][] = l($text, $path, array('query' => array('refine' => urldecode($output_array[1]))));

      if (!empty($facet['text'])) {
        $facet_names[(string) $facet['id']] = $facet['text'];
      }
      else {
        $facet_names[(string) $facet['id']] = $facet['id'];
      }
    }
  }
  foreach ($items as $facet_key => $facet) {
    // Allow the facet key to be translated.
    $content .= theme('item_list', array(
      'items' => $facet,
      'title' => t('Filter by !title', array('!title' => (string) $facet_names[$facet_key])),
      'attributes' => array('class' => array('c-content-facet-' . $facet_key)),
      )
    );
  }

  return $content;
}

/**
 * Get active facet item and render it.
 * @return type
 */
function _c_content_webfinder_get_active_facet_items() {
  $active_items = array();
  $facet_names = array();
  if (isset($_GET['refine'])) {
    // Facets are selected.
    $facet_items = explode(',', filter_xss($_GET['refine']));
    $original = $facet_items;
    foreach ($facet_items as $key => $facet_item) {
      $condition = urlencode(implode(',', $facet_items));

      $result = db_select('c_content_webfinder_facets', 'f')
          ->fields('f', array('text', 'source_name', 'source_human_name'))
          ->condition('f.uuid', $condition, '=')
          ->execute()
          ->fetch();

      if ($result) {
        $active_items[$result->source_name][] = l('(-) ' . html_entity_decode($result->text), current_path(), array(
          'attributes' => array('class' => array('active')),
        ));

        $facet_names[$result->source_name] = $result->source_human_name;
      }

      unset($facet_items[$key]);
    }
  }

  return array('facets' => array_reverse($active_items), 'facet_names' => $facet_names);
}
