<?php
/**
 * @file
 * dimpact_content_types.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function dimpact_content_types_taxonomy_default_vocabularies() {
  return array(
    'faq_categories' => array(
      'name' => 'FAQ categorieën',
      'machine_name' => 'faq_categories',
      'description' => 'Categorieën voor de veelgestelde vragen pagina',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
