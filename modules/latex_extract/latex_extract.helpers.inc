<?php

/**
 * @file
 * Collection of helper functions for the dop_doc module.
 */

/**
 * Return Ja or Nee based on $input.
 * @param boolean $input
 */
function janee($input) {
  if ($input == TRUE) {
    return 'Ja';
  }
  else {
    return 'Nee';
  }
}

/**
 * Format a latex table.
 *
 * Returns latex for a table based on the $data. The output depends on the
 * $type parameter:
 *
 * tabularx:
 *   - first column is fixed 5 cm width
 *   - last column gets the rest of page width
 *   - other columns auto width.
 *   - First row (header) will be generated bold.
 *   - all cells have borders.
 *
 * longtable:
 *   - entire table is aprox 15 cm wide.
 *   - column widhts will be distributed equally, an optional weight key can be
 *     supplied in the data array to control this behaviour (this only working
 *     for longtable is actually for legacy reasons, if you feel up to it, maybe
 *     it can be implemented for tabularx too).
 *   - first row (header) will be generated bold and have a background color.
 *   - all cells have borders.

 * @param array $data
 * @example
 *   $data = array(
 *     'header' => array('column1', 'column2', 'column3'),
 *     'weight' => array(2, 1, 1), // Only works for longtable
 *     'rows' => array(
 *       array('row 1 col 1', 'row 1 col 2', 'row 1 col 3'),
 *       array('row 2 col 1', 'row 2 col 2', 'row 2 col 3'),
 *     )
 *   );
 */
function latex_table($data, $type = 'tabularx') {
  switch ($type) {
    case 'tabularx':
      return latex_table_tabularx($data);
    case 'longtable':
      return latex_table_longtable($data);
  }
}

function latex_table_tabularx($data) {

  $number_of_columns = count($data['header']);

  // Last column is a p column.
  $rows_spacing_orig = '| p{5cm} ';
  for ($i=1; $i<$number_of_columns; $i++) {
    $rows_spacing_orig .= '| l ';
  }
  $rows_spacing = substr_replace($rows_spacing_orig, 'X', -2, -1);
  $rows_spacing .= '|';

  // Define table.
  $output = '  \begin{tabularx}{\linewidth}{' . $rows_spacing . '}'.N;
  $output .= '  \rowcolor{tableheader}'.N;
  $output .= '  \hline'.N;
  // Header formatted bold.
  foreach($data['header'] as $header_item) {
    $header[] = '\textbf{' . $header_item . '}';
  }
  $output .= '  '.implode(' & ', $header);
  $output .= '  \\\\'.N;
  $output .= '  \hline'.N;

  foreach($data['rows'] as $row) {
    $output .= '  ' . implode(' & ', $row);
    $output .= "  \\\\".N;
    $output .= '  \hline'.N;
  }

  $output .= '  \end{tabularx}'.N.N;


  return $output;
}

function latex_table_longtable($data) {

  $number_of_columns = count($data['header']);

  $weight = $number_of_columns;

  if (isset($data['weight'])) {
    $weight = array_sum($data['weight']);
  }
  else {
    $data['weight'] = array_fill(0, $number_of_columns, 1);
  }

  // Last column is a p column.
  $rows_spacing = '| ';

  foreach ($data['header'] as $key => $value) {
    $width = ($data['weight'][$key] * CONTENTWIDTH) / $weight;
    $rows_spacing .= sprintf("p{%.2fcm}|", $width);
  }

  // Define table.
  $output = '  \begin{longtable}{' . $rows_spacing . '}'.N;
  $output .= '  \hline'.N;
  // Header formatted bold.
  $output .= '  \rowcolor{tableheader}'.N;
  foreach($data['header'] as $header_item) {
    $header[] = '\textbf{' . $header_item . '}';
  }
  $headerline = '  ' . implode(' & ', $header);
  $headerline .= '  \tabularnewline' . N;
  $headerline .= '  \hline' . N;

  $output .= $headerline;

  $output .= '\endfirsthead' . N;
  $output .= '\multicolumn{' . $number_of_columns . '}{l}{\textit{Vervolg van vorige pagina}} \\\\' . N;
  $output .= '\hline' . N;
  $output .= '\rowcolor{tableheader}' . N;
  $output .= $headerline;
  $output .= '\hline' . N;
  $output .= '\endhead' . N;
  $output .= '\multicolumn{' . $number_of_columns . '}{r}{\textit{Gaat verder op volgende pagina}} \\\\' . N;
  $output .= '\endfoot' . N;
  $output .= '\hline' . N;
  $output .= '\endlastfoot' . N;

  foreach($data['rows'] as $row) {
    $output .= '  ' . implode(' & ', $row);
    $output .= '  \tabularnewline' . N;
    $output .= '  \hline' . N;
  }

  $output .= '  \end{longtable}' . N . N;


  return $output;
}

/**
 * Return a latex safe string.
 *
 * @param string $string
 * @param boolean $strip_tags
 *   Should strip_tags() called, default TRUE.
 *
 * @return string Latex safe string.
 */
function latex_safe($string, $strip_tags=TRUE) {
    $map = array(
      "\\" => "\\textbackslash",
      "#" => "\\#",
      "$" => "\\$",
      "%" => "\\%",
      "&" => "\\&",
      "~" => "\\~{}",
      "_" => "\\_",
      "^" => "\\^{}",
      "{" => "\\{",
      "}" => "\\}",
      "é" => "\\'{e}",
      "ë" => "\\\"{e}",
    );
    if ($strip_tags) {
      $string = strip_tags($string);
    }
    return latex_mb_replace(array_keys($map), array_values($map), $string);
}

/**
 * Friendly name for field widget types.
 * @param unknown $type
 */
function latex_widget_type($type) {
  $types = array(
    'text_textarea_with_summary' => 'WYSIWYG (met samenvatting)',
    'text_textarea' => 'WYSIWYG',
    'text' => 'Tekst',
    'text_textfield' => 'Tekst',
    'link_field' => 'Link',
    'media_generic' => 'Bestand',
    'options_select' => 'Taxonomie (dropdown)',
    'options_onoff' => 'Aan/uit-vinkje',
    'options_buttons' => 'Radio-knoppen/vinkjes',
    'relation_add' => 'Relatie',
    'taxonomy_autocomplete' => 'Taxonomie (autocomplete)',
    'taxonomy_hs' => 'Taxonomie (hierarchische dropdown)',
    'date_popup' => 'Datum',
  );

  if (isset($types[$type])) {
    return $types[$type];
  }
  else {
    return $type;
  }
}

/**
 * Implementation of str_replace for multibyte
 */
function latex_mb_replace($search, $replace, $subject, &$count=0) {
  if (!is_array($search) && is_array($replace)) {
    return false;
  }
  if (is_array($subject)) {
    // call mb_replace for each single string in $subject
    foreach ($subject as &$string) {
      $string = &latex_mb_replace($search, $replace, $string, $c);
      $count += $c;
    }
  } elseif (is_array($search)) {
    if (!is_array($replace)) {
      foreach ($search as &$string) {
        $subject = latex_mb_replace($string, $replace, $subject, $c);
        $count += $c;
      }
    } else {
      $n = max(count($search), count($replace));
      while ($n--) {
        $subject = latex_mb_replace(current($search), current($replace), $subject, $c);
        $count += $c;
        next($search);
        next($replace);
      }
    }
  } else {
    $parts = mb_split(preg_quote($search), $subject);
    $count = count($parts)-1;
    $subject = implode($replace, $parts);
  }
  return $subject;
}