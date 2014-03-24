<?php
/*
 * Private function to get all nodes that require updates
 */

function _get_required_nodes() {
  //Query
  $duedate = time() - (variable_get('content_reminder_days', 20) * 86400);

  $orcond = db_or();

  $types = _get_reminder_types();

  foreach($types as $type) {
    if (variable_get('content_reminder_types_' . $type->type, 0) == 1) {
        $dband = db_and();
        $duedate = time() - (variable_get('content_reminder_types_' . $type->type . '_days', 20) * 86400);
        $dband->condition('n.type', $type->type, '=');
        $dband->condition('n.changed', $duedate,'<');
        $orcond->condition($dband);
    }
  }

    $query = db_select('node','n');
    $query->leftjoin('node_revision','nr', 'nr.nid = n.nid');
    $query->leftjoin('users','u', 'u.uid = nr.uid');
    $query->fields('n', array('nid', 'title', 'changed', 'type'))
          ->fields('u', array('mail'));
    $query->addExpression('MAX(nr.vid)');
    $query->condition($orcond)
          ->groupBy('n.nid')
          ->orderBy('n.type','ASC');
    $results = $query->execute()->fetchAll();
    
  return $results;

}

/*
 * Private function to send an e-mail with nodes that require an update
 */

function _send_reminder_mail($nodes) {
  $email_nodes = array();
  foreach ($nodes as $node) {
    if (!isset($email_nodes[$node->mail])) {
      $email_nodes[$node->mail] = array();
    }
    $email_nodes[$node->mail][] = $node;
  }

  foreach ($email_nodes as $email_node) {
    $build = array(
      '#theme' => 'content_reminder',
      '#nodes' => $email_node,
      '#kip' => 5,
    );

    $mail_token = microtime();
    $from = variable_get('system_mail', 'My Email Address <example@example.com>');
    $message = array(
      'id' => 'custom' . '_' . $mail_token,
      'to' => $email_node[0]->mail,
      'subject' => 'update',
      'body' => drupal_render($build),
      'headers' => array(
        'From' => $from,
        'Sender' => $from,
        'Return-Path' => $from,
      ),
    );
    $system = drupal_mail_system('custom', $mail_token);
    $message = $system->format($message);
    $system->mail($message);

  }
}

/*
 * Private function to get reminder node types
 */

function _get_reminder_types() {

  $types = node_type_get_types();

  return $types;
}

function _get_old_nodes() {

  $orcond = db_or();
  $types = _get_reminder_types();

  foreach ($types as $type) {
    if (variable_get('content_reminder_types_' . $type->type, 0) == 1) {
        $dband = db_and();
        $duedate = time() - (variable_get('content_reminder_types_' . $type->type . '_depub', 20) * 86400);
        $dband->condition('type', $type->type, '=');
        $dband->condition('changed', $duedate,'<');
        $orcond->condition($dband);
    }
  }
    $query = db_update('node');
    $query->fields(array('status' => 0));
    $query->condition($orcond);
    $results = $query->execute();
  return $results;
}