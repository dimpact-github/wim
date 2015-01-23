<?php

function install_step_config() {
  if (empty($_SESSION['config'])) {
    return 'De sessie is verlopen. U moet de installatie opnieuw opstarten.';
  }
  $config = $_SESSION['config'];

  $db = install_get_database_settings();
  mysql_connect($db['host'], $db['username'], $db['password']);
  mysql_select_db($db['database']);

  install_step_config_set_variable('site_name', $config['name']);
  install_step_config_set_variable('site_mail', $config['mail']);
  install_step_config_set_domain($config['domain'], $config['name']);
  install_step_config_set_password($config['password']);

  install_step_next();
}

function install_step_config_set_variable($name, $value) {
  $value = serialize($value);
  mysql_query('UPDATE variable SET value = \'' . addslashes($value) . '\' WHERE name = \'' . addslashes($name) . '\';');
}

function install_step_config_set_domain($domain, $name) {
  $domain_length = strlen($domain) + 13;
  mysql_query('UPDATE variable SET value = "s:' . $domain_length . ':\"http://piwik.'. addslashes($domain) .'\";" WHERE name = "piwik_url_http";');
  mysql_query('INSERT INTO apachesolr_environment (env_id, name, url) VALUES ("solr", "solr", "http://localhost:8080/solr/dimpact")');
  mysql_query('UPDATE domain SET subdomain = REPLACE(subdomain, \'.distributie.dimpact.dop.nu\', \'.' . addslashes($domain) . '\');');
  mysql_query('UPDATE domain SET subdomain = REPLACE(subdomain, \'distributie.dimpact.dop.nu\', \'' . addslashes($domain) . '\');');
  mysql_query('UPDATE domain SET sitename = REPLACE(sitename, \'Dimpact\', \'' . addslashes($name) . '\');');
  mysql_query('UPDATE domain SET machine_name = REPLACE(REPLACE(CONCAT(LOWER(subdomain), COALESCE(CONCAT(\'_\', LOWER(dominion_directory)), \'\')), \'.\', \'_\'), \'/\', \'_\');');
  install_step_config_set_variable('dominion_domain_suffix', ".$domain");
}

function install_step_config_set_password($password) {
  if (!function_exists('variable_get')) {
    function variable_get($name, $default) {
      $res = mysql_query('SELECT value FROM variable WHERE name = \'' . addslashes($name) . '\';');
      return ($value = @mysql_result($res, 0, 0)) ? $value : $default;
    }
  }
  if (!function_exists('drupal_random_bytes')) {
    function drupal_random_bytes($count) {
      return install_random_bytes($count);
    }
  }
  require DRUPAL_ROOT . '/includes/password.inc';
  $hash = user_hash_password($password);
  mysql_query('UPDATE users SET pass = \'' . addslashes($hash) . '\' WHERE name != \'servicedesk\' AND uid > 0;');
}
