<?php

/**
 * Callback for mapping gvop bm nodes.
 *
 * @param DOMElement $record
 * @param $node
 * @param DOMXPath $xpath
 */
function gvop_bm_map(DOMElement $record, $node, DOMXPath $xpath) {
  // Body text
  $text = '';
  $identifier =  $xpath->query('.//dcterms:identifier', $record)->item(0)->nodeValue;
  if (preg_match('/^(http.*)\.html$/', $identifier, $match)) {
    $xml_url = $match[1] . '.xml';
    $text = gvop_bm_get_text($xml_url);
  }
  if (empty($text)) {
    $text = $xpath->query('.//dcterms:description', $record)->item(0)->nodeValue;
  }
  $node->body = array(
    LANGUAGE_NONE => array(
      array(
        'value' => $text,
        'format' => 'filtered_html',
      )
    )
  );

  // Locations
  $node->field_location = array(LANGUAGE_NONE => array());
  $locs = $xpath->query('.//overheidbm:object', $record);
  foreach ($locs as $loc) {
    $number_query = $xpath->query('.//overheidbm:huisnummer', $loc);
    $number = $number_query->item(0) ? $number_query->item(0)->nodeValue : FALSE;

    $postal_code_query =  $xpath->query('.//overheidbm:postcode', $loc);
    $postal_code = $postal_code_query->item(0) ? $postal_code_query->item(0)->nodeValue : FALSE;

    $coordinates_x_query =  $xpath->query('.//overheidbm:x-waarde', $loc);
    $coordinates_x = $coordinates_x_query->item(0) ? $coordinates_x_query->item(0)->nodeValue : FALSE;

    $coordinates_y_query =  $xpath->query('.//overheidbm:y-waarde', $loc);
    $coordinates_y = $coordinates_x_query->item(0) ? $coordinates_y_query->item(0)->nodeValue : FALSE;

    if (!empty($postal_code) && !empty($number)) {
      $geo_postal = _gvop_bm_geo_request($postal_code . ', Nederland');

      if (isset($geo_postal->results[0]) && isset($geo_postal->results[0]->geometry)) {
        $postal_loc = $geo_postal->results[0]->geometry->location;

        $node->field_location[LANGUAGE_NONE][] = array(
          'postal_code' => $postal_code,
          'additional' => $number,
          'country' => 'nl',
          'latitude' => (string)$postal_loc->lat,
          'longitude' => (string)$postal_loc->lng,
          'locpick' => array(
            'user_latitude' => (string)$postal_loc->lat,
            'user_longitude' => (string)$postal_loc->lng,
          ),
          'source' => 1,
        );
      }
    }
    else if (!empty($postal_code)) {
      $geo_postal = _gvop_bm_geo_request($postal_code . ', Nederland');

      if (isset($geo_postal->results[0]) && isset($geo_postal->results[0]->geometry)) {
        $postal_loc = $geo_postal->results[0]->geometry->location;

        $node->field_location[LANGUAGE_NONE][] = array(
          'postal_code' => $postal_code,
          'country' => 'nl',
          'latitude' => (string)$postal_loc->lat,
          'longitude' => (string)$postal_loc->lng,
          'locpick' => array(
            'user_latitude' => (string)$postal_loc->lat,
            'user_longitude' => (string)$postal_loc->lng,
          ),
          'source' => 1,
        );
      }
    }
    elseif (!empty($coordinates_x) && !empty($coordinates_y)) {
      $coordinates = gvop_bm_rd2wgs($coordinates_x, $coordinates_y);
      $node->field_location[LANGUAGE_NONE][] = array(
        'country' => 'nl',
        'latitude' => (string) $coordinates['latitude'],
        'longitude' => (string) $coordinates['longitude'],
        'locpick' => array(
          'user_latitude' => (string) $coordinates['latitude'],
          'user_longitude' => (string) $coordinates['longitude'],
        ),
        'source' => 1,
      );
    }
    else {
      $municipality = trim($xpath->query('.//dcterms:spatial', $record)->item(0)->nodeValue);
      if (!empty($municipality)) {
        $geo_muni = _gvop_bm_geo_request('Gemeente ' . $municipality . ', Nederland');

        if (isset($geo_muni->results[0]) && isset($geo_muni->results[0]->geometry)) {
          $muni_loc = $geo_muni->results[0]->geometry->location;

          $node->field_location[LANGUAGE_NONE][] = array(
            'country' => 'nl',
            'latitude' => (string)$muni_loc->lat,
            'longitude' => (string)$muni_loc->lng,
            'locpick' => array(
              'user_latitude' => (string)$muni_loc->lat,
              'user_longitude' => (string)$muni_loc->lng,
            ),
            'source' => 1,
          );
        }
      }
    }
  }

  // Type bekendmaking.
  $type = $xpath->query('.//overheidbm:producttype', $record)->item(0)->nodeValue;
  $term = bespoke_get_term_id($type, 'announcement_type');
  $node->field_announcement_type = array(
    LANGUAGE_NONE => array(array('tid' => $term->tid))
  );

  // Datum
  $date = $xpath->query('.//dcterms:temporal/*', $record)->item(0)->nodeValue;
  $node->field_date = array(
    LANGUAGE_NONE => array(array('value' => $date))
  );
}

