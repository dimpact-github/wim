<?php
/**
 * @file
 * dimpact_imagestyles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function dimpact_imagestyles_image_default_styles() {
  $styles = array();

  // Exported image style: list_thumbnail.
  $styles['list_thumbnail'] = array(
    'name' => 'list_thumbnail',
    'label' => 'List thumbnail (135x120)',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 135,
          'height' => 120,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: node_thumbnail.
  $styles['node_thumbnail'] = array(
    'name' => 'node_thumbnail',
    'label' => 'Node thumbnail (532x225)',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 532,
          'height' => 225,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
