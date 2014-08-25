<?php

function phalanx_guard_insert_log($uid, $formid, $message = '') {
	db_insert('phalanx_guard_log')
		->fields(array(
		'updated' => REQUEST_TIME,
		'form_id' => $formid,
		'uid' => $uid,
		'message' => $message
	))
	->execute();
}

function phalanx_guard_get_violations() {
	$result = db_query('SELECT pgl.updated, pgl.form_id, pgl.message, u.uid, u.name
						FROM phalanx_guard_log pgl
						INNER JOIN users u ON pgl.uid = u.uid
						ORDER BY updated DESC'
					);
	return $result->fetchAll();
}