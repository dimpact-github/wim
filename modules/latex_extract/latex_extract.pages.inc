<?php
/**
 * @file
 * Page callbacks for latex_extract module.
 */
/**
 * Form for the content types page
 */
function latex_extract_report_contenttypes_form($form, &$form_state) {
  $doctype = isset($form_state['values']['doctype'])?$form_state['values']['doctype']:'to';
  $tabletype = isset($form_state['values']['tables'])?$form_state['values']['tables']:'longtable';

  $form = array(
    'doctype' => array(
      '#type' => 'radios',
      '#title' => t('Type'),
      '#options' => array(
        'to' => 'Technisch Ontwerp',
        'fo' => 'Functioneel Ontwerp',
      ),
      '#default_value' => 'to',
    ),
    'tables' => array(
      '#type' => 'radios',
      '#title' => t('Tables'),
      '#options' => array(
        'tabularx' => 'TabularX',
        'longtable' => 'Long table',
      ),
      '#description' => t('The type of tables to generate. TabularX will alter the width of columns automatically, longtable can run across multiple pages.'),
      '#default_value' => 'longtable',
    ),
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Export'),
    ),
    'source' => array(
      '#type' => 'textarea',
      '#title' => t('Export'),
      '#value' => latex_extract_report_contenttypes($doctype, $tabletype),
      '#rows' => '200',
    ),
  );

  return $form;
}

function latex_extract_report_contenttypes_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
}

/**
 * Generate the LaTeX for Contenttypes.
 *
 * @return string Latex formated output for part contenttypes.
 */
function latex_extract_report_contenttypes($doctype = 'to', $tabletype = 'tabularx') {
  switch ($doctype) {
    case 'to':
      return latex_extract_report_contenttypes_to($tabletype);
    case 'fo':
      return latex_extract_report_contenttypes_fo($tabletype);
    default:
      return '';
  }
}

function latex_extract_report_contenttypes_to($tabletype = 'tabularx') {
  //module_load_include('module', 'node');
  $entity_info = entity_get_info('node');
  $view_modes = $entity_info['view modes'];

  $types = node_type_get_types();
  $names = node_type_get_names();
  $field_ui = module_exists('field_ui');
  $rows = array();

  $output = '';
  foreach ($names as $key => $name) {
    $type = $types[$key];
    $node_type = node_type_load($key);

    // Format LaTex style
    $node_options = variable_get('node_options_' . $key);
    $published = in_array('status', $node_options);
    $sticky    = in_array('sticky', $node_options);
    $promoted  = in_array('promote', $node_options);
    $revision  = in_array('revision', $node_options);

    $comment = variable_get('comment_' . $key); // 0 = hidden, 1= closed, 2 = open
    $comment_text = array(
      0 => 'Hidden',
      1 => 'Closed',
      2 => 'Open',
    );
    $output .= '\subsection{' . latex_safe($name) . '}' . N . '\label{sec:content-'.strtolower(latex_safe($name)).'}' . N;

    if (!empty($type->decription)) {
      $output .= N . latex_safe($type->description) . N.N;
    }

    $data = array(
      'header' => array('Name', 'Value'),
      'rows' => array(
        array('Naam', latex_safe($name)),
        array('Systeemnaam', latex_safe($type->type)),
        array('Beschrijving', latex_safe($type->description)),
        array('Titel gebruiken', janee($type->has_title)),
        array('Published', janee($published)),
        array('Promoted', janee($promoted)),
        array('Sticky', janee($sticky)),
        array('Create new revision', janee($revision)),
        array('Comments', $comment_text[$comment]),
      ),
    );
    $output .= latex_table($data, $tabletype);
    /**
     * Per content type
     * Fields
     * - Per field
     * -- systemname
     * -- descriptionname
     * -- nice value.
     */

    // Fields.
    $output .= '\subsubsection{' . latex_safe($name) . ' fields}'.N;
    $fields = field_info_instances('node', $type->type);

    if (!empty($fields)) {
      $rows = array();
        foreach($fields as $field_key => $field) {
          $rows[] = array(
            latex_safe($field_key),
            latex_safe($field['widget']['module']),
            latex_safe($field['description']),
          );
        }

        $data = array(
          'header' => array('Veld', 'Type', 'Omschrijving'),
          'rows' => $rows,
        );

        $output .= latex_table($data, $tabletype);
    }
    else {
      $output .= 'Geen veldinformatie om weer te geven.';
    }

    // List the View modes of a content type.
    $view_mode_settings = field_view_mode_settings('node', $type->type);
    $output .= '\subsubsection{' . latex_safe($name) . ' view modes}'.N;
    $rows = array();
    if (!empty($view_mode_settings)) {
      $custom_view_modes = array();
      foreach ($view_mode_settings as $view_mode => $value) {

        $rows[] = array(
          latex_safe($view_modes[$view_mode]['label']),
          latex_safe($view_mode),
          janee($value['custom_settings'])
        );

        // Safe custom view modes to generate an overview of their settings.
        if ($value['custom_settings']) {
          $custom_view_modes[] = $view_mode;
        }
      }
      $data = array(
        'header' => array('Label', 'Name', 'Custom settings'),
        'rows' => $rows,
      );
      $output .= latex_table($data, $tabletype);

      // @todo Settings for per viewmode that have custom settings.
      foreach ($custom_view_modes as $custom_view_mode) {
        $instances = field_info_instances('node', $type->type);

        $data = array();
        $rows = array();
        foreach ($instances as $instance_name => $instance) {
          $field = field_info_field($instance['field_name']);
          $display = $instance['display'][$custom_view_mode];
         // var_dump($display);
          $settings = implode(', ',  $display['settings']);
          $settings = ($settings == '') ? ' ' : $settings;
          $weight = ($display['weight']) ? $display['weight'] : ' ';
          $rows[] = array(
            latex_safe($instance['field_name']),
            latex_safe($display['label']),
            latex_safe($display['type']),
            latex_safe($weight  ),
            latex_safe($settings),
          );
        }

        $output .= '\paragraph{' . latex_safe($view_modes[$custom_view_mode]['label']) .' view mode instellingen voor contenttype ' . latex_safe($name) .' }'.N;

        if (!empty($rows)) {
          $data = array(
            'header' => array('Fieldname', 'Label', 'Type', 'Weight', 'Settings'),
            'rows' => $rows,
          );
          $output .= ''.N;
          $output .= latex_table($data, $tabletype);
        }
        else {
          $ouput .= 'Geen veldinstellingen om weer te geven.'.N;
        }
      }

    }
    else {
      $output .= 'Geen informatie over view modes beschikbaar.'.N;
    }

  }

  // The end!
 return $output;

}

