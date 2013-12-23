<?php

/**
 * Get all defined colours as array.
 *
 * @return array
 *   All defined colours for this theme.
 */
function _rijkshuisstijl_defined_colours() {
  return array(
    'internet_colors' => array(
      'violet' => t('violet'),
      'pink' => t('pink'),
      'red' => t('red'),
      'ruby' => t('ruby'),
      'purple' => t('purple'),
      'orange' => t('orange'),
      'moss-green' => t('moss green'),
      'mint-green' => t('mint green'),
      'light-blue' => t('light blue'),
      'azure' => t('azure'),
      'green' => t('green'),
      'yellow' => t('yellow'),
      'dark-green' => t('dark green'),
      'dark-yellow' => t('dark yellow'),
      'dark-brown' => t('dark brown'),
      'brown' => t('brown'),
    ),
    'intranet_colors' => array(
      'intra_app' => t('intranet color'),
    ),
  );
}

function dimpact_form_system_theme_settings_alter(&$form, $form_state) {
  $form['hide_site_title'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide site title'),
    '#weight' => -20,
    '#default_value' => theme_get_setting('hide_site_title', 'dimpact'),
  );

  $form['color'] = array(
    '#type' => 'fieldset',
    '#title' => t('Color settings'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#weight' => -19,
  );

  $colours = _rijkshuisstijl_defined_colours();
  $colours_assoc_internet = array();
  foreach ($colours['internet_colors'] as $index => $colour) {
    $colours_assoc_internet[$index] = _dimpact_format_color_swatch($index, $colour);
  }

  $form['color']['color_swatch_internet'] = array(
    '#type' => 'radios',
    '#title' => t('Inernet color swatches'),
    '#options' => $colours_assoc_internet,
    '#default_value' => theme_get_setting('color_swatch_internet', 'dimpact'),
    '#states' => array(
      'visible' => array(
        ':input[name="system_type"]' => array('value' => 'internet'),
      ),
    ),
  );
}

/**
 * Format a color checkbox label on the admin screen.
 *
 * @param string $colour
 *   The name of the colour
 *
 * @return string
 *   A string containing the rendered label.
 */
function _dimpact_format_color_swatch($class, $label) {
  return "<span class=\"" . $class . "\">" . $label . "</span>";
}
