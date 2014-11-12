<?php

include(dirname(__FILE__) . '/default.settings.php');

$databases['default']['default'] = array(
  'driver' => 'mysql',
  'database' => '',
  'username' => '',
  'password' => '',
  'host' => '127.0.0.1',
  'prefix' => '',
  'collation' => 'utf8_general_ci',
);

// To enable memcache, uncomment the following lines.
// include_once('./includes/cache.inc');
// include_once('./sites/all/modules/contrib/memcache/memcache.inc');
// $conf['cache_default_class'] = 'MemCacheDrupal';
// $conf['memcache_key_prefix'] = 'dimpact';

include DRUPAL_ROOT . '/sites/all/modules/contrib/domain/settings.inc';
