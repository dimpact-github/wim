<?php
/**
 * @file
 * dimpact_content_types.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dimpact_content_types_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_additions|node|product|form';
  $field_group->group_name = 'group_additions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Aanvullende informatie',
    'weight' => '5',
    'children' => array(
      0 => 'field_contact',
      1 => 'field_cost',
      2 => 'field_objection',
      3 => 'field_particulars',
      4 => 'field_request',
      5 => 'field_term',
      6 => 'field_bijlage',
      7 => 'field_related_pdc',
      8 => 'field_related_vac',
      9 => 'field_extra_afbeelding',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-additions field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_additions|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pdc|node|product|form';
  $field_group->group_name = 'group_pdc';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'PDC informatie',
    'weight' => '4',
    'children' => array(
      0 => 'field_location',
      1 => 'field_date',
      2 => 'field_forms',
      3 => 'field_more_information',
      4 => 'field_related_laws',
      5 => 'field_related_pdc_vac',
      6 => 'field_request_online',
      7 => 'field_sc_audience',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_pdc|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vac|node|vac|form';
  $field_group->group_name = 'group_vac';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'vac';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'VAC informatie',
    'weight' => '5',
    'children' => array(
      0 => 'field_location',
      1 => 'field_more_information',
      2 => 'field_related_pdc_vac',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-vac field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_vac|node|vac|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Aanvullende informatie');
  t('PDC informatie');
  t('VAC informatie');

  return $field_groups;
}
