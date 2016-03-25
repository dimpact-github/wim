<?php

/**
 * @file dimpact_docreader.admin.inc
 */

// List of languages currently supported by docReader (http://www.readspeaker.com/nl/readspeaker-docreader/)
function docreader_supported_languages() {
  $languages = array( 'nl_nl' => 'Nederlands',
                      'fy_nl' => 'Fries',
                      'en_uk' => 'Brits Engels',
                      'de_de' => 'Duits',
                      'fr_fr' => 'Frans',
                      'es_es' => 'Spaans',
                      'sv_se' => 'Zweeds',
                      'no_nb' => 'Noors (Bokmål)',
                      'fi_fi' => 'Fins',
                      'ru_ru' => 'Russisch',
                      'ar_ar' => 'Arabisch' );
  
  return $languages;
}

/**
 * Form builder.
 */
function dimpact_docreader_settings_form($form, &$form_state) {
  $form['dimpact_docreader_cid'] = array(
    '#type' => 'textfield',
    '#title' => t('Klant-id'),
    '#description' => t('Uw klant-id kunt u opvragen bij <a href="http://www.readspeaker.com/nl/readspeaker-docreader/">docReader</a>.'),
    '#default_value' => variable_get('dimpact_docreader_cid', ''),
    '#required' => TRUE,
  );
  $form['dimpact_docreader_language'] = array(
    '#type' => 'select',
    '#title' => t('Voorleestaal'),
    '#options' => docreader_supported_languages(),
    '#default_value' => variable_get( 'dimpact_docreader_language', 'nl_nl' ),
    '#required' => TRUE,
  );
  $form['dimpact_docreader_supported_file_extensions'] = array(
    '#type' => 'textfield',
    '#title' => t('Ondersteunde bestandsextensies'),
    '#description' => t('De bestandsextensies waarvoor een docReader-voorleeslink gegenereerd moet worden. Bestandsextensies dienen gescheiden te worden door een komma. Een lijst van ondersteunde documentformaten vindt u
                         op de <a href="http://www.readspeaker.com/nl/readspeaker-docreader/">docReader-website</a>.'),
    '#default_value' => variable_get( 'dimpact_docreader_supported_file_extensions', docreader_supported_file_extensions() ),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
