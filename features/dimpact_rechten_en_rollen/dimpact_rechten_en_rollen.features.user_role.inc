<?php
/**
 * @file
 * dimpact_rechten_en_rollen.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function dimpact_rechten_en_rollen_user_default_roles() {
  $roles = array();

  // Exported role: medewerker.
  $roles['medewerker'] = array(
    'name' => 'medewerker',
    'weight' => 3,
  );

  return $roles;
}
