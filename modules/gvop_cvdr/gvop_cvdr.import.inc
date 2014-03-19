<?php

/**
 * Callback for mapping gvop cvdr nodes.
 *
 * @param DOMElement $record
 * @param $node
 * @param DOMXPath $xpath
 */
function gvop_cvdr_map(DOMElement $record, $node, DOMXPath $xpath) {
  // Date fields.
  $mapping = array(
    './/dcterms:issued' => 'field_reg_issued',
    './/overheidrg:inwerkingtredingDatum' => 'field_date_elaboration',
    './/overheidrg:uitwerkingtredingDatum' => 'field_date_recall',
    './/overheidrg:terugwerkendekrachtDatum' => 'field_date_retroactively',
  );
  $xpath->registerNamespace('dcterms', 'http://purl.org/dc/terms/');
  $xpath->registerNamespace('overheidrg', 'http://standaarden.overheid.nl/cvdr/terms/');
  foreach ($mapping as $query => $field) {
    if (($item = $xpath->query($query)->item(0)) && trim($item->nodeValue) != '') {
      $node->$field = array(
        LANGUAGE_NONE => array(array(
          'value' => $item->nodeValue,
          'format' => NULL,
          'safe_value' => $item->nodeValue
        )),
      );
    }
  }

  // Text fields.
  $mapping = array(
    './/dcterms:subject' => 'field_intro',
    './/dcterms:isRatifiedBy' => 'field_ratified_by',
    './/overheidrg:betreft' => 'field_reg_concerning',
    './/overheidrg:kenmerk' => 'field_reg_characteristic',
    './/overheidrg:onderwerp' => 'field_reg_subject',
  );
  foreach ($mapping as $query => $field) {
    if (($item = $xpath->query($query)->item(0)) && !empty($item->nodeValue)) {
      $node->$field = array(
        LANGUAGE_NONE => array(array('value' => drupal_substr($item->nodeValue, 0, 255))),
      );
    }
  }

  $node->field_red_addition = array(
    LANGUAGE_NONE => array(
      array(
        'value' => $xpath->query('.//overheidrg:redactioneleToevoeging', $record)->item(0)->nodeValue,
        'format' => 'filtered_html',
      )
    )
  );

  if (module_exists('scheduler')) {
    $node->publish_on = FALSE;
    $node->unpublish_on = FALSE;
    $publish_on_str = trim($xpath->query('.//overheidrg:inwerkingtredingDatum', $record)->item(0)->nodeValue);
    if (!empty($publish_on_str)) {
      if ($node->publish_on <= REQUEST_TIME) {
        $node->status = 1;
      }
      else {
        $node->publish_on =  strtotime($publish_on_str);
      }
    }

    $unpublish_on_str = trim($xpath->query('.//overheidrg:uitwerkingtredingDatum', $record)->item(0)->nodeValue);
    if (!empty($unpublish_on_str)) {
      if ($node->unpublish_on <= REQUEST_TIME) {
        $node->status = 0;
      }
      else {
        $node->unpublish_on = strtotime($unpublish_on_str);
      }
    }
  }

  $xpath->registerNamespace('ns1', "http://standaarden.overheid.nl/sru");
  $pubUrl = $xpath->query('.//ns1:publicatieurl_xml', $record)->item(0)->nodeValue;
  $pubUrlHTML = $xpath->query('.//ns1:publicatieurl_xhtml', $record)->item(0)->nodeValue;
  if ($pubUrl) {
    $data = drupal_http_request($pubUrl);
    if ($data->code == 200) {
      $pubXML = $data->data;
      $pubDOM = new DOMDocument;
      $pubDOM->loadXML($pubXML);

      $body_str = _gvop_cvdr_get_text($pubUrlHTML);
      if (empty($body_str)) {
        // If we failed fetching the original HTML, generate our own HTML based on the XML data.
        $regeling = $pubDOM->getElementsByTagName('regeling')->item(0);
        $body_str = _gvop_cvdr_xml_read_text($regeling);
      }

      $node->body = array(
        LANGUAGE_NONE => array(
          array(
            'value' => $body_str,
            'format' => 'filtered_html',
          )
        )
      );
    }
  }
}

function _gvop_cvdr_xml_read_text(DOMElement $element, $level = 1) {
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
          $output .= _gvop_cvdr_xml_read_text($child, $level);
          break;
        case 'deel':
        case 'artikel':
          $output .= _gvop_cvdr_xml_read_text($child, $level + 1);
          break;
        case 'al':
          $text = _gvop_cvdr_xml_read_text($child, $level);
          if (trim(str_replace('&nbsp;', '', $text)) != '') {
            $output .= '<p>';
            $output .= $text;
            $output .= '</p>';
          }
          break;
        case 'vet':
          $output .= '<strong>';
          $output .= _gvop_cvdr_xml_read_text($child, $level);
          $output .= '</strong>';
          break;
        case 'sup':
          $output .= '<span class="sup">';
          $output .= _gvop_cvdr_xml_read_text($child, $level);
          $output .= '</span>';
          break;
        case 'kop':
          $output .= _gvop_cvdr_xml_read_kop($child, 'h' . ($level + 1));
          break;
        case 'tussenkop':
          $output .= _gvop_cvdr_xml_read_kop($child, 'h' . ($level + 2));
          break;
        case 'lijst':
          $output .= _gvop_cvdr_xml_read_lijst($child);
          break;
        case 'lid':
          $output .= _gvop_cvdr_xml_read_lid($child);
          break;
      }
    }
    $output .= PHP_EOL;
  } while ($child = $child->nextSibling);
  return $output;
}

function _gvop_cvdr_xml_read_kop(DOMElement $element, $tag = 'h2') {
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

function _gvop_cvdr_xml_read_lijst(DOMElement $element) {
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
    $text = trim(_gvop_cvdr_xml_read_text($child));
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

function _gvop_cvdr_xml_read_lid(DOMElement $element) {
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
  $text = _gvop_cvdr_xml_read_text($element);
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

function _gvop_cvdr_get_text($url) {
  $data = drupal_http_request($url);
  if ($data->code != 200) {
    return FALSE;
  }

  // Fix XHTML errors before loading document.
  $data->data = preg_replace('/<\\!DOCTYPE[^>]+>/si', '', $data->data);
  $data->data = str_replace('></meta>', '/>', $data->data);

  $dom = new DOMDocument();
  $dom->loadHTML($data->data);
  if (!$text = $dom->getElementById('broodtekst')) {
    // There is no guarantee that this HTML will not change, but KOOP does not
    // provide other ways to get the HTML either (i.e. XSLT). A change is not
    // likely, but if they do so, we need to update this module immediately.
    watchdog('gvop_cvdr', t('No <div id="broodtekst"> found in CVDR HTML. Module needs to be updated. URL: %url'), array(
      '%url' => $url,
    ), WATCHDOG_CRITICAL);
    return FALSE;
  }
  $text = $text->C14N();

  // Strip unnecessary whitespace.
  $text = preg_replace('/[\s]+/', ' ', $text);

  // Strip outer div.
  $text = preg_replace('/^<div[^>]*>(.*)<\\/div>$/s', '\\1', $text);

  // Fix double bullets.
  $text = preg_replace('/<span class\\="ol">[^<]{1,10}<\\/span>/s', '', $text);

  return $text;
}
