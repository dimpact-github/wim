<?php
/**
 * @file
 * dimpact_content_types.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dimpact_content_types_field_group_info() {
  $export = array();

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
    'weight' => '4',
    'children' => array(
      0 => 'field_bijlage',
      1 => 'field_related_pdc',
      2 => 'field_related_vac',
      3 => 'field_contact',
      4 => 'field_cost',
      5 => 'field_objection',
      6 => 'field_particulars',
      7 => 'field_request',
      8 => 'field_term',
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
  $export['group_additions|node|product|form'] = $field_group;

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
    'weight' => '3',
    'children' => array(
      0 => 'field_location',
      1 => 'field_more_information',
      2 => 'field_related_laws',
      3 => 'field_request_online',
      4 => 'field_date',
      5 => 'field_sc_audience',
      6 => 'field_related_pdc_vac',
      7 => 'field_forms',
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
  $export['group_pdc|node|product|form'] = $field_group;

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
    'weight' => '4',
    'children' => array(
      0 => 'field_more_information',
      1 => 'field_related_pdc_vac',
      2 => 'field_location',
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
  $export['group_vac|node|vac|form'] = $field_group;

  return $export;
}
