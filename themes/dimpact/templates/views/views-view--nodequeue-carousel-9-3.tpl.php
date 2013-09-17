<?php
/**
 * @file views-view.tpl.php
 * Main view template
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<<?php print $tag; ?> class="<?php print $classes; ?>">
<?php print render($title_prefix); ?>
<?php print $title; ?>
<?php print render($title_suffix); ?>
<?php print $header; ?>
<?php if ($exposed): ?>
  <div class="view-filters">
    <?php print $exposed; ?>
  </div>
<?php endif; ?>
<?php print $attachment_before; ?>
<div class="views-rows">
  <?php print $rows; ?>
</div>
<div class="progress"></div>
<!--<a href="#" class="btn_play_pause">Afspelen</a>-->
<a href="#" class="btn_prev"><span class="icon-chevron-sign-left"></span></a>
<!--<div class="pager"></div>-->
<a href="#" class="btn_next"><span class="icon-chevron-sign-right"></span></a>
<?php print $empty; ?>
<?php print $pager; ?>
<?php print $attachment_after; ?>
<?php print $footer; ?>
<?php print $more; ?>
<?php if ($feed_icon): ?>
  <div class="feed-icon">
    <?php print $feed_icon; ?>
  </div>
<?php endif; ?>
</<?php print $tag; ?>>