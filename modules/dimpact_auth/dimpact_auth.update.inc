<?php

/**
 * @file
 * Update local Dimpact user directory to match data from external provider.
 */

function dimpact_auth_update($provider) {
  // Handle authentication.

  // Delete removed authnames from local directory.
  dimpact_auth_update_delete_authnames($provider);
  // Add new authnames to local directory and schedule for full Drupal updating.
  dimpact_auth_update_insert_authnames($provider);
  // Check existing users for directory updates and schedule for full Drupal updating.
  dimpact_auth_update_update_authnames($provider);

  // Handle directory profile information.

  // @todo Inserted users first. Either order or split up in two fases.
  $authnames = dimpact_auth_update_authnames_to_update();
  // @todo Convert to Batch API.
  foreach($authnames as $authname) {
    $dimpact_user_data = module_invoke($provider, 'dimpact_auth_load', $authname);
    $account = user_external_load($authname);
    if ($account) {
      $edit = array();
      foreach (module_implements('dimpact_auth_field_update') as $module) {
          $function = $module . '_dimpact_auth_field_update';
          $function($dimpact_user_data, $edit, $account);
      }
      user_save($account, $edit);
    }
  }
}

/**
 * Deletes users from local directory.
 */
function dimpact_auth_update_delete_authnames($provider) {
  $authnames = module_invoke($provider, 'dimpact_auth_authnames_to_delete');

  if ($authnames) {
    db_delete('dimpact_auth')->condition('authname', $authnames, 'IN')->execute();
  }
}

/**
 * Flag users in local directory for updating Drupal data.
 */
function dimpact_auth_update_update_authnames($provider) {
  $might_need_updating = module_invoke($provider, 'dimpact_auth_authnames_check_update');

  // Schedule existing users for updating.
  if ($might_need_updating) {
    foreach ($might_need_updating as $authname => $hash) {
      $dimpact_user_data = module_invoke($provider, 'dimpact_auth_load', $authname);
      if ($hash !== hash('sha256', serialize($dimpact_user_data))) {
        db_merge('dimpact_auth')
          ->key(array('authname' => $authname))
          ->fields(array(
              'needs_updating' => 1,
            ))
          ->execute();
      }
    }
  }
}

/**
 * Inserts users in local directory.
 */
function dimpact_auth_update_insert_authnames($provider) {
  $authnames = module_invoke($provider, 'dimpact_auth_authnames_to_insert');

  // Insert users into directory list.
  if ($authnames) {
    foreach ($authnames as $authname) {
      if (isset($authname)) {
        db_insert('dimpact_auth')
          ->fields(array(
              'authname' => $authname,
              'created' => REQUEST_TIME,
              'needs_updating' => 1,
            ))
          ->execute();
      }
    }
  }
}

function dimpact_auth_update_authnames_to_update() {
  $sql = 'SELECT da.authname FROM {dimpact_auth} da WHERE da.needs_updating=1';
  $authnames = db_query($sql)->fetchCol();
  return $authnames;
}
