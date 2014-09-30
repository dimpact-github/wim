<?php
/**
 * @file field--fences-divh2.tpl.php
 * Wrap each field value in the <div> element.
 *
 * Customizations:
 *  - $heading: When view mode is 'full' it's <h2>, otherwise, it's <h3>.
 *
 * @see http://developers.whatwg.org/grouping-content.html#the-div-element
 */
?>
<div class="field-wrapper field-wrapper-<?php print drupal_html_class($element['#field_name']); ?>">
  <?php if ($element['#label_display'] == 'inline'): ?>
    <span class="field-label"<?php print $title_attributes; ?>>
      <?php print $label; ?>:
    </span>
  <?php elseif ($element['#label_display'] == 'above'): ?>
    <<?php print $heading ?> class="field-label"<?php print $title_attributes; ?>>
      <?php print $label; ?>
    </<?php print $heading ?>>
  <?php endif; ?>

  <?php foreach ($items as $delta => $item): ?>
    <div<?php print $attributes; ?>>
      <?php print render($item); ?>
      <?php if (isset($files[$delta]) && !empty($files[$delta])): ?>
        <div class="ris-attachments">
          <?php print render($files[$delta]); ?>
        </div>
      <?php endif; ?>
    </div>
  <?php endforeach; ?>
</div>
