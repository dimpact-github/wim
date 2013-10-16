<!DOCTYPE html>
<html<?php print $html_attributes; ?>>
<head>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <link rel="dns-prefetch" href="//themes.googleusercontent.com">
  <link rel="dns-prefetch" href="//fonts.googleapis.com">
  <?php print $styles; ?>
  <link rel="stylesheet" href="http://fonts.googleapis.com/css?family=Droid+Sans:400,700|Roboto+Slab:400,700" media="screen" />
  <?php print $scripts; ?>
  <!--[if lt IE 9]>
  <link rel="stylesheet" href="/<?php print $path; ?>/css/lte-ie9.css" media="all">
  <script src="/<?php print $path; ?>/js/libraries/html5shiv/src/html5shiv.js"></script>
  <script src="/<?php print $path; ?>/js/libraries/respond.min.js"></script>
  <![endif]-->
</head>
<body class="maintenance-page">

  <div id="main-wrapper">
    <header role="banner" id="header">

      <div class="container">
        <hgroup class="branding">
          <?php if ($site_name): ?>
            <h1 class="site-name">
              <?php if ($logo): ?>
                <a title="<?php print t('Home'); ?>" rel="home" href="<?php print $front_page; ?>" class="logo"><img src="<?php print $logo ?>" alt="<?php print $site_name ?> Logo"></a>
              <?php endif; ?>
              <a title="<?php print t('Home'); ?>" rel="home" href="<?php print $front_page; ?>"><?php print $site_name; ?></a>
            </h1>
          <?php endif; ?>
          <?php if ($site_slogan): ?>
            <h2 class="site-slogan"><?php print $site_slogan; ?></h2>
          <?php endif; ?>
        </hgroup>
        <?php print $header; ?>
      </div>
    </header>

    <div class="main" id="main">

      <div class="container">
        <div role="main" class="column-main">
            <?php print render($title_prefix); ?>
            <?php if ($title && !empty($content)): ?>
              <h1 class="title" id="page-title"><?php print $title; ?></h1>
            <?php endif; ?>
            <?php print render($title_suffix); ?>
            <?php print $help; ?>
            <?php if ($tabs || $action_links): ?>
              <div class="tasks">
                <?php print $tabs; ?>
                <?php if ($action_links): ?>
                  <div class="actions actions-<?php print ($actions == 1) ? 'single' : 'multiple'; ?>">
                    <div class="wrap">
                      <h2><?php print t('Page actions'); ?></h2>
                      <ul class="action-links">
                        <?php print $action_links; ?>
                      </ul>
                    </div>
                  </div>
                <?php endif; ?>
              </div>
            <?php endif; ?>
            <?php print $content; ?>
        </div>
      </div>

    </div>

  </div>

</body>
</html>
