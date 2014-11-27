<?php

function install_step_done() {
  if (!install_passed('install_step_server')) {
    header('Location: install.php');
    exit;
  }

  // Reset the passed list, to prevent running the installer again.
  $_SESSION['passed'] = array();

  return install_render_template('done');
}
