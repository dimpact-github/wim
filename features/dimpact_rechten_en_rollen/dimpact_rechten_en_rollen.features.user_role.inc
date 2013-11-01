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

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: eindredacteur.
  $roles['eindredacteur'] = array(
    'name' => 'eindredacteur',
    'weight' => 4,
  );

  // Exported role: medewerker.
  $roles['medewerker'] = array(
    'name' => 'medewerker',
    'weight' => 7,
  );

  // Exported role: redacteur.
  $roles['redacteur'] = array(
    'name' => 'redacteur',
    'weight' => 5,
  );

  // Exported role: teamlid.
  $roles['teamlid'] = array(
    'name' => 'teamlid',
    'weight' => 6,
  );

  return $roles;
}
