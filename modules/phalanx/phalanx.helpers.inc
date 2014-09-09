<?php 

	function phalanx_node_table_layout($data) {
		$rows = array();
		$header = array('Node id', 'Title', 'Action', 'Edit', 'User');
		foreach ($data as $row) {
			$rows[] = array(
				$row->nid,
				l($row->form_id, 'node/'.$row->nid),
				$row->action,
				format_date($row->updated, 'short'),
				l($row->name, 'user/'.$row->uid),
			);
		}
		return theme('table', array('header' => $header, 'rows'=>$rows));
	}

	function phalanx_form_table_layout($data) {
		$rows = array();
		$header = array('Form id', 'Action', 'Submission', 'User', 'Total changes');
		foreach ($data as $row) {
			$rows[] = array(
				l($row->form_id, 'admin/phalanx/forms/form/'.$row->form_id),
				$row->action,
				format_date($row->latest_update, 'short'),
				l($row->name, 'user/'.$row->uid),
				$row->count,
			);
		}
		return theme('table', array('header' => $header, 'rows' => $rows));
	}

	function phalanx_process_history_data($data) {
		$initial = $data[0];
		$updates = array();

		if (count($data) > 1) {
			for ($i = 0; $i < count($data) - 1; $i++) {
				$updates[] = phalanx_process_record_changes($data[$i+1], $data[$i]);
			}
		}
		else {
			$updates[] = phalanx_process_record_changes((object)array('form_data' => ''), $data[0]);
		}		
		return array('initial' => $initial, 'updates' => $updates);
	}

	function phalanx_format_history_data($history) {
		$str = '<div class="items"><ul>';
		foreach ($history['updates'] as $record) {
			$str .= '<li><h3>'.$record['user']. ' on '. $record['date'].'</h3></li>';
			$rows = array();
			if (count($record['changes']) > 0) {
				foreach ($record['changes'] as $key => $change) {
					if (is_array($change['old'])) {
						$change['old'] = '<pre>'.print_r($change['old'], true).'</pre>';
					}
					if (is_array($change['new'])) {
						$change['new'] = '<pre>'.print_r($change['new'], true).'</pre>';
					}
					$rows[] = array($key, $change['old'], $change['new']);
				}
			}
			else {
				$rows[] = array('No changes were made on this save', '', '');
			}
			$headers = array('variable', 'old', 'new');
			$str .= theme('table', array('header' => $headers, 'rows' => $rows));
		}
		return $str . '</ul></div>';
	}

	function phalanx_process_record_changes($old, $new) {
		$record = array();


		$record['user'] = l($new->name, 'user/'.$new->uid);
		$record['date'] = format_date($new->updated, 'short');
		$record['changes'] = array();

		$form_state_new = unserialize($new->form_data);
		$form_state_old = unserialize($old->form_data);

		if (!is_array($form_state_old)) {
			$form_state_old = array('values' => array('INITIAL'));
		}

		$record['form_values_new'] = $form_state_new['values'];
		$record['form_values_old'] = $form_state_old['values'];

		foreach($record['form_values_new'] as $key => $value) {
			if (array_key_exists($key, $record['form_values_old'])) {
				if ($value != $record['form_values_old'][$key]) {
					$record['changes'][$key] = array('old' => $record['form_values_old'][$key], 'new' => $value);
				}
			}
			else {
				$record['changes'][$key] = array('old' => 'NULL', 'new' => $value);
			}
		}

		return $record;
	}

	function phalanx_log($form_action) {
		$admin_only = variable_get('phalanx_admin_forms', TRUE);
		$log_node_deletes = variable_get('phalanx_delete_nodes', TRUE);

		$is_admin_form = arg(0) == 'admin' ? TRUE : FALSE;

		if((arg(0) == 'node' && arg(2) == 'delete') && $log_node_deletes) {
			return TRUE;
		}
		if(arg(0) == 'admin' && !$admin_only) {
			return FALSE;
		}
		return TRUE;
	}