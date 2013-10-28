<?php

/**
 * Callback for the "add wiki page" breadcrumb action to generate the crumbs.
 *
 * @param array $arguments
 * @return array
 */
function bespoke_action_add_wiki_page_get_crumbs($arguments) {
  $crumbs = array();

  if (arg(0) == 'node' && is_numeric(arg(1)) && ($node = node_load(arg(1)))) {
    if ($node->title != variable_get('wikitools_main_page_title', 'Main Page')) {
      $crumbs[] = array(
        'title' => $node->title,
        'href' => arg(0) . '/' . arg(1),
      );
    }
  }

  return $crumbs;
}
