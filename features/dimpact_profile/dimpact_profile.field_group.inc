<?php
/**
 * @file
 * dimpact_profile.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dimpact_profile_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_intern|user|user|form';
  $field_group->group_name = 'group_intern';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Intern',
    'weight' => '1',
    'children' => array(
      0 => 'field_functie',
      1 => 'field_doorkiesnummer',
      2 => 'field_mobiel',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_intern|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_links|user|user|form';
  $field_group->group_name = 'group_links';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '3',
    'children' => array(
      0 => 'field_interne_applicaties',
      1 => 'field_websites',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_links|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_persoonlijk|user|user|form';
  $field_group->group_name = 'group_persoonlijk';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Persoonlijk',
    'weight' => '2',
    'children' => array(
      0 => 'field_kennis_opleidingen_werk',
      1 => 'field_activiteiten_interesses',
      2 => 'field_overige_informatie',
      3 => 'field_persoonlijke_gegevens',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-persoonlijk field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_persoonlijk|user|user|form'] = $field_group;

  return $export;
}
