<?php

/**
 * Page callback for synonyms textfile.
 */
function solr_synonyms_generate_txt() {
  $output = array();

  // Fetch base terms if applicable.
  $base_url = variable_get('solr_synonyms_base', '');
  if ($base_url) {
    $data = drupal_http_request($base_url);
    if ($data->code == 200) {
      $lines = array_filter(drupal_map('trim', explode("\n", $data->data)));
      foreach ($lines as $line) {
        list($term, $synonyms) = array_map('trim', explode('=>', $line, 2));
        $synonyms = array_filter(array_unique(array_map('trim', explode(',', $synonyms))));
        $output[$term] = $synonyms;
      }
    }
  }

  // Add our terms.
  $terms = db_select('solr_synonyms', 's')
    ->fields('s', array('keyword', 'synonyms'))
    ->orderBy('s.keyword', 'ASC')
    ->execute();
  foreach ($terms as $term) {
    $synonyms = array_filter(array_unique(array_map('trim', explode(',', $term->synonyms))));
    if (isset($output[$term->keyword])) {
      $output[$term->keyword] = array_unique(array_merge($output[$term->keyword], $synonyms));
    }
    else {
      $output[$term->keyword] = $synonyms;
    }
  }

  // Output synonyms.
  drupal_add_http_header('Content-Type', 'text/plain; utf-8');
  foreach ($output as $term => $synonyms) {
    print $term . ' => ' . implode(', ', $synonyms) . "\n";
  }
}
