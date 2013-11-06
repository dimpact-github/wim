<!DOCTYPE html>
<html<?php print $html_attributes; ?>>
  <head>
    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
    <link rel="dns-prefetch" href="//themes.googleusercontent.com">
    <link rel="dns-prefetch" href="//fonts.googleapis.com">
    <script src="/<?php print $path; ?>/js/modernizr.js"></script>
    <?php print $styles; ?>
    <?php print $scripts; ?>
    <!--[if lte IE 9]>
      <link rel="stylesheet" href="/<?php print $path; ?>/css/lte-ie9.css" media="all">
    <![endif]-->
    <!--[if lt IE 9]>
      <link rel="stylesheet" href="/<?php print $path; ?>/css/lt-ie9.css" media="all">
      <script src="/<?php print $path; ?>/js/libraries/html5shiv/src/html5shiv.js"></script>
      <script src="/<?php print $path; ?>/js/libraries/respond.min.js"></script>
    <![endif]-->
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
