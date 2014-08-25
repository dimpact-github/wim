<?php

function phalanx_guard_admin($form, &$form_state) {
	$form['phalanx_guard'] = array(
		'#type' => 'fieldset',
  		'#title' => t('Phalanx Guard Main Settings'),
  		'#collapsible' => FALSE,
  		'#collapsed' => FALSE,
	);
	$form['phalanx_guard']['phalanx_guard_enable'] = array(
		'#type' => 'checkbox',
		'#title' => 'Enable Phalanx Guard',
		'#description' => t('By selecting this option you can enable Phalanx Guard'),
		'#default_value' => variable_get('phalanx_guard_enable', TRUE),
	);
	$form['phalanx_guard']['phalanx_guard_force_logout'] = array(
		'#type' => 'checkbox',
		'#title' => 'Force logout after Phalanx Guard violation',
		'#description' => t('By selecting this option you can force the user to logout after a Phalanx Guard violation'),
		'#default_value' => variable_get('phalanx_guard_force_logout', TRUE),
	);

	return system_settings_form($form);
}