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
function sduconnect_set_pdc_content($xpath, &$node, $private = FALSE, $references) {
  $xpath->registerNameSpace('m', 'http://www.sduconnect.nl/Productoverzicht');
  $xpath->registerNameSpace('dcterms', 'http://purl.org/dc/terms/');
  $xpath->registerNameSpace('overheid', 'http://standaarden.overheid.nl/owms/terms/');
  $xpath->registerNameSpace('overheidproduct', 'http://standaarden.overheid.nl/product/terms/');
  $xpath->registerNameSpace('overheidsc', 'http://standaarden.overheid.nl/sc/terms/');

  $node->type = 'product';
  $node->title = (string) $xpath->query('//m:page/m:product/m:name')->item(0)->nodeValue;

  $tabs = array();

  // Beschrijving.
  $tabs['Beschrijving'] = '';
  // Let op.
  $field = $xpath->query('//m:page/m:product/m:notice');
  if ($field->length) {
    $value = $field->item(0)->nodeValue;
    if (preg_match('/[a-z]/si', strip_tags($value))) {
      $tabs['Beschrijving'] .= '<strong>Let op:</strong> ' . $field->item(0)->nodeValue;
    }
  }
  $field = $xpath->query('//m:page/m:product/m:description');
  if ($field->length) {
    $tabs['Beschrijving'] .= $field->item(0)->nodeValue;
  }
  $related_pdc = array();
  $related_vac = array();
  foreach ($references as $related) {
    ${'related_' . $related->type}[] = array(
      'href' => 'node/' . $related->nid,
      'title' => $related->title,
    );
  }
  if ($related_pdc) {
    $tabs['Beschrijving'] .= '<h3>Gerelateerde producten</h3>' . theme('links', array('links' => $related_pdc));
  }
  if ($related_vac) {
    $tabs['Beschrijving'] .= '<h3>Vraag en antwoord</h3>' . theme('links', array('links' => $related_vac));
  }
  // Meer informatie.
  $names = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:product_links/m:product_link/m:product_link_name'));
  $urls = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:product_links/m:product_link/m:product_link_url'));
  $items = array();
  foreach ($names as $i => $name) {
    $items[] = array(
      'href' => $urls[$i],
      'title' => $name,
    );
  }
  if ($items) {
    $tabs['Beschrijving'] .= '<h3>Meer informatie</h3>' . theme('links', array('links' => $items));
  }
  // Related laws.
  $names = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:law_rules/m:law_rule/m:law_rule_name'));
  $urls = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:law_rules/m:law_rule/m:url'));
  $items = array();
  foreach ($names as $i => $name) {
    $items[] = array(
      'href' => $urls[$i],
      'title' => $name,
    );
  }
  if ($items) {
    $tabs['Beschrijving'] .= '<h3>Gerelateerde wetten / regelgeving</h3>' . theme('links', array('links' => $items));
  }

  // Voorwaarden.
  $tabs['Voorwaarden'] = '';
  $field = $xpath->query('//m:page/m:product/m:conditions');
  if ($field->length) {
    $tabs['Voorwaarden'] .= $field->item(0)->nodeValue;
  }

  // Aanpak.
  $tabs['Aanpak'] = '';
  $field = $xpath->query('//m:page/m:product/m:procedure');
  if ($field->length) {
    $tabs['Aanpak'] .= $field->item(0)->nodeValue;
  }
  // Forms.
  $names = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:formulieren_extern/m:formulier/m:label'));
  $urls = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:formulieren_extern/m:formulier/m:href'));
  $items = array();
  foreach ($names as $i => $name) {
    $items[] = array(
      'href' => $urls[$i],
      'title' => $name,
    );
  }
  if ($items) {
    $tabs['Aanpak'] .= '<h3>Formulieren</h3>' . theme('links', array('links' => $items));
  }
  // Request online.
  $url = sduconnect_nodelist_to_string($xpath->query('//m:page/m:product/overheidproduct:scproduct/overheidproduct:meta/overheidproduct:scmeta/overheidproduct:aanvraagURL/@resourceIdentifier'));
  $items = array();
  if ($url) {
    $items[] = array(
      'href' => $url,
      'title' => 'Online aanvragen',
    );
  }
  if ($items) {
    $tabs['Aanpak'] .= '<h3>Online aanvragen</h3>' . theme('links', array('links' => $items));
  }

  // Termijn.
  $tabs['Termijn'] = '';
  $field = $xpath->query('//m:page/m:product/m:period');
  if ($field->length) {
    $tabs['Termijn'] .= $field->item(0)->nodeValue;
  }

  // Bezwaar en beroep.
  $tabs['Bezwaar en beroep'] = '';
  $field = $xpath->query('//m:page/m:product/m:appeal');
  if ($field->length) {
    $tabs['Bezwaar en beroep'] .= $field->item(0)->nodeValue;
  }

  // Kosten
  $tabs['Kosten'] = '';
  $field = $xpath->query('//m:page/m:product/m:costs');
  if ($field->length) {
    $tabs['Kosten'] .= $field->item(0)->nodeValue;
  }

  // Contact
  $tabs['Contact'] = '';
  $field = $xpath->query('//m:page/m:product/m:contact');
  if ($field->length) {
    $tabs['Contact'] .= $field->item(0)->nodeValue;
  }
  // Location.
  $locations = array();
  $name = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:uitvoerende_instanties/m:instantie/m:naam'));
  $street = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:uitvoerende_instanties/m:instantie/m:p_straat'));
  $number = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:uitvoerende_instanties/m:instantie/m:p_nummer'));
  $postal_code = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:uitvoerende_instanties/m:instantie/m:p_postcode'));
  $po_box = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:uitvoerende_instanties/m:instantie/m:p_po_box'));
  $city = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:uitvoerende_instanties/m:instantie/m:p_woonplaats'));
  for ($i = 0; $i < count($name); ++$i) {
    $location = array();
    if ($name[$i]) {
      $location[] = $name[$i];
    }
    $location[] = $street[$i] ? trim($street[$i] . ' ' . $number[$i]) : ($po_box[$i] ? 'Postbus ' . $po_box[$i] : '');
    $location[] = $postal_code[$i] . ' ' . $city[$i];
    $locations[] = '<p>' . implode('<br/>', array_map('check_plain', $location)) . '</p>';
  }
  if ($locations) {
    $tabs['Contact'] .= '<h3>Locatie</h3>' . implode($locations);
  }

  // Indien periode
  $tabs['Indien periode'] = '';
  $field = $xpath->query('//m:page/m:product/m:subsidies');
  if ($field->length) {
    $tabs['Indien periode'] .= $field->item(0)->nodeValue;
  }

  // Beschikbaar budget
  $tabs['Beschikbaar budget'] = '';
  $field = $xpath->query('//m:page/m:product/m:subsidies_budget');
  if ($field->length) {
    $tabs['Beschikbaar budget'] .= $field->item(0)->nodeValue;
  }

  // Maximale bijdrage
  $tabs['Maximale bijdrage'] = '';
  $field = $xpath->query('//m:page/m:product/m:subsidies_maximale_bijdrage');
  if ($field->length) {
    $tabs['Maximale bijdrage'] .= $field->item(0)->nodeValue;
  }

  // Tags.
  $a = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:doelgroepen/m:doelgroep'));
  $b = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:themes/m:theme/m:main/m:name'));
  $c = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:themes/m:theme/m:subthemes/m:subtheme/m:name'));
  $d = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/m:vind_themes/m:vind_theme/m:name'));
  $e = sduconnect_nodelist_to_array($xpath->query('//m:page/m:product/overheidproduct:scproduct/overheidproduct:meta/overheidproduct:owmsmantel/dcterms:subject'));
  $tags = array_unique(array_merge($a, $b, $c, $d, $e));
  $items = sduconnect_tags($tags);
  $node->field_tags = array(LANGUAGE_NONE => $items);

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

  // Merge tab content in body.
  $body = '';
  foreach ($tabs as $title => $content) {
    if (preg_match('/[a-z0-9]/si', strip_tags($content))) {
      $body .= '<h2>**' . check_plain($title) . '</h2>' . $content;
    }
  }
  $node->body = array(LANGUAGE_NONE => array(array(
    'value' => $body,
    'format' => 'filtered_html',
  )));
}

