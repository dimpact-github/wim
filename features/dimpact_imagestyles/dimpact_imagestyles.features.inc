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
        'label' => 'Schalen en bijsnijden',
        'help' => 'Bij het schalen blijft de breedte-hoogte verhouding van de oorspronkelijke afbeelding behouden. Bij het bijsnijden wordt de langste zijde ingekort. Hiermee kunt u bijvoorbeeld vierkante miniaturen maken.',
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
        'label' => 'Schalen en bijsnijden',
        'help' => 'Bij het schalen blijft de breedte-hoogte verhouding van de oorspronkelijke afbeelding behouden. Bij het bijsnijden wordt de langste zijde ingekort. Hiermee kunt u bijvoorbeeld vierkante miniaturen maken.',
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

  // Exported image style: overige_onderwerp.
  $styles['overige_onderwerp'] = array(
    'name' => 'overige_onderwerp',
    'label' => 'Overige onderwerp (390x100)',
    'effects' => array(
      3 => array(
        'label' => 'Schalen en bijsnijden',
        'help' => 'Bij het schalen blijft de breedte-hoogte verhouding van de oorspronkelijke afbeelding behouden. Bij het bijsnijden wordt de langste zijde ingekort. Hiermee kunt u bijvoorbeeld vierkante miniaturen maken.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 390,
          'height' => 100,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: slide_9_3.
  $styles['slide_9_3'] = array(
    'name' => 'slide_9_3',
    'label' => 'Slide 9/3',
    'effects' => array(
      4 => array(
        'label' => 'Schalen en bijsnijden',
        'help' => 'Bij het schalen blijft de breedte-hoogte verhouding van de oorspronkelijke afbeelding behouden. Bij het bijsnijden wordt de langste zijde ingekort. Hiermee kunt u bijvoorbeeld vierkante miniaturen maken.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 740,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
