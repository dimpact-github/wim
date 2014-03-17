<?php

/**
 * Node block theming.
 *
 * This template is called when nodes are placed in a block via felix.
 *
 * Use felix-node--NODETYPE.tpl.php for type specific theming.
 *
 * Available variables:
 * - $node: Loaded node object
 * - $content: Content array (objects selected by felix)
 * - $full_content: Content array for full node teaseer
 * - $view_mode: The view mode for this node
 */

?>

<?php print drupal_render($content); ?>