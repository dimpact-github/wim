<?php

/**
 * Admin settings form for each view page to add additional classes to the body tag.
 */
function views_classes_admin_form($form, &$form_state) {
  $views = views_get_all_views();
  $views['taxonomy_term']->display['page']->display_options['path'];

  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('Op deze pagina kunt u CSS-klassen opgeven, die vervolgens aan de body van de betreffende pagina worden toegevoegd.'),
  );

  foreach ($views as $view) {
    foreach ($view->display as $display) {
      if ($display->display_options['path']) {
        $form[$display->display_options['path']] = array(
          '#type' => 'textfield',
          '#title' => 'Pagina-url: ' . $display->display_options['path'] ,
          '#default_value' => variable_get($display->display_options['path'], ''),
        );
      }
    }
  }

  return system_settings_form($form);
}