<?php

/**
 * Check if the current user is allowed to publish changes to this node.
 *
 * @param object $node
 * @return bool
 */
function _scheduler_revision_allow_publication($node) {
  global $user;
  if (isset($node->workbench_moderation['current']->state)) {
    $moderation_state = $node->workbench_moderation['current']->state;
  }
  else {
    $moderation_state = variable_get('workbench_moderation_default_state_' . $node->type, workbench_moderation_state_none());
  }
  if ($moderation_state == workbench_moderation_state_published()) {
    $moderation_state = workbench_moderation_state_none();
  }
  $states = workbench_moderation_states_next($moderation_state, $user, $node);
  return isset($states['published']);
}

/**
 * Publish scheduled revisions.
 */
function _scheduler_revision_cron() {
  $nodes = db_select('scheduler_revision', 'r')
    ->fields('r', array('nid', 'vid'))
    ->condition('r.publish_revision_on', REQUEST_TIME, '<')
    ->range(0, 25)
    ->execute();
  foreach ($nodes as $node) {
    if ($node = node_load($node->nid, $node->vid)) {
      workbench_moderation_moderate($node, 'published');
      watchdog('scheduler_revision', '@type: scheduled publishing of %title.', array(
        '@type' => $node->type,
        '%title' => $node->title,
      ), WATCHDOG_NOTICE, l(t('view'), 'node/' . $n->nid, array('alias' => TRUE)));
    }
    db_delete('scheduler_revision')
      ->condition('nid', $node->nid)
      ->condition('vid', $node->vid)
      ->execute();
  }
}
