<?php

/**
 * Admin form that allows configuring filtered words.
 * @return type
 */
function twitter_filter_words_admin() {
  $form = array();

  $twitter_filter = variable_get('twitter_filter_words');
  $form['twitter_filter_words'] = array(
    '#type' => 'textarea',
    '#title' => t('Words to filter'),
    '#description' => t('The words to filter in Tweets. Seperate words with a "," (without quotes). The input is case insensitive.'),
    '#default_value' => isset($twitter_filter) ? $twitter_filter : '',
  );

  return system_settings_form($form);
}

/**
 * Form to create a new Tweet block.
 * @param type $form
 * @param type $form_state
 * @return string
 */
function twitter_filter_words_add_block($form, &$form_state) {
  module_load_include('inc', 'block', 'block.admin');
  $form = block_admin_configure($form, $form_state, 'twitter_filter_words', NULL);

  $form['#validate'] = array('_twitter_filter_words_add_block_validate');
  $form['#submit'] = array('_twitter_filter_words_add_block_submit');

  return $form;
}

/**
 * Implements hook_block_configure.
 * Loads the configure form for Tweet blocks.
 * @param type $delta
 * @return type
 */
function _twitter_filter_words_block_configure($delta = '') {
  $arg0 = arg(0);
  if ($arg0 === 'admin') {
    $form_state = array('values' => _twitter_filter_words_config($delta));
    return _twitter_filter_words_configure_form(array(), $form_state);
  }
}

/**
 * Retrieve the config for the given block.
 * Returns empty array if not available.
 * @param type $delta
 * @return type
 */
function _twitter_filter_words_config($delta = NULL) {
  $config = array(
    'delta' => $delta,
    'tfw_tweet_key' => '',
    'tfw_number_of_items' => '',
    'tfw_show_rts' => 0,
    'tfw_show_replies' => 0,
    'title' => '',
  );

  if ($delta) {
    $config['delta'] = $delta;
    $config['tfw_tweet_key'] =  variable_get("twitter_filter_words_block_{$delta}_tweet_key", $config['tfw_tweet_key']);
    $config['tfw_number_of_items'] = variable_get("twitter_filter_words_block_{$delta}_number_items", $config['tfw_number_of_items']);
    $config['tfw_show_rts'] = variable_get("twitter_filter_words_block_{$delta}_show_rts", $config['tfw_show_rts']);
    $config['tfw_show_replies'] = variable_get("twitter_filter_words_block_{$delta}_show_replies", $config['tfw_show_replies']);
    $config['title'] = variable_get("twitter_filter_words_block_{$delta}_title", $config['title']);
  }

  return $config;
}

/**
 * Admin form for adding and configuring new Twitter blocks.
 * @return string
 */
function _twitter_filter_words_add_block($form, &$form_state) {
  module_load_include('inc', 'block', 'block.admin');
  $form = block_admin_configure($form, $form_state, 'twitter_filter_words', NULL);

  $form['#validate'] = array('_twitter_filter_words_add_block_validate');
  $form['#submit'] = array('_twitter_filter_words_add_block_submit');

  return $form;
}

/**
 * Block configuration form.
 * @param type $form
 * @param type $form_state
 * @return type
 */
function _twitter_filter_words_configure_form($form, &$form_state) {
  $config = $form_state['values'];
  
  $form['twitter_filter_block'] = array(
    '#type' => 'fieldset',
    '#title' => t('Twitter block'),
    '#tree' => TRUE,
  );
  $form['twitter_filter_block']['tfw_tweet_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter block hashtag/account'),
    '#size' => 50,
    '#description' => t('Define the hashtag (use #) or account (use @) to use for retrieving tweets.'),
    '#required' => TRUE,
    '#default_value' => isset($config['tfw_tweet_key']) ? $config['tfw_tweet_key'] : ''
  );
  $form['twitter_filter_block']['tfw_number_of_items'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter block maximum tweets'),
    '#size' => 5,
    '#description' => t('<strong>The MAXIMUM amount of Tweets to display. The amount of tweets displayed can be less depending on the number of filtered tweets.</strong>'),
    '#default_value' => isset($config['tfw_number_of_items']) ? $config['tfw_number_of_items'] : 5,
    '#required' => TRUE,
  );
  $form['twitter_filter_block']['tfw_show_rts'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show retweets in this feed?'),
    '#description' => t('Show retweets in this feed.'),
    '#default_value' => isset($config['tfw_show_rts']) ? $config['tfw_show_rts'] : 0,
  );
  $form['twitter_filter_block']['tfw_show_replies'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show replies to other tweets in this feed?'),
    '#description' => t('Show replies to other tweets in this feed.'),
    '#default_value' => isset($config['tfw_show_replies']) ? $config['tfw_show_replies'] : 0,
  );

  return $form;
}

