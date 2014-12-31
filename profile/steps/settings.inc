<?php

function install_step_settings() {
  if (!install_passed('install_step_server')) {
    header('Location: install.php');
    exit;
  }

  $values = install_post_values();
  if (!isset($values['name'])) {
    return install_step_settings_form();
  }
  $errors = array();
  if (empty($values['name'])) {
    $errors[] = 'Vul een naam in voor de website.';
  }
  if (empty($values['mail'])) {
    $errors[] = 'Vul een e-mailadres in.';
  }
  if (empty($values['domain'])) {
    $errors[] = 'Vul een domeinnaam in.';
  }
  elseif (!preg_match('/^[.a-z0-9\\-]+$/', $values['domain'])) {
    $errors[] = 'Ongeldige domeinnaam. Alleen alfanumerieke tekens en afbreekstreepjes zijn toegestaan.';
  }
  if (empty($values['password'])) {
    $errors[] = 'Vul een wachtwoord in.';
  }
  elseif (empty($values['password2'])) {
    $errors[] = 'Herhaal het opgegeven wachtwoord.';
  }
  elseif ($values['password'] != $values['password2']) {
    $errors[] = 'De opgegeven wachtwoorden komen niet overeen.';
  }
  if ($errors) {
    return install_step_settings_form($errors);
  }
  else {
    $_SESSION['config'] = $values;
    install_step_next();
  }
}

function install_step_settings_form($errors = array()) {
  $domain = isset($_SERVER['HTTP_HOST']) ? $_SERVER['HTTP_HOST'] : 'gemeente.nl';
  $name = '';
  if (preg_match('/([a-z0-9\\-]+)$/si', preg_replace('/\\.[a-z]{2,3}$/', '', $domain), $match)) {
    $name = ucfirst(str_replace('-', ' ', $match[1]));
  }

  $random = install_random_bytes(24);
  $values = install_post_values();
  $values += array(
    'name' => "$name",
    'mail' => "info@$domain",
    'domain' => "$domain",
    'password' => $random,
    'password2' => $random,
  );

  return install_render_template('settings', array(
    'action' => install_check_plain($_SERVER['REQUEST_URI']),
    'values' => array_map('install_check_plain', $values),
    'errors' => array_map('install_check_plain', $errors),
  ));
}
