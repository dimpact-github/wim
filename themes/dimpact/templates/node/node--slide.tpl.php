<?php

// We hide the comments and links now so that we can render them later.
hide($content['comments']);
hide($content['links']);
hide($content['field_image']);
hide($content['field_link']);

?>
<article<?php print $attributes; ?>>
  <?php if ($content['field_link']['#items']): ?>
    <?php
      print l(
        strip_tags(render($content['field_image']), '<img>'),
        $content['field_link']['#items'][0]['url'], array(
          'html' => TRUE
        )
      );
    ?>
  <?php else: ?>
    <?php print render($content['field_image']); ?>
  <?php endif; ?>
</article>
