<?php

/**
 * @file
 * Update local Dimpact user directory to match data from external provider.
 */

function dimpact_auth_update($provider) {
  dimpact_auth_update_delete_authnames($provider);
  dimpact_auth_update_update_authnames($provider);
  dimpact_auth_update_insert_authnames($provider);
}

/**
 * Deletes users from local directory.
 */
function dimpact_auth_update_delete_authnames($provider) {
  $authnames = module_invoke($provider, 'dimpact_auth_authnames_to_delete');

  if ($authnames) {
    db_delete()->condition('authname', $authnames, 'IN')->execute();
    module_invoke_all('dimpact_auth_field_delete', $authnames);
  }
}

/**
 * Updates users in local directory.
 */
function dimpact_auth_update_update_authnames($provider) {
  $authnames = module_invoke($provider, 'dimpact_auth_authnames_to_update');

  // Merge listed users.
  if ($authnames) {
    foreach ($authnames as $authname) {
      db_merge('dimpact_auth')
        ->key(array('authname' => $authname))
        ->fields(array(
            'authname' => $authname,
          ))
        ->execute();
    }
    module_invoke_all('dimpact_auth_field_update', $authnames);
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
      db_insert('dimpact_auth')
        ->fields(array(
            'authname' => $authname,
            'created' => REQUEST_TIME,
          ))
        ->execute();
    }

    module_invoke_all('dimpact_auth_field_insert', $authnames);
  }
}
