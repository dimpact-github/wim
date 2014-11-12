<?php

function install_step_settingsfile() {
  $checks = array(
    'exists' => 'Het bestand sites/default/settings.php moet worden aangemaakt',
    'database' => 'Aanwezigheid van databaseconfiguratie',
    'databaseprefix' => 'De databaseprefix moet leeg zijn',
    'dbdriver' => 'Er wordt gebruik gemaakt van een MySQL of MariaDB database',
    'connection' => 'Verbinding met de mysql server is mogelijk',
    'selectdb' => 'Database is aangemaakt',
    'domain' => 'De domain settings.inc moet worden ingeladen',
  );
  return install_checklist($checks, __FUNCTION__);
}

function install_step_settingsfile_exists() {
  return is_file(DRUPAL_ROOT . '/sites/default/settings.php');
}

function install_step_settingsfile_database() {
  // Check if $databases exists in the settingsfile.
  return (bool) install_get_database_settings();
}

function install_step_settingsfile_databaseprefix() {
  $db = install_get_database_settings();
  return empty($db['prefix']);
}

function install_step_settingsfile_dbdriver() {
  $db = install_get_database_settings();
  return $db['driver'] == 'mysql';
}

function install_step_settingsfile_connection() {
  $db = install_get_database_settings();
  if (!@mysql_connect($db['host'], $db['username'], $db['password'])) {
    return FALSE;
  }
  return TRUE;
}

function install_step_settingsfile_selectdb() {
  $db = install_get_database_settings();
  if (!@mysql_select_db($db['database'])) {
    return FALSE;
  }
  return TRUE;
}

function install_step_settingsfile_domain() {
  $contents = file_get_contents(DRUPAL_ROOT . '/sites/default/settings.php');
  return strstr($contents, 'sites/all/modules/contrib/domain/settings.inc');
}