function latex_extract_report_contenttypes_fo($tabletype) {
  //module_load_include('module', 'node');
  $entity_info = entity_get_info('node');
  $view_modes = $entity_info['view modes'];

  $types = node_type_get_types();
  $names = node_type_get_names();
  $field_ui = module_exists('field_ui');
  $rows = array();

  $output = '';
  foreach ($names as $key => $name) {
    $type = $types[$key];
    $node_type = node_type_load($key);

    // Format LaTex style
    $node_options = variable_get('node_options_' . $key);

    $output .= '\subsection{' . latex_safe($name) . '}' . N . '\label{sec:content-'.latex_safe(strtolower($name)).'}' . N;

    if (!empty($type->description)) {
      $output .= latex_safe($type->description) . N.N;
    }

    $comment = variable_get('comment_' . $key, 0); // 0 = hidden, 1= closed, 2 = open
    $comment_text = array(
        0 => 'Reacties zijn bij items van dit content type standaard uitgeschakeld (dit is per item aan te passen).',
        1 => 'Reacties zijn bij items van dit content type standaard uitgeschakeld, maar wel zichtbaar (dit is per item aan te passen).',
        2 => 'Reacties zijn bij items van dit content type standaard ingeschakeld (dit is per item aan te passen).',
    );

    $output .= latex_safe($comment_text[$comment]) . N . N;

    /**
     * Per content type
     * Fields
     * - Per field
     * -- systemname
     * -- descriptionname
     * -- nice value.
     */

    // Fields.
    $output .= '\subsubsection{Velden}'.N;
    $fields = field_info_instances('node', $type->type);
    $weights = array();

    foreach ($fields as $field) {
      $weights[] = $field['widget']['weight'];
    }

    array_multisort($weights, $fields);

    $rows = array();

    if ($type->has_title) {
      $rows[] = array(
        '\raggedright{' . latex_safe($type->title_label) . '}',
        '\raggedright{' . latex_safe('Tekst') . '}',
        '\raggedright{}',
      );
    }

    if (!empty($fields)) {
      foreach($fields as $field_key => $field) {
        $rows[] = array(
          '\raggedright{' . latex_safe($field['label']) . '}',
          '\raggedright{' . latex_safe(latex_widget_type($field['widget']['type'])) . '}',
          '\raggedright{' . latex_safe($field['description']) . '}',
        );
      }
    }

    if (module_exists('metatag')) {
      $rows[] = array(
        '\raggedright{Pagina-titel (meta)}',
        '\raggedright{Tekst}',
        '\raggedright{Pagina-titel zoals die bijv. gebruikt wordt door zoekmachines en wordt getoond in de titel-balk van browsers. Wordt standaard gevuld met het patroon [Titel] | [Sitenaam].}',
      );
      $rows[] = array(
        '\raggedright{Meta-omschrijving}',
        '\raggedright{Tekst}',
        '\raggedright{Inhoud van de meta-tag \emph{Description} die gebruikt wordt door zoekmachines. Wordt standaard gevuld met de inhoud van het veld \emph{Intro}.}',
      );
      $rows[] = array(
        '\raggedright{Meta-sleutelwoorden}',
        '\raggedright{Tekst}',
        '\raggedright{Inhoud van de meta-tag \emph{Keywords}. Wordt \emph{niet} gebruikt door de meeste zoekmachines.}',
      );
    }

    if (count($rows)) {
      $data = array(
        'header' => array('Veld', 'Type', 'Omschrijving'),
        'weight' => array(1, 1, 2),
        'rows' => $rows,
      );

      $output .= latex_table($data, $tabletype);
    }
    else {
      $ouput .= 'Dit content type heeft geen velden.'.N;
    }
  }

  // The end!
 return $output;
}

/**
 * Page callback for DOP Docs Pathauto.
 *
 * @todo: Integration with pathauto. For now all the contenttypes are listed,
 * with no pathauto information.
 *
 * @return string Latex formated output for part contenttypes.
 */
function latex_extract_report_pathauto() {

  $types = node_type_get_types();
  $names = node_type_get_names();

  $content = '';
  foreach ($names as $key => $name) {
    $type = $types[$key];
    $content .= '\pathauto{' . latex_safe($name) . '}{ pad }{ opmerking }'.N;
  }

  return _latex_extract_output('Pathauto', $content);
  // The end!

}


/**
 * Helper function for output.
 */
function _latex_extract_output($title, $content) {

  drupal_set_title($title);

  $output = '<pre>';
  $output .= $content;
  $output .= '</pre>';

  return $output;
}
