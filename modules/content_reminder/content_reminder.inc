<?php
/*
 * Private function to get all nodes that require updates
 */

function _get_required_nodes() {
  //Query
  $duedate = time() - (variable_get('content_reminder_days', 20) * 86400);

  $orcond = db_or();

  $types = _get_reminder_types();

  $orcondswitch = false;

  foreach($types as $type) {
    if (variable_get('content_reminder_types_' . $type->type, 0) == 1) {
        $dband = db_and();
        $duedate = time() - (variable_get('content_reminder_types_' . $type->type . '_days', 20) * 86400);
        $dband->condition('n.type', $type->type, '=');
        $dband->condition('nr.timestamp', $duedate,'<');
        $orcond->condition($dband);
        $orcondswitch = true;
    }
  }

  if ($orcondswitch == true) {
    $query = db_select('node','n');
    $query->leftjoin('field_data_field_reminder_email', 're', 're.entity_id = n.nid');
    $query->leftjoin('node_revision','nr', 'nr.vid = n.vid');
    $query->leftjoin('users','u', 'u.uid = nr.uid');
    $query->fields('n', array('nid', 'title', 'changed', 'type',))
          ->fields('nr', array('status'))
          ->fields('u', array('mail'))
          ->fields('re',array('field_reminder_email_email'));
    $query->condition($orcond)
          ->groupBy('n.nid')
          ->orderBy('n.type','ASC');
    $results = $query->execute()->fetchAll();

    return $results;
  } else {
    return NULL;
  }
}

/*
 * Private function to send an e-mail with nodes that require an update
 */

function _prepare_nodes($nodes, $mailtype) {

  $email_nodes = array();
  foreach ($nodes as $node) {
    if (!isset($email_nodes[$node->mail])) {
      $email_nodes[$node->mail] = array();
    }
    $node->url = l($node->title, 'node/' . $node->nid, array('absolute' => TRUE));
    $email_nodes[$node->mail][] = $node;
  }

  $loaded_node = array();
  foreach ($nodes as $node) {
    $loaded_node[$node->nid] = node_load($node->nid);
  }

  $emailremindernodes = array();
  foreach ($loaded_node as $node) {
    if (!empty($node->field_reminder_email)) {
      foreach ($node->field_reminder_email['und'] as $mail_list) {
        foreach ($mail_list as $key => $value) {

          $emailremindernodes[$value][$node->nid]->nid = $node->nid;
          $emailremindernodes[$value][$node->nid]->title = $node->title;
          $emailremindernodes[$value][$node->nid]->changed = $node->changed;
          $emailremindernodes[$value][$node->nid]->type = $node->type;
          $emailremindernodes[$value][$node->nid]->mail = $value;
          $emailremindernodes[$value][$node->nid]->status = $node->status;
          $emailremindernodes[$value][$node->nid]->url = l($node->title, 'node/' . $node->nid, array('absolute' => TRUE));

        }
      }
    }
  }

  _send_mails($email_nodes, $mailtype);
  _send_mails($emailremindernodes, $mailtype);

}

/*
 * Private function to get reminder node types
 */

function _get_reminder_types() {

  $types = node_type_get_types();

  return $types;
}

/*
 * Private function to get expired nodes and update the status to 0 if needed
 */

function _get_old_nodes() {

  $orcond = db_or();
  $types = _get_reminder_types();
  $orcondswitch = false;

  foreach ($types as $type) {
    if ((variable_get('content_reminder_types_' . $type->type, 0) == 1) || variable_get('content_reminder_types_' . $type->type . '_depub_box', 0) == 1) {
        $dband = db_and();
        $duedate = time() - (variable_get('content_reminder_types_' . $type->type . '_depub', 20) * 86400);
        $dband->condition('n.type', $type->type, '=');
        $dband->condition('nr.timestamp', $duedate,'<');
        $orcond->condition($dband);
        $orcondswitch = true;
    }
  }

  if ($orcondswitch == true) {
     $query = db_select('node','n');
      $query->leftjoin('field_data_field_reminder_email', 're', 're.entity_id = n.nid');
      $query->leftjoin('node_revision','nr', 'nr.vid = n.vid');
      $query->leftjoin('users','u', 'u.uid = nr.uid');
      $query->fields('n', array('nid', 'title', 'changed', 'type'))
            ->fields('nr', array('status'))
            ->fields('u', array('mail'))
            ->fields('re',array('field_reminder_email_email'));
      $query->condition($orcond)
            ->groupBy('n.nid')
            ->orderBy('n.type','ASC');
      $mailnodes = $query->execute()->fetchAll();

    foreach ($types as $type) {
      if (variable_get('content_reminder_types_' . $type->type . '_depub_box', 0) == 1) {
        $query = db_select('node_revision', 'nr');
        $query->leftjoin('node','n', 'n.vid = nr.vid');
        $query->fields('n', array('nid'));
        $query->condition($orcond);
        $results = $query->execute()->fetchAll();
        foreach ($results as $result) {
          foreach ($mailnodes as &$mailnode) {
            if ($result->nid == $mailnode->nid) {
              $mailnode->status = 0;
            }
          }
          $node = node_load($result->nid);
          $node->status = 0;
          $a[$result->nid]->status = 0;
          node_save($node);
        }
      }
    }
    return $mailnodes;
  } else {
    return NULL;
  }

}

/*
 * Private function to send e-mails
 */

function _send_mails($mailnodes, $mailtype) {
  foreach ($mailnodes as $mail => $nodes) {
    $build = array(
      '#theme' => 'content_reminder',
      '#nodes' => $nodes,
      '#mailtype' => $mailtype,
      '#content_reminder_text' => variable_get('content_reminder_' . $mailtype . '_text', 'mijn tekstje'),
    );

    $mail_token = microtime();
    $from = variable_get('system_mail', '<reminder@zwolle.nl>');
    $message = array(
      'id' => 'custom' . '_' . $mail_token,
      'to' => $mail,
      'subject' => 'update',
      'body' => drupal_render($build),
      'headers' => array(
        'From' => $from,
        'Sender' => $from,
        'Return-Path' => $from,
        'Content-Type' => 'text/html; charset=UTF-8; format=flowed',
      ),
    );

    $system = drupal_mail_system('custom', $mail_token);
    $system->mail($message);
  }
}
