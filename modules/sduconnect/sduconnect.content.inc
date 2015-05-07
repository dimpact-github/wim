<?php

/**
 * @file
 * Mapping of XML to node content.
 */

/**
 * Populate node object with PDC content.
 *
 * @param DOMXPath $xpath
 * @param object $node
 */
function sduconnect_set_pdc_content($xpath, $node) {
  $xpath->registerNameSpace('m', 'http://www.sduconnect.nl/Productoverzicht');
  $xpath->registerNameSpace('dcterms', 'http://purl.org/dc/terms/');
  $xpath->registerNameSpace('overheid', 'http://standaarden.overheid.nl/owms/terms/');
  $xpath->registerNameSpace('overheidproduct', 'http://standaarden.overheid.nl/product/terms/');
  $xpath->registerNameSpace('overheidsc', 'http://standaarden.overheid.nl/sc/terms/');

  $node->type = 'product';
  $node->title = (string) $xpath->query('//m:page/m:product/m:name')->item(0)->nodeValue;

  // Body field.
  $body = '';
  $field = $xpath->query('//m:page/m:product/m:description');
  if ($field->length) {
    $body .= $field->item(0)->nodeValue;
  }
  $fields = array(
    'Let op' => $xpath->query('//m:page/m:product/m:notice'),
    'Voorwaarden' => $xpath->query('//m:page/m:product/m:conditions'),
    'Aanpak' => $xpath->query('//m:page/m:product/m:procedure'),
    'Termijn' => $xpath->query('//m:page/m:product/m:period'),
    'Bezwaar en beroep' => $xpath->query('//m:page/m:product/m:appeal'),
    'Kosten' => $xpath->query('//m:page/m:product/m:costs'),
    'Contact' => $xpath->query('//m:page/m:product/m:contact'),
    'Indienperiode' => $xpath->query('//m:page/m:product/m:subsidies'),
    'Beschikbaar budget' => $xpath->query('//m:page/m:product/m:subsidies_budget'),
    'Maximale bijdrage' => $xpath->query('//m:page/m:product/m:subsidies_maximale_bijdrage'),
  );
  foreach ($fields as $title => $field) {
    $content = $field->length > 0 ? $field->item(0)->nodeValue : '';
    if (preg_match('/[a-z0-9]/si', strip_tags($content))) {
      $body .= '<h2>**' . check_plain($title) . '</h2>' . $content;
    }
  }
  $node->body = array(LANGUAGE_NONE => array(array(
    'value' => $body,
    'format' => 'filtered_html',
  )));

  // Tags.
  $a = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:doelgroepen/m:doelgroep'));
  $b = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:themes/m:theme/m:main/m:name'));
  $c = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:themes/m:theme/m:subthemes/m:subtheme/m:name'));
  $d = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:vind_themes/m:vind_theme/m:name'));
  $e = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/overheidproduct:scproduct/overheidproduct:meta/overheidproduct:owmsmantel/dcterms:subject'));
  drush_print(implode(',', $a));
  drush_print(implode(',', $b));
  drush_print(implode(',', $c));
  drush_print(implode(',', $d));
  drush_print(implode(',', $e));
  $tags = array_unique(array_merge($a, $b, $c, $d, $e));
  $items = sduconnect_tags($tags);
  $node->field_tags = array(LANGUAGE_NONE => $items);

  // Related laws.
  $names = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:law_rules/m:law_rule/m:law_rule_name'));
  $urls = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:law_rules/m:law_rule/m:url'));
  $items = array();
  foreach ($names as $i => $name) {
    $items[] = array(
      'url' => $urls[$i],
      'title' => $name,
    );
  }
  $node->field_related_laws = array(LANGUAGE_NONE => $items);

  // More information.
  $names = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:product_links/m:product_link/m:product_link_name'));
  $urls = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:product_links/m:product_link/m:product_link_url'));
  $items = array();
  foreach ($names as $i => $name) {
    $items[] = array(
      'url' => $urls[$i],
      'title' => $name,
    );
  }
  $node->field_more_information = array(LANGUAGE_NONE => $items);

  // Forms.
  $names = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:formulieren_extern/m:formulier/m:label'));
  $urls = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:formulieren_extern/m:formulier/m:href'));
  $items = array();
  foreach ($names as $i => $name) {
    $items[] = array(
      'url' => $urls[$i],
      'title' => $name,
    );
  }
  $node->field_forms = array(LANGUAGE_NONE => $items);

  // Request online.
  $url = sduconnect_nodelist_to_string($xpath->query('//m:page/m:product/overheidproduct:scproduct/overheidproduct:meta/overheidproduct:scmeta/overheidproduct:aanvraagURL/@resourceIdentifier'));
  $items = array();
  if ($url) {
    $items[] = array(
      'url' => $url,
      'title' => 'Online aanvragen',
    );
  }
  $node->field_request_online = array(LANGUAGE_NONE => $items);

  // Samenwerkende Catalogi
  $categories = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:doelgroepen/m:doelgroep'));
  $items = array();
  foreach ($categories as $category) {
    if ($category === 'organisatie/ondernemer') {
      $category = 'ondernemer';
    }
    $items[] = array(
      'value' => $category,
    );
  }
  $node->field_sc_audience = array(LANGUAGE_NONE => $items);

  // Location.
  $locations = array();
  $name = sduconnect_nodelist_to_string($xpath->query('//m:page/m:product/m:indieningsadressen/m:instantie/m:naam'));
  $street = sduconnect_nodelist_to_string($xpath->query('//m:page/m:product/m:indieningsadressen/m:instantie/m:p_straat'));
  $number = sduconnect_nodelist_to_string($xpath->query('//m:page/m:product/m:indieningsadressen/m:instantie/m:p_nummer'));
  $postal_code = sduconnect_nodelist_to_string($xpath->query('//m:page/m:product/m:indieningsadressen/m:instantie/m:p_postcode'));
  $po_box = sduconnect_nodelist_to_string($xpath->query('//m:page/m:product/m:indieningsadressen/m:instantie/m:p_po_box'));
  $city = sduconnect_nodelist_to_string($xpath->query('//m:page/m:product/m:indieningsadressen/m:instantie/m:p_woonplaats'));
  $location = array(
    'lid' => NULL,
    'name' => $name,
    'street' => $street ? trim("$street $number") : ($po_box ? "Postbus $po_box" : ''),
    'additional' => '',
    'city' => $city,
    'province' => NULL,
    'postal_code' => $postal_code,
    'country' => NULL,
    'latitude' => NULL,
    'longitude' => NULL,
    'source' => NULL,
    'inhibit_geocode' => TRUE,
  );
  $settings = variable_get('location_settings_node_product', array());
  $location['location_settings'] = $settings;
  if ($location['street']) {
    location_save($location);
    $locations[] = $location;
  }

  $name = sduconnect_nodelist_to_string($xpath->query('//m:page/m:product/m:uitvoerende_instanties/m:instantie/m:naam'));
  $street = sduconnect_nodelist_to_string($xpath->query('//m:page/m:product/m:uitvoerende_instanties/m:instantie/m:p_straat'));
  $number = sduconnect_nodelist_to_string($xpath->query('//m:page/m:product/m:uitvoerende_instanties/m:instantie/m:p_nummer'));
  $postal_code = sduconnect_nodelist_to_string($xpath->query('//m:page/m:product/m:uitvoerende_instanties/m:instantie/m:p_postcode'));
  $po_box = sduconnect_nodelist_to_string($xpath->query('//m:page/m:product/m:uitvoerende_instanties/m:instantie/m:p_po_box'));
  $city = sduconnect_nodelist_to_string($xpath->query('//m:page/m:product/m:uitvoerende_instanties/m:instantie/m:p_woonplaats'));
  $location = array(
    'lid' => NULL,
    'name' => $name,
    'street' => $street ? trim("$street $number") : ($po_box ? "Postbus $po_box" : ''),
    'additional' => '',
    'city' => $city,
    'province' => NULL,
    'postal_code' => $postal_code,
    'country' => NULL,
    'latitude' => NULL,
    'longitude' => NULL,
    'source' => NULL,
    'inhibit_geocode' => TRUE,
  );
  $settings = variable_get('location_settings_node_product', array());
  $location['location_settings'] = $settings;
  if ($location['street']) {
    location_save($location);
    $locations[] = $location;
  }

  $node->field_location = array(LANGUAGE_NONE => $locations);

  // Start- and enddate.
  $start = sduconnect_nodelist_to_string($xpath->query('//m:page/m:product/m:subsidies_startdate'));
  if ($start) {
    $start = implode('-', array_reverse(explode('-', $start))) . ' 00:00:00';
  }
  $end = sduconnect_nodelist_to_string($xpath->query('//m:page/m:product/m:subsidies_enddate'));
  if ($end) {
    $end = implode('-', array_reverse(explode('-', $end))) . ' 00:00:00';
  }
  $items = array();
  if ($start) {
    $items[] = array(
      'value' => $start,
      'value2' => $end,
      'timezone' => variable_get('date_default_timezone', 'Europe/Amsterdam'),
      'timezone_db' => 'UTC',
      'date_type' => 'datetime',
    );
  }
  $node->field_date = array(LANGUAGE_NONE => $items);

}

