<!DOCTYPE html>
<html<?php print $html_attributes; ?> class="no-js">
  <head>
    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
    <script src="/<?php print $path; ?>/js/modernizr.js"></script>
    <?php print $styles; ?>
    <?php
      module_load_include('admin.inc', 'dimpact_custom_css', 'dimpact_custom_css');
      global $_domain;
      global $base_url;

      if (domain_conf_variable_get($_domain['domain_id'], 'css_killswitch')) {
        foreach (dimpact_custom_css_files() as $key => $title) {

          $file = file_load(domain_conf_variable_get($_domain['domain_id'], $key));
          $cache_key = variable_get('dimpact_custom_css_cache_key', '');

          if ($key == 'custom_css_screen') {
            print '<link rel="stylesheet" href="' . $base_url . '/' . conf_path() . '/files/custom_css/' . $file->filename . '?' . $cache_key . '" media="screen" />';
          }
          if ($key == 'custom_css_print') {
            print '<link rel="stylesheet" href="' . $base_url . '/' . conf_path() . '/files/custom_css/' . $file->filename . '?' . $cache_key . '" media="print" />';
          }
        }
      }
    ?>
    <?php print $scripts; ?>

    <?php if (variable_get('bespoke_readspeaker_status') == 1): ?>
    <script type="text/javascript" src="http://f1.eu.readspeaker.com/script/26/ReadSpeaker.js?pids=embhl"></script>
    <?php endif; ?>

    <!--[if lte IE 9]>
      <link rel="stylesheet" href="/<?php print $path; ?>/css/lte-ie9.css" media="all">
    <![endif]-->
    <!--[if lt IE 9]>
      <link rel="stylesheet" href="/<?php print $path; ?>/css/lt-ie9.css" media="all">
      <script src="/<?php print $path; ?>/js/libraries/html5shiv/src/html5shiv.js"></script>
      <script src="/<?php print $path; ?>/js/libraries/respond.min.js"></script>
    <![endif]-->
    <?php if (domain_conf_variable_get($_domain['domain_id'], 'css_killswitch')) {
        foreach (dimpact_custom_css_files() as $key => $title) {
          $file = file_load(domain_conf_variable_get($_domain['domain_id'], $key));
                    if ($key == 'custom_css_lteie9') {
            print '<!--[if lte IE 9]><link rel="stylesheet" href="' . $base_url . '/' . conf_path() . '/files/custom_css/' . $file->filename . '?' . $cache_key . '" media="all" /><![endif]-->';
          }
          if ($key == 'custom_css_ltie9') {
            print '<!--[if lt IE 9]><link rel="stylesheet" href="' . $base_url . '/' . conf_path() . '/files/custom_css/' . $file->filename . '?' . $cache_key . '" media="all" /><![endif]-->';
          }
        }
      }
    ?>
  </head>
  <body<?php print $body_attributes;?>>
    <a href="#main" class="visuallyhidden focusable skip-link"><?php print t('Skip to main content'); ?></a>
    <a href="#content" class="visuallyhidden focusable skip-link"><?php print t('Skip to content'); ?></a>
    <div class="overlay-alpha-container"></div>
    <?php print $page_top; ?>
    <?php print $page; ?>
    <?php print $page_bottom; ?>
  </body>
</html>
