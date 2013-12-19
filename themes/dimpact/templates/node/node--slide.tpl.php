<?php

// We hide the comments and links now so that we can render them later.
hide($content['comments']);
hide($content['links']);
hide($content['field_image']);
hide($content['field_link']);

?>
<article<?php print $attributes; ?>>

<?php print render($content['field_image']); ?>
<?php print render($content['field_link']); ?>
 
</article>