/**
 * Populate node object with VAC content.
 *
 * @param DOMXPath $xpath
 * @param object $node
 * @param boolean $private Import private fields.
 */
function sduconnect_set_vac_content($xpath, &$node, $private = FALSE) {
  $xpath->registerNameSpace('vac', 'http://standaarden.overheid.nl/vac/');
  $xpath->registerNameSpace('dcterms', 'http://purl.org/dc/terms/');
  $xpath->registerNameSpace('overheid', 'http://standaarden.overheid.nl/owms/terms/');
  $xpath->registerNameSpace('overheidvac', 'http://standaarden.overheid.nl/vac/terms/');

  $node->type = 'vac';
  $node->title = sduconnect_nodelist_to_string($xpath->query('//vac:vacs/vac:vac/vac:body/vac:kanaal/vac:vraag'));

  // Body.
  $body = sduconnect_nodelist_to_string($xpath->query('//vac:vacs/vac:vac/vac:body/vac:kanaal/vac:antwoord/vac:antwoordTekst'));
  $body .= sduconnect_nodelist_to_string($xpath->query('//vac:vacs/vac:vac/vac:body/vac:kanaal/vac:antwoord/vac:antwoordProductVeld'));
  if ($private) {
    $body .= sduconnect_nodelist_to_string($xpath->query('//vac:vacs/vac:vac/vac:body/vac:kanaal/vac:onderwaterantwoord/vac:onderwaterantwoordTekst'));
    $body .= sduconnect_nodelist_to_string($xpath->query('//vac:vacs/vac:vac/vac:body/vac:kanaal/vac:onderwaterantwoord/vac:onderwaterantwoordProductVeld'));
  }
  $node->body = array(LANGUAGE_NONE => array(array(
    'value' => $body,
    'format' => 'filtered_html',
  )));

  // Explanation.
  $value = sduconnect_nodelist_to_string($xpath->query('//vac:vacs/vac:vac/vac:body/vac:kanaal/vac:toelichting'));
  $items = array();
  if (preg_match('/[a-z0-9]/si', strip_tags($value))) {
    $items[] = array(
      'value' => $value,
      'format' => 'filtered_html',
    );
  }
  $node->field_explanation = array(LANGUAGE_NONE => $items);

  // Related items.
  $ids = sduconnect_nodelist_to_array($xpath->query('//vac:vacs/vac:vac/vac:body/vac:verwijzingProduct/@resourceIdentifier'));
  $items = array();
  $nodes = db_select('sduconnect_item', 'i')
    ->fields('i', array('nid'))
    ->condition('external_id', $ids)
    ->execute()
    ->fetchAll();
  foreach ($nodes as $item) {
    $items[] = array('target_id' => $item->nid);
  }
  $node->field_related_pdc_vac = array(LANGUAGE_NONE => $items);

  // Tags.
  $a = sduconnect_nodelist_to_array($xpath->query('//vac:vacs/vac:vac/vac:meta/vac:owmsmantel/dcterms:audience'));
  $b = sduconnect_nodelist_to_array($xpath->query('//vac:vacs/vac:vac/vac:meta/vac:vacmeta/vac:trefwoord'));
  $tags = array_unique(array_merge($a, $b));
  $items = sduconnect_tags($tags);
  $node->field_tags = array(LANGUAGE_NONE => $items);

  // Location.
  $locations = array();
  $name = sduconnect_nodelist_to_string($xpath->query('//vac:vacs/vac:vac/vac:body/vac:kanaal/vac:antwoord/vac:antwoordAdres/vac:instantie/vac:naam'));
  $street = sduconnect_nodelist_to_string($xpath->query('//vac:vacs/vac:vac/vac:body/vac:kanaal/vac:antwoord/vac:antwoordAdres/vac:instantie/vac:p_straat'));
  $number = sduconnect_nodelist_to_string($xpath->query('//vac:vacs/vac:vac/vac:body/vac:kanaal/vac:antwoord/vac:antwoordAdres/vac:instantie/vac:p_nummer'));
  $postal_code = sduconnect_nodelist_to_string($xpath->query('//vac:vacs/vac:vac/vac:body/vac:kanaal/vac:antwoord/vac:antwoordAdres/vac:instantie/vac:p_postcode'));
  $po_box = sduconnect_nodelist_to_string($xpath->query('//vac:vacs/vac:vac/vac:body/vac:kanaal/vac:antwoord/vac:antwoordAdres/vac:instantie/vac:p_po_box'));
  $city = sduconnect_nodelist_to_string($xpath->query('//vac:vacs/vac:vac/vac:body/vac:kanaal/vac:antwoord/vac:antwoordAdres/vac:instantie/vac:p_woonplaats'));
  $location = array(
    'lid' => NULL,
    'name' => $name,
    'street' => $street ? trim("$street $number") : ($po_box ? "Postbus $po_box" : ''),
    'additional' => '',
    'city' => $city,
    'province' => NULL,
    'postal_code' => $postal_code,
    'country' => NULL,
    'latitude' => NULL,
    'longitude' => NULL,
    'source' => NULL,
    'inhibit_geocode' => TRUE,
  );
  $settings = variable_get('location_settings_node_vac', array());
  $location['location_settings'] = $settings;
  if ($location['street']) {
    location_save($location);
    $locations[] = $location;
  }
  $node->field_location = array(LANGUAGE_NONE => $locations);

  // More information.
  $names = sduconnect_nodelist_to_array($xpath->query('//vac:vacs/vac:vac/vac:body/vac:kanaal/vac:verwijzingOverigeInfo'));
  $urls = sduconnect_nodelist_to_array($xpath->query('//vac:vacs/vac:vac/vac:body/vac:kanaal/vac:verwijzingOverigeInfo/@resourceIdentifier'));
  $items = array();
  foreach ($names as $i => $name) {
    $items[] = array(
      'url' => $urls[$i],
      'title' => $name,
    );
  }
  $node->field_more_information = array(LANGUAGE_NONE => $items);
}