/**
 * Set PDC references.
 *
 * @param object $node
 * @param array $references
 */
function sduconnect_set_pdc_references(&$node, $references) {
  $node->field_related_pdc = array(LANGUAGE_NONE => array());
  $node->field_related_vac = array(LANGUAGE_NONE => array());
  foreach ($references as $reference) {
    if ($reference->type == 'pdc') {
      $node->field_related_pdc[LANGUAGE_NONE][] = array('value' => $reference->nid);
    }
    if ($reference->type == 'vac') {
      $node->field_related_vac[LANGUAGE_NONE][] = array('value' => $reference->nid);
    }
  }
}

/**
 * Populate node object with VAC content.
 *
 * @param DOMXPath $xpath
 * @param object $node
 * @param boolean $private Import private fields.
 */
function sduconnect_set_vac_content($xpath, &$node, $private = FALSE, $references) {
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

/**
 * Extract references from VAC.
 *
 * @param DOMXPath $xpath
 */
function sduconnect_get_vac_references($xpath) {
  return array();
}


/**
 * Extract references from PDC.
 *
 * @param DOMXPath $xpath
 */
function sduconnect_get_pdc_references($xpath) {
  $xpath->registerNameSpace('m', 'http://www.sduconnect.nl/Productoverzicht');

  $output = array();
  $items = sduconnect_nodelist_to_array($xpath->query('//m:vac_relatie/@base_id'));
  foreach ($items as $item) {
    $output[] = (object) array(
      'type' => 'vac',
      'id' => $item,
    );
  }
  $items = sduconnect_nodelist_to_array($xpath->query('//m:product_relatie/@base_id'));
  foreach ($items as $item) {
    $output[] = (object) array(
      'type' => 'pdc',
      'id' => $item,
    );
  }
  return $output;
}
