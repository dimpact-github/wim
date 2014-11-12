<?php

function install_step_server() {
  if (!install_passed('install_step_settingsfile')) {
    header('Location: install.php');
    exit;
  }

  $checks = array(
    'version' => 'Minimaal PHP versie 5.3.0',
    'memory' => 'Geheugenlimiet minimaal 128M',
    'filesdir' => 'Map sites/default/files is aangemaakt',
    'fileswriteable' => 'Webserver heeft schrijfrechten op de files directory',
    'dbempty' => 'Database is leeg',
  );
  return install_checklist($checks, __FUNCTION__);
}

function install_step_server_version() {
  return version_compare(PHP_VERSION, '5.3.0') >= 0;
}

function install_step_server_memory() {
  $limit = ini_get('memory_limit');
  if (preg_match('/^([0-9]+)M$/si', $limit, $match)) {
    return intval($match[1]) > 128;
  }
  else {
    // Unsure, but continue;
    return TRUE;
  }
}

function install_step_server_filesdir() {
  return is_dir(DRUPAL_ROOT . '/sites/default/files');
}

function install_step_server_fileswriteable() {
  return is_writeable(DRUPAL_ROOT . '/sites/default/files');
}

function install_step_server_dbempty() {
  $db = install_get_database_settings();
  if (!@mysql_connect($db['host'], $db['username'], $db['password'])) {
    return FALSE;
  }
  if (!@mysql_select_db($db['database'])) {
    return FALSE;
  }
  $res = mysql_query('SHOW TABLES');
  $tables = mysql_num_rows($res);
  return $tables == 0;
}
