<?php

/**
 * @file
 * Theme template for a list of tweets.
 *
 * Available variables in the theme include:
 *
 * 1) An array of $tweets, where each tweet object has:
 *   $tweet->id
 *   $tweet->username
 *   $tweet->userphoto
 *   $tweet->text
 *   $tweet->timestamp
 *   $tweet->time_ago
 *
 * 2) $twitkey string containing initial keyword.
 *
 * 3) $title
 *
 */
?>
<?php if ($lazy_load): ?>
  <?php print $lazy_load; ?>
<?php else: ?>

<div class="tweets-pulled-listing">
  <?php if (!empty($title)): ?>
    <h2><?php print $title; ?></h2>
  <?php endif; ?>

  <?php if (is_array($tweets)): ?>
    <?php $tweet_count = count($tweets); ?>
    <ul class="tweets-pulled-listing">
    <?php _twitter_filter_words_process_filter($tweets); ?>
    <?php foreach ($tweets as $tweet_key => $tweet): ?>
      <li>
        <div class="tweet-author-wrapper clearfix">
          <div class="tweet-author-info clearfix">
            <div class="tweet-authorphoto">
              <?php print l("<img src='" . $tweet->userphoto . "' alt='" . $tweet->username . "' />",
                  'http://twitter.com/' . $tweet->screenname,
                  array('html' => TRUE, 'external' => TRUE, 'attributes' => array('target' => '_blank'))); ?>
            </div>
            <div class="tweet-author"><?php print l($tweet->username,
                'http://twitter.com/' . $tweet->screenname,
                array('external' => TRUE, 'attributes' => array('target' => '_blank'))); ?></div>
          </div>
        </div>
        <div class="tweet-text"><?php print twitter_pull_add_links($tweet->text); ?></div>
        <?php if ($tweet_key < $tweet_count - 1): ?>
          <div class="tweet-divider"></div>
        <?php endif; ?>
      </li>
    <?php endforeach; ?>
    </ul>
    <div class="more-link">
      <span>
        <?php if (function_exists('_twitter_filter_words_more_link')): ?>
          <?php print _twitter_filter_words_more_link($twitkey); ?>
        <?php else: ?>
          <?php print $twitkey; ?>
        <?php endif; ?>
      </span>
    </div>
  <?php endif; ?>
</div>
<?php endif;
