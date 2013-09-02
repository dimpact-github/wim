<?php

// We hide the comments and links now so that we can render them later.
hide($content['comments']);
hide($content['links']);
hide($content['field_image']);

?>
<article<?php print $attributes; ?>>
  <?php print render($content['field_image']); ?>
  <?php print render($title_prefix); ?>
  <?php if ($page): /* ?>
    <h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
  <?php */ else: ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($display_submitted || !empty($content['field_tags'])): ?>
    <?php // print $user_picture; ?>
    <?php // print render($content['field_tags']); ?>
  <?php endif; ?>
  <div class="content"<?php print $content_attributes; ?>>
    <?php if ($node->type == 'news'): ?>
      <time datetime="<?php print $timestamp; ?>">
        <span class="day-month-year"><?php print format_date($node->created, 'custom', 'd F Y'); ?></span>
      </time>
    <?php endif; ?>
    <?php print render($content); ?>
  </div>
  <?php // print render($content['links']); ?>
  <?php print render($content['comments']); ?>
</article>
