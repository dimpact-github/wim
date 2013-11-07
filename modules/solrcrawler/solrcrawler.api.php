<?php

/**
 * Implements hook_solrcrawler_document_alter().
 * 
 * Alter a document before indexing.
 * 
 * @param ApacheSolrDocument $document
 */
function hook_solrcrawler_document_alter(ApacheSolrDocument &$document) {
  $document->addField('foo', 'bar');
}
