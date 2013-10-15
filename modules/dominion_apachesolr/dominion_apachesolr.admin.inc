<?php

function dominion_apachesolr_admin_settings($form, &$form_state) {
  $form = array();

  $form[DOMINION_APACHESOLR_VAR_FIELD_DOMAIN_ID] = array(
    '#type' => 'textfield',
    '#title' => t('Solr domain id field'),
    '#default_value' => variable_get(DOMINION_APACHESOLR_VAR_FIELD_DOMAIN_ID, DOMINION_APACHESOLR_VAR_FIELD_DOMAIN_ID_DEFAULT),
    '#description' => t('Name for field in solr schema.xml where the domain ids are stored.'),
  );

  $form[DOMINION_APACHESOLR_VAR_FIELD_DOMAIN_SITE] = array(
    '#type' => 'textfield',
    '#title' => t('Solr domain site field'),
    '#default_value' => variable_get(DOMINION_APACHESOLR_VAR_FIELD_DOMAIN_SITE, DOMINION_APACHESOLR_VAR_FIELD_DOMAIN_SITE_DEFAULT),
    '#description' => t('Name for field in solr schema.xml where the domain site value is stored.'),
  );

  $sql = 'SELECT domain_id, sitename
  FROM {domain}
  ORDER BY sitename ASC';
  $res = db_query($sql);
  $options = array();
  while ($domain = $res->fetchObject()) {
    if ($domain->domain_id == 0) $domain->domain_id = -1;
    $options[$domain->domain_id] = $domain->sitename;
  }
  $form[DOMINION_APACHESOLR_VAR_MAIN_SEARCH_DOMAINS] = array(
    '#type' => 'checkboxes',
    '#title' => t('Include these domains in the search result when not on a Dominion subsite'),
    '#default_value' => variable_get(DOMINION_APACHESOLR_VAR_MAIN_SEARCH_DOMAINS, array()),
    '#options' => $options,
    '#description' => t('Include these additional domains in the search results. The current domainis always included and thus not listed in this setting.'),
  );

  return system_settings_form($form);
}
