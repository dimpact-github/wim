<?php

function phalanx_main_page() {
	return 'main page, todo!';
}

function phalanx_form_overview() {
	module_load_include('inc', 'phalanx', 'phalanx.database');
	module_load_include('inc', 'phalanx', 'phalanx.helpers');
	return phalanx_form_table_layout(phalanx_get_forms_overview());
}

function phalanx_form_history($form_id) {
	module_load_include('inc', 'phalanx', 'phalanx.database');
	module_load_include('inc', 'phalanx', 'phalanx.helpers');
	drupal_set_title('History for '.$form_id);

	$edits = phalanx_get_form_history($form_id);
	$history = phalanx_process_history_data($edits);

	return phalanx_format_history_data($history);
}