function _gvop_bm_geo_request($address) {
  $cid = 'gvop_bm:geo:' . md5($address);
  if ($cache = cache_get($cid)) {
    return $cache->data;
  }

  $query = array(
    'region' => 'nl',
    'sensor' => 'false',
    'address' => $address,
  );
  $uri = 'http://maps.googleapis.com/maps/api/geocode/json';
  $uri = $uri . '?' . drupal_http_build_query($query);
  $request = drupal_http_request($uri);
  $output = json_decode($request->data);

  cache_set($cid, $output, 'cache', REQUEST_TIME + 604800);
  return $output;
}

/**
 * Convert RD to GPS
 *
 * Function copied from:
 * http://www.god-object.com/2009/10/23/convert-rijksdriehoekscordinaten-to-latitudelongitude/
 */
function gvop_bm_rd2wgs($x, $y) {
  // Calculate WGS84 coördinates
  $dX = ($x - 155000) * pow(10, - 5);
  $dY = ($y - 463000) * pow(10, - 5);
  $SomN = (3235.65389 * $dY) + (- 32.58297 * pow($dX, 2)) + (- 0.2475 *
      pow($dY, 2)) + (- 0.84978 * pow($dX, 2) *
      $dY) + (- 0.0655 * pow($dY, 3)) + (- 0.01709 *
      pow($dX, 2) * pow($dY, 2)) + (- 0.00738 *
      $dX) + (0.0053 * pow($dX, 4)) + (- 0.00039 *
      pow($dX, 2) * pow($dY, 3)) + (0.00033 * pow(
        $dX, 4) * $dY) + (- 0.00012 *
      $dX * $dY);
  $SomE = (5260.52916 * $dX) + (105.94684 * $dX * $dY) + (2.45656 *
      $dX * pow($dY, 2)) + (- 0.81885 * pow(
        $dX, 3)) + (0.05594 *
      $dX * pow($dY, 3)) + (- 0.05607 * pow(
        $dX, 3) * $dY) + (0.01199 *
      $dY) + (- 0.00256 * pow($dX, 3) * pow(
        $dY, 2)) + (0.00128 *
      $dX * pow($dY, 4)) + (0.00022 * pow($dY,
        2)) + (- 0.00022 * pow(
        $dX, 2)) + (0.00026 *
      pow($dX, 5));

  $Latitude = 52.15517 + ($SomN / 3600);
  $Longitude = 5.387206 + ($SomE / 3600);

  return array(
    'latitude' => $Latitude ,
    'longitude' => $Longitude);
}

function gvop_bm_get_text($xml_url) {
  $data = drupal_http_request($xml_url);
  if ($data->code == 200) {
    $pubXML = $data->data;
    $pubDOM = new DOMDocument;
    $pubDOM->loadXML($pubXML);

    $tags = array(
      'regeling',
      'zakelijke-mededeling',
    );
    foreach ($tags as $tag) {
      $element = $pubDOM->getElementsByTagName($tag)->item(0);
      if (is_object($element) && $element instanceof DOMElement) {
        break;
      }
    }
    if (is_object($element) && $element instanceof DOMElement) {
      $body_str = _gvop_bm_xml_read_text($element);
      return $body_str;
    }
    else {
      if (function_exists('drush_log')) {
        drush_log("No known tag found in $xml_url");
      }
    }
  }
}

