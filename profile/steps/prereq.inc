<?php

function install_step_prereq() {
  return install_step_prereq_form();
  // return install_render_template('prereq');
}

function install_step_prereq_form($errors = array()) {

  return install_render_template('prereq', array(
    'action' => install_check_plain($_SERVER['REQUEST_URI']),
  ));

}