/**
 * Validate block creation before saving.
 * @param type $form
 * @param type $form_state
 */
function _twitter_filter_words_add_block_validate($form, &$form_state) {
  if (!empty($form_state['values']['twitter_filter_block']['tfw_tweet_key']) && strpos($form_state['values']['twitter_filter_block']['tfw_tweet_key'], '@') === FALSE && strpos($form_state['values']['twitter_filter_block']['tfw_tweet_key'], '#') === FALSE) {
    form_set_error('twitter_filter_block][tfw_tweet_key', t('You need to use a @ for accounts or a # for hashtags.'));
  }
}

/**
 * Write values to the database.
 * @param type $form
 * @param type $form_state
 */
function _twitter_filter_words_add_block_submit($form, &$form_state) {
  // Determine the delta of the new block.
  $block_ids = variable_get('twitter_filter_words_block_ids', array());
  $delta = empty($block_ids) ? 1 : max($block_ids) + 1;
  $form_state['values']['delta'] = $delta;

  // Save the new array of blocks IDs.
  $block_ids[] = $delta;
  variable_set('twitter_filter_words_block_ids', $block_ids);

  // Save the block configuration.
  twitter_filter_words_block_save($delta, $form_state['values']);

  // Run the normal new block submission (borrowed from block_add_block_form_submit).
  $query = db_insert('block')->fields(array('visibility', 'pages', 'custom', 'title', 'module', 'theme', 'region', 'status', 'weight', 'delta', 'cache'));
  foreach (list_themes() as $key => $theme) {
    if ($theme->status) {
      $region = !empty($form_state['values']['regions'][$theme->name]) ? $form_state['values']['regions'][$theme->name] : BLOCK_REGION_NONE;
      $query->values(array(
        'visibility' => (int) $form_state['values']['visibility'],
        'pages' => trim($form_state['values']['pages']),
        'custom' => (int) $form_state['values']['custom'],
        'title' => $form_state['values']['title'],
        'module' => $form_state['values']['module'],
        'theme' => $theme->name,
        'region' => ($region == BLOCK_REGION_NONE ? '' : $region),
        'status' => 0,
        'status' => (int) ($region != BLOCK_REGION_NONE),
        'weight' => 0,
        'delta' => $delta,
        'cache' => DRUPAL_NO_CACHE,
      ));
    }
  }
  $query->execute();

  $query = db_insert('block_role')->fields(array('rid', 'module', 'delta'));
  foreach (array_filter($form_state['values']['roles']) as $rid) {
    $query->values(array(
      'rid' => $rid,
      'module' => $form_state['values']['module'],
      'delta' => $delta,
    ));
  }
  $query->execute();

  drupal_set_message(t('The block has been created.'));
  $form_state['redirect'] = 'admin/structure/block';
}

/**
 * Save the variables for this block to the database.
 * Uses the variables available in Drupal.
 * @param type $delta
 * @param type $edit
 */
function _twitter_filter_words_block_save($delta, $edit) {
  variable_set("twitter_filter_words_block_{$delta}_tweet_key", $edit['twitter_filter_block']['tfw_tweet_key']);
  variable_set("twitter_filter_words_block_{$delta}_number_items", $edit['twitter_filter_block']['tfw_number_of_items']);
  variable_set("twitter_filter_words_block_{$delta}_title", (!empty($edit['title']) ? $edit['title'] : $edit['twitter_filter_block']['tfw_tweet_key']));
  variable_set("twitter_filter_words_block_{$delta}_show_rts", (!empty($edit['show_rts']) ? $edit['show_rts'] : $edit['twitter_filter_block']['tfw_show_rts']));
  variable_set("twitter_filter_words_block_{$delta}_show_replies", (!empty($edit['tfw_show_replies']) ? $edit['tfw_show_replies'] : $edit['twitter_filter_block']['tfw_show_replies']));

  // Clear the cache after saving new configs.
  db_truncate(TWITTER_PULL_CACHE_TABLE)->execute();
  cache_clear_all();
}