/**
 * Convert DOMXML nodelist to string.
 *
 * @param DOMNodeList $nodelist
 * @return array
 */
function sduconnect_nodelist_to_string($nodelist) {
  if ($nodelist->length) {
    return $nodelist->item(0)->nodeValue;
  }
  return '';
}

/**
 * Convert DOMXML nodelist to array.
 *
 * @param DOMNodeList $nodelist
 * @return array
 */
function sduconnect_nodelist_to_array($nodelist) {
  $output = array();
  foreach ($nodelist as $node) {
    $output[] = $node->nodeValue;
  }
  return $output;
}

/**
 * Get term id's for tags.
 *
 * @param string $names
 * @return array
 */
function sduconnect_tags($names) {
  $output = array();
  $vocab = 'tags';
  $names = array_filter(array_unique(array_map('trim', $names)));
  foreach ($names as $name) {
    $query = db_select('taxonomy_term_data', 'td')
      ->fields('td', array('tid'))
      ->condition('td.name', $name)
      ->range(0, 1);
    $v = $query->join('taxonomy_vocabulary', 'v', 'td.vid = v.vid');
    $query->condition("$v.machine_name", $vocab);
    $tid = $query->execute()->fetchField();
    if (!$tid) {
      $vid = db_select('taxonomy_vocabulary', 'v')
        ->fields('v', array('vid'))
        ->condition('v.machine_name', $vocab)
        ->execute()
        ->fetchField();
      $term = (object) array(
        'name' => $name,
        'vid' => $vid,
        'vocabulary_machine_name' => $vocab,
      );
      taxonomy_term_save($term);
      $tid = $term->tid;
    }
    $output[] = array(
      'tid' => $tid,
    );
  }
  return $output;
}
