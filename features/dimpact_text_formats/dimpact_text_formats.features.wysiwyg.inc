<?php
/**
 * @file
 * dimpact_text_formats.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function dimpact_text_formats_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: filtered_html
  $profiles['filtered_html'] = array(
    'format' => 'filtered_html',
    'editor' => 'ckeditor',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 1,
      'theme' => 'advanced',
      'language' => 'nl',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Undo' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Anchor' => 1,
          'Blockquote' => 1,
          'Source' => 1,
          'PasteText' => 1,
          'PasteFromWord' => 1,
          'RemoveFormat' => 1,
          'SpecialChar' => 1,
          'Format' => 1,
          'Table' => 1,
          'Find' => 1,
          'Replace' => 1,
          'Iframe' => 1,
        ),
        'ckeditor_abbrbutton' => array(
          'ckeditor_abbrbutton' => 1,
        ),
        'ckeditor_acronym_button' => array(
          'ckeditor_acronym_button' => 1,
        ),
        'ckeditor_definitionlist_button' => array(
          'ckeditor_definitionlist_button' => 1,
        ),
        'ckeditor_insertionbutton' => array(
          'ckeditor_insertionbutton' => 1,
        ),
        'ckeditor_languagebutton' => array(
          'ckeditor_languagebutton' => 1,
        ),
        'ckeditor_deletionbutton' => array(
          'ckeditor_deletionbutton' => 1,
        ),
        'linkit' => array(
          'linkit' => 1,
        ),
        'drupal' => array(
          'media' => 1,
        ),
      ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'resizing' => 1,
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 1,
      'apply_source_formatting' => 0,
      'paste_auto_cleanup_on_paste' => 0,
      'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6,div',
      'css_setting' => 'self',
      'css_path' => '/%t/css/editor.css',
      'css_classes' => '',
    ),
    'rdf_mapping' => array(),
  );

  // Exported profile: full_html
  $profiles['full_html'] = array(
    'format' => 'full_html',
    'editor' => 'ckeditor',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 1,
      'theme' => 'advanced',
      'language' => 'nl',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Undo' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Anchor' => 1,
          'Blockquote' => 1,
          'Source' => 1,
          'PasteText' => 1,
          'PasteFromWord' => 1,
          'RemoveFormat' => 1,
          'SpecialChar' => 1,
          'Format' => 1,
          'Table' => 1,
          'Find' => 1,
          'Replace' => 1,
          'Iframe' => 1,
        ),
        'ckeditor_abbrbutton' => array(
          'ckeditor_abbrbutton' => 1,
        ),
        'ckeditor_acronym_button' => array(
          'ckeditor_acronym_button' => 1,
        ),
        'ckeditor_definitionlist_button' => array(
          'ckeditor_definitionlist_button' => 1,
        ),
        'ckeditor_insertionbutton' => array(
          'ckeditor_insertionbutton' => 1,
        ),
        'ckeditor_languagebutton' => array(
          'ckeditor_languagebutton' => 1,
        ),
        'ckeditor_deletionbutton' => array(
          'ckeditor_deletionbutton' => 1,
        ),
        'linkit' => array(
          'linkit' => 1,
        ),
        'drupal' => array(
          'media' => 1,
        ),
      ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'resizing' => 1,
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 1,
      'apply_source_formatting' => 0,
      'paste_auto_cleanup_on_paste' => 0,
      'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6,div',
      'css_setting' => 'self',
      'css_path' => '/%t/css/editor.css',
      'css_classes' => '',
    ),
    'rdf_mapping' => array(),
  );

  return $profiles;
}
