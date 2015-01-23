<?php

function install_dimpact() {
  session_start();
  $step = install_step_current();
  $function = "install_step_$step";
  require __DIR__ . "/steps/$step.inc";
  $content = $function();
  print install_render_template('page', array('content' => $content));
}

function install_render_template($file, $params = array()) {
  extract($params);
  ob_start();
  require __DIR__ . "/templates/$file.tpl.php";
  $content = ob_get_contents();
  ob_end_clean();
  return $content;
}

function install_steps() {
  return array(
    'prereq' => 'Prerequisites installeren',
    'settingsfile' => 'Settings.php controleren',
    'server' => 'Server controleren',
    'settings' => 'Opties instellen',
    'database' => 'Database',
    'config' => 'Drupal configureren',
    'done' => 'Gereed',
  );
}

function install_step_current() {
  $steps = install_steps();
  return isset($_GET['step']) && isset($steps[$_GET['step']]) ? $_GET['step'] : reset(array_keys($steps));
}

function install_step_next() {
  $steps = array_keys(install_steps());
  $index = array_search(install_step_current(), $steps);
  if ($index !== FALSE && isset($steps[$index + 1])) {
    header('Location: install.php?step=' . $steps[$index + 1]);
  }
}

function install_passed($checklist, $set = FALSE) {
  if (empty($_SESSION['passed'])) {
    $_SESSION['passed'] = array();
  }
  if ($set) {
    $_SESSION['passed'][] = $checklist;
  }
  return in_array($checklist, $_SESSION['passed']);
}

function install_checklist($checks, $function_prefix) {
  $passed = 0;
  foreach (array_keys($checks) as $check) {
    $current = $check;
    $function = "{$function_prefix}_$check";
    if (!$function()) {
      break;
    }
    ++$passed;
  }
  if ($passed == count($checks)) {
    install_passed($function_prefix, TRUE);
    install_step_next();
  }
  return install_render_template('checklist', array('current' => $current, 'steps' => $checks));
}

function install_post_values() {
  $values = array();
  foreach ($_POST as $name => $value) {
    $values[$name] = ini_get('register_globals') ? stripslashes($value) : $value;
  }
  return $values;
}

function install_check_plain($input) {
  return htmlentities($input, ENT_COMPAT, 'UTF-8');
}

function install_get_database_settings() {
  // Check if $databases exists in the settingsfile.
  $contents = file_get_contents(DRUPAL_ROOT . '/sites/default/settings.php');
  if (!preg_match('/\\$databases\\[\'default\'\\]\\[\'default\'\\][\s]+\\=[\s]array.+?\\)\\;/si', $contents, $match)) {
    return FALSE;
  }
  $settings = @eval($match[0]);
  if (!is_array($databases['default']) || !is_array($databases['default']['default'])) {
    return FALSE;
  }
  $db = $databases['default']['default'];
  if (empty($db['driver']) || empty($db['username']) || empty($db['password']) || empty($db['host']) || empty($db['database'])) {
    return FALSE;
  }
  return $db;
}

function install_random_bytes($count) {
  $bytes = hash('sha256', microtime() . mt_rand());
  return substr($bytes, 0, $count);
}