function _gvop_bm_xml_read_text(DOMElement $element, $level = 1) {
  $output = '';
  if (!$element->hasChildNodes()) {
    return $output;
  }
  $child = $element->firstChild;
  do {
    if ($child instanceof DOMText) {
      $output .= htmlentities($child->nodeValue, ENT_COMPAT, 'UTF-8');
    }
    if ($child instanceof DOMElement) {
      switch ($child->tagName) {
        case 'intitule':
        case 'aanhef':
        case 'preambule':
        case 'regeling-tekst':
        case 'regeling-sluiting':
        case 'hoofdstuk':
        case 'structuurtekst':
        case 'slotformulering':
        case 'nota-toelichting':
        case 'considerans':
        case 'tekst':
          $output .= _gvop_bm_xml_read_text($child, $level);
          break;
        case 'deel':
        case 'artikel':
          $output .= _gvop_bm_xml_read_text($child, $level + 1);
          break;
        case 'al':
          $text = _gvop_bm_xml_read_text($child, $level);
          if (trim(str_replace('&nbsp;', '', $text)) != '') {
            $output .= '<p>';
            $output .= $text;
            $output .= '</p>';
          }
          break;
        case 'vet':
        case 'nadruk':
          $output .= '<strong>';
          $output .= _gvop_bm_xml_read_text($child, $level);
          $output .= '</strong>';
          break;
        case 'sup':
          $output .= '<span class="sup">';
          $output .= _gvop_bm_xml_read_text($child, $level);
          $output .= '</span>';
          break;
        case 'kop':
          $output .= _gvop_bm_xml_read_kop($child, 'h' . ($level + 1));
          break;
        case 'tussenkop':
          $output .= _gvop_bm_xml_read_kop($child, 'h' . ($level + 2));
          break;
        case 'lijst':
          $output .= _gvop_bm_xml_read_lijst($child);
          break;
        case 'lid':
          $output .= _gvop_bm_xml_read_lid($child);
          break;
      }
    }
    $output .= PHP_EOL;
  } while ($child = $child->nextSibling);
  return $output;
}

function _gvop_bm_xml_read_kop(DOMElement $element, $tag = 'h2') {
  $output = '';
  if (!$element->hasChildNodes()) {
    return $output;
  }
  $child = $element->firstChild;
  do {
    if (!$child instanceof DOMElement) {
      continue;
    }
    ${$child->tagName} = trim(htmlentities($child->nodeValue, ENT_COMPAT, 'UTF-8'));
  } while ($child = $child->nextSibling);

  // Tag, Label, Nr, Titel are dynamically set so this might give errors in
  // your IDE.
  $output .= '<' . $tag . '>';
  $output .= empty($label) ? '' : "$label ";
  $output .= empty($nr) ? '' : "$nr ";
  $output .= $titel;
  $output .= '</' . $tag . '>';

  return $output;
}

function _gvop_bm_xml_read_lijst(DOMElement $element) {
  $output = '';
  if (!$element->hasChildNodes()) {
    return $output;
  }
  $output .= '<ul class="whitespace-small">';
  $child = $element->firstChild;
  do {
    if (!$child instanceof DOMElement) {
      continue;
    }
    $output .= '<li>';
    $nr = $child->getAttribute('nr');
    $text = trim(_gvop_bm_xml_read_text($child));
    if (!empty($nr)) {
      $nr = $nr == '-' ? '·' : $nr;
      $nr = '<span class="ol">' . htmlentities($nr, ENT_COMPAT, 'UTF-8') . ' </span>';
      if (preg_match('/^\\<p\\>/s', $text)) {
        $text = preg_replace('/^\\<p\\>/s', '<p>' . $nr, $text);
      }
      else {
        $text = $nr . $text;
      }
      if (preg_match('/^\\<p\\>(.*)\\<\\/p\\>$/si', $text, $match)) {
        $text = $match[1];
      }
    }
    $output .= $text;
    $output .= '</li>';
  } while ($child = $child->nextSibling);
  $output .= '</ul>';
  return $output;
}

function _gvop_bm_xml_read_lid(DOMElement $element) {
  $output = '';
  if (!$element->hasChildNodes()) {
    return $output;
  }
  $child = $element->firstChild;
  do {
    if (!$child instanceof DOMElement) {
      continue;
    }
    if ($child->tagName == 'lidnr') {
      $lidnr = $child->nodeValue;
    }
  } while ($child = $child->nextSibling);
  $text = _gvop_bm_xml_read_text($element);
  if (!empty($lidnr)) {
    $lidnr = htmlentities($lidnr, ENT_COMPAT, 'UTF-8');
    $lidnr = '<span class="lidnr">' . $lidnr . ' </span>';
    if (preg_match('/^\\<p\\>/s', $text)) {
      $text = preg_replace('/^\\<p\\>/s', '<p>' . $lidnr, $text);
    }
    else {
      $text = $lidnr . $text;
    }
  }
  $output .= $text;
  return $output;
}
