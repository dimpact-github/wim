<?php
$info = array(
  // Available colors and color labels used in theme.
  'fields' => array(
    'dcolor' => t('Base color'),
    'dcolorlight' => t('Light color'),
    'dlinkcolor' => t('Link color'),
    'dbackgroundcolor' => t('Background color'),
    'dtoptakencolor' => t('Toptaken color'),
    'dheadingcolor' => t('Heading color'),
    'dbuttoncolor' => t('Button color'),
  ),

  // Pre-defined color schemes.
  'schemes' => array(
    'default' => array(
      'title' => t('Azure'),
      'colors' => array(
        'dcolor' => '#007bc7',
        'dcolorlight' => '#B2D7EE',
        'dlinkcolor' => '#ffffff',
        'dbackgroundcolor' => '#dddddd',
        'dtoptakencolor' => '#007bc7',
        'dheadingcolor' => '#333',
        'dbuttoncolor' => '#007bc7',
      ),
    ),
    'dark-brown' => array(
      'title' => t('Dark Brown'),
      'colors' => array(
        'dcolor' => '#623327',
        'dcolorlight' => '#D1C1BE',
        'dlinkcolor' => '#ffffff',
        'dbackgroundcolor' => '#dddddd',
        'dtoptakencolor' => '#623327',
        'dheadingcolor' => '#333',
        'dbuttoncolor' => '#623327',
      ),
    ),
    'dark-green' => array(
      'title' => t('Green'),
      'colors' => array(
        'dcolor' => '#275937',
        'dcolorlight' => '#BECDC3',
        'dlinkcolor' => '#ffffff',
        'dbackgroundcolor' => '#dddddd',
        'dtoptakencolor' => '#275937',
        'dheadingcolor' => '#333',
        'dbuttoncolor' => '#275937',
      ),
    ),
    'purple' => array(
      'title' => t('Purple'),
      'colors' => array(
        'dcolor' => '#42145f',
        'dcolorlight' => '#C6B8CF',
        'dlinkcolor' => '#ffffff',
        'dbackgroundcolor' => '#dddddd',
        'dtoptakencolor' => '#42145f',
        'dheadingcolor' => '#333',
        'dbuttoncolor' => '#42145f',
      ),
    ),
  ),

  // CSS files to override compiled from the SCSS
  'css' => array(
    'style.css',
  ),
);
