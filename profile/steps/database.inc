<?php

function install_step_database() {
  if (!install_passed('install_step_server')) {
    header('Location: install.php');
    exit;
  }

  if (isset($_GET['from'])) {
    return install_step_ajax();
  }
  return install_render_template('database');
}

function install_step_ajax() {
  $db = install_get_database_settings();
  mysql_connect($db['host'], $db['username'], $db['password']);
  mysql_select_db($db['database']);

  $from = intval($_GET['from']);
  $count = install_step_database_get_query_count();
  if ($from >= $count) {
    $progress = 100;
    $from = '-1';
  }
  else {
    for ($i = $from; $i < min($count, $from + 10); ++$i) {
      $sql = install_step_database_get_query($i);
      if (!mysql_query($sql)) {
        throw new Exception('Query error: ' . mysql_error() . ' in ' . $sql);
      }
    }
    $progress = round($i / $count * 100);
    $from = $i;
  }
  die("$progress,$from");
}

function install_step_database_get_query_count() {
  return install_step_database_get_query(-1);
}

function install_step_database_get_query($n) {
  static $data;
  if (!isset($data)) {
    $file = __DIR__ . '/../data.sql';
    $data = file_get_contents($file);
    $data = preg_split('/;[\r\n]/s', $data);
  }
  return $n == -1 ? count($data) - 1 : $data[$n];
}
