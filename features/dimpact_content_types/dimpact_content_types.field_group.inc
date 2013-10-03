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
  $field_group->identifier = 'group_tabs|node|product|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '2',
    'children' => array(
      0 => 'field_tabcontent',
      1 => 'field_tabtitel',
    ),
    'format_type' => 'field_group_multiple_container',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'parent_format_type' => 'div',
        'classes' => 'group-tabs field-group-field_group_multiple_container',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_tabs|node|product|form'] = $field_group;

  return $export;
}
