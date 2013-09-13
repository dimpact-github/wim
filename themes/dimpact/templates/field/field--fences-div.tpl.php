<?php
/**
 * @file field--fences-div.tpl.php
 * Wrap each field value in the <div> element.
 *
 * @see http://developers.whatwg.org/grouping-content.html#the-div-element
 */
?>
<?php if (in_array($field_name_css, array('field-date', 'field-location'))): ?>
  <div class="field-wrapper field-wrapper-<?php print drupal_html_class($element['#field_name']); ?>">
<?php endif; ?>
  <?php if ($element['#label_display'] == 'inline'): ?>
    <span class="field-label"<?php print $title_attributes; ?>>
      <?php print $label; ?>:
    </span>
  <?php elseif ($element['#label_display'] == 'above'): ?>
    <h3 class="field-label"<?php print $title_attributes; ?>>
      <?php print $label; ?>
    </h3>
  <?php endif; ?>

  <?php foreach ($items as $delta => $item): ?>
    <div class="<?php print $classes; ?>"<?php print $attributes; ?>>
      <?php print render($item); ?>
    </div>
  <?php endforeach; ?>
<?php if (in_array($field_name_css, array('field-date', 'field-location'))): ?>
  </div>
<?php endif; ?>
