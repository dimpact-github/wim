<?php

/**
 * Callback for mapping gvop bm nodes.
 *
 * @param DOMElement $record
 * @param $node
 * @param DOMXPath $xpath
 */
function gvop_bm_map(DOMElement $record, $node, DOMXPath $xpath) {
  // Body tekst.
  $node->body = array(
    LANGUAGE_NONE => array(
      array(
        'value' => $xpath->query('.//dcterms:description', $record)->item(0)->nodeValue,
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
    else {
      $municipality = $xpath->query('.//dcterms:spatial', $record)->item(0)->nodeValue;

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
  // @todo, add caching for requests.
  $query = array(
    'region' => 'nl',
    'sensor' => 'false',
    'address' => $address,
  );
  $uri = 'http://maps.googleapis.com/maps/api/geocode/json';
  $uri = $uri . '?' . drupal_http_build_query($query);
  $request = drupal_http_request($uri);
  return json_decode($request->data);
}