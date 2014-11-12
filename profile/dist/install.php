<?php

/**
 * @file
 * Initiates a browser-based installation of Drupal.
 */

/**
 * Defines the root directory of the Drupal installation.
 */
define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/profiles/dimpact/install.inc';
install_dimpact();
