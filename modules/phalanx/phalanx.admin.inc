<?php

function phalanx_admin($form, &$form_state) {
	$form['phalanx_forms'] = array(
		'#type' => 'fieldset',
  		'#title' => t('Phalanx forms'),
  		'#collapsible' => FALSE,
  		'#collapsed' => FALSE,
	);
	$form['phalanx_forms']['phalanx_forms_enable'] = array(
		'#type' => 'checkbox',
		'#title' => 'Enable Phalanx Forms',
		'#description' => t('By selecting this option you can enable the Phalanx Forms Logging'),
		'#default_value' => variable_get('phalanx_forms_enable', TRUE),
	);
	$form['phalanx_forms']['phalanx_exclude_forms'] = array(
  		'#type' => 'textarea',
  		'#title' => t('The forms to exclude'),
  		'#description' => t('One form per line (systemname of the form), NOT IMPLEMENTED YET'),
    	'#default_value' => variable_get('phalanx_exclude_forms', ''),
	);
	$form['phalanx_forms']['phalanx_admin_forms'] = array(
		'#type' => 'checkbox',
		'#title' => 'Admin forms only',
		'#description' => t('By selecting this option only the forms in the admin interface will be logged'),
		'#default_value' => variable_get('phalanx_admin_forms', TRUE),
	);
	$form['phalanx_forms']['phalanx_admin_stealth_mode'] = array(
		'#type' => 'checkbox',
		'#title' => 'Enable admin stealth mode',
		'#description' => t('By selecting this option the actions from the admin user will not get logged'),
		'#default_value' => variable_get('phalanx_admin_stealth_mode', TRUE),
	);
		$form['phalanx_forms']['phalanx_notify_user'] = array(
		'#type' => 'checkbox',
		'#title' => 'Notify users that Phalanx is active',
		'#description' => t('By selecting this option the users will be notified that the forms are being monitored by Phalanx'),
		'#default_value' => variable_get('phalanx_notify_user', TRUE),
	);

 	return system_settings_form($form);
}