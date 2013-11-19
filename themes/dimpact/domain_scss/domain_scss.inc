<?php
$info = array(
  // Available colors and color labels used in theme.
  'fields' => array(
    'dcolor' => t('Base Color'),
    'dcolorlight' => t('Light Color'),
    'dlinkcolor' => t('Link Color'),
    'dbackgroundcolor' => t('Background Color'),
  ),

  // Pre-defined color schemes.
  'schemes' => array(
    'default' => array(
      'title' => t('Azure'),
      'colors' => array(
        'dcolor' => '#007bc7',
        'dcolorlight' => '#B2D7EE',
        'dlinkcolor' => '#ffffff',
        'dbackgroundcolor' => '#dddddd'
      ),
    ),
    'dark-brown' => array(
      'title' => t('Dark Brown'),
      'colors' => array(
        'dcolor' => '#623327',
        'dcolorlight' => '#D1C1BE',
        'dlinkcolor' => '#ffffff',
        'dbackgroundcolor' => '#dddddd'
      ),
    ),
    'dark-green' => array(
      'title' => t('Green'),
      'colors' => array(
        'dcolor' => '#275937',
        'dcolorlight' => '#BECDC3',
        'dlinkcolor' => '#ffffff',
        'dbackgroundcolor' => '#dddddd'
      ),
    ),
    'purple' => array(
      'title' => t('Purple'),
      'colors' => array(
        'dcolor' => '#42145f',
        'dcolorlight' => '#C6B8CF',
        'dlinkcolor' => '#ffffff',
        'dbackgroundcolor' => '#dddddd'
      ),
    ),
  ),

  // CSS files to override compiled from the SCSS
  'css' => array(
    'style.css',
  ),
);
