<?php

function phalanx_guard_violations() {
	module_load_include('inc', 'phalanx_guard', 'phalanx_guard_database');
	$violations = phalanx_guard_get_violations();

	$rows = array();
	$header = array('Submission', 'Form ID', 'User', 'Message');
	foreach ($violations as $violation) {
		$rows[] = array(
			format_date($violation->updated, 'short'),
			$violation->form_id,
			l($violation->name, 'user/' . $violation->uid),
			$violation->message,	
		);
	}
	return theme('table', array('header' => $header, 'rows' => $rows));
}