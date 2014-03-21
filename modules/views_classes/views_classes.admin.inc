<?php

/**
 * Admin settings form for each view page to add additional classes to the body tag.
 */
function views_classes_admin_form($form, &$form_state) {
  
  $views = views_get_all_views();
  
  $views['taxonomy_term']->display['page']->display_options['path'];

  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('A form for finding contactunits based on postcode'),
  );

  foreach ($views as $view) {
    foreach ($view->display as $display) {
      if ($display->display_options['path']) {
        $form[$display->display_options['path']] = array(
          '#type' => 'textfield',
          '#title' => 'url: ' . $display->display_options['path'] ,
          '#default_value' => variable_get($display->display_options['path'], ''),
        );
      }
    }
  }

  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('Form to add additional classes to the body class array.'),
  );

  return system_settings_form($form);
}