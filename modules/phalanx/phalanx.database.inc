<?php

function phalanx_get_forms_overview() {
	$result = db_query('SELECT MAX(updated) as latest_update, count(updated) as count, action, form_id, name, pf.uid
						FROM phalanx_forms pf 
						INNER JOIN users u ON pf.uid = u.uid
						GROUP BY form_id
						ORDER BY MAX(updated) DESC');
	return $result->fetchAll();
}

function phalanx_get_form_history($form_id) {
	$result = db_query('SELECT *, pf.uid, name
						FROM phalanx_forms pf
						INNER JOIN users u ON pf.uid = u.uid
						WHERE form_id = :form_id
						ORDER BY updated DESC',
						array(':form_id' => $form_id));
	return $result->fetchAll();
}

function phalanx_insert_record($user, $form, $form_state) {
	db_insert('phalanx_forms')
  		->fields(array(
    	'updated' => REQUEST_TIME,
    	'form_id' => $form['#id'],
    	'action' => $form['#action'],
    	'form_data' => serialize($form_state),
    	'uid' => $user->uid
  	))
  	->execute();
  	if (variable_get('phalanx_notify_user', FALSE)) {
  		drupal_set_message(t('Phalanx: Phalanx has recorded this form save.'));
  	}
} 