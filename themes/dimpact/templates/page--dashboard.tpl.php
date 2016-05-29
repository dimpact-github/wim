<?php
/**
 * @file
 * Output for main HTML page content.
 */

$header = render($page['header']);
$navigation = render($page['navigation']);
$help = render($page['help']);

$region_meta_first  = render($page['region_meta_first']);
$region_meta_second = render($page['region_meta_second']);

$region_full_top    = render($page['region_full_top']);

$region_93_first    = render($page['region_93_first']);
$region_93_second   = render($page['region_93_second']);

$region_39_first    = render($page['region_39_first']);
$region_39_second   = render($page['region_39_second']);

$region_363_first   = render($page['region_363_first']);
$content_top        = render($page['content_top']);
$content            = render($page['content']);
$content_bottom     = render($page['content_bottom']);
$region_363_third   = render($page['region_363_third']);

$region_444_first   = render($page['region_444_first']);
$region_444_second  = render($page['region_444_second']);
$region_444_third   = render($page['region_444_third']);

$region_footer_first   = render($page['region_footer_first']);
$region_footer_second  = render($page['region_footer_second']);
$region_footer_third   = render($page['region_footer_third']);

$region_full_bottom = render($page['region_full_bottom']);

$tabs = render($tabs);
$actions = count($action_links);
$action_links = render($action_links);
?>
<?php if ($region_meta_first || $region_meta_second): ?>
  <div class="container container-nopadding">
    <div class="region_meta_first">
      <?php print $region_meta_first; ?>
    </div>
    <div class="region_meta_second">
      <?php print $region_meta_second; ?>
    </div>
  </div>
<?php endif; ?>
<div id="main-wrapper">
  <header role="banner" id="header">

    <div class="container">
      <div class="branding">
        <div class="site-name">
          <h1 <?php if (theme_get_setting('hide_site_title', 'dimpact')): ?>class="hide-text"<?php endif; ?>>
            <a title="<?php print t('Home'); ?>" rel="home" href="<?php print $front_page; ?>" class="name"><?php print $site_name; ?></a>
          </h1>
          <?php if ($logo): ?>
            <a title="<?php print t('Home'); ?>" rel="home" href="<?php print $front_page; ?>" class="logo"><img src="<?php print $logo ?>" alt="<?php print $site_name ?> Logo"></a>
          <?php endif; ?>
        </div>
        <?php if ($site_slogan): ?>
          <h2 class="site-slogan"><?php print $site_slogan; ?></h2>
        <?php endif; ?>
      </div>
      <?php print $header; ?>
    </div>
  </header>
  <?php if ($navigation): ?>
    <nav role="navigation" class="main-menu">
      <div class="container container-nopadding">
        <?php print $navigation; ?>
      </div>
      <?php if ($breadcrumb): ?>
        <div class="container container-nopadding">
          <?php print $breadcrumb; ?>
        </div>
      <?php endif; ?>
    </nav>
  <?php endif; ?>

  <div class="main" id="main">

    <?php if ($messages): ?>
      <div class="container container-nopadding">
        <section class="console">
          <h2 class="visuallyhidden"><?php print t('Console'); ?></h2>
          <?php print $messages; ?>
        </section>
      </div>
    <?php endif; ?>

    <?php // Region 9/3 ?>
    <?php if ($region_93_first || $region_93_second): ?>
      <div class="container">
        <div class="region_93_first">
          <?php print $region_93_first; ?>
        </div>
        <div class="region_93_second">
          <?php print $region_93_second; ?>
        </div>
      </div>
    <?php endif; ?>

<!--    <div class="container">-->
      <?php print $content; ?>
<!--    </div>-->
    <?php /* if (!$hidecontent): ?>
      <div class="container">
        <div role="main" class="column-main">
          <div id="content">
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
          <?php // print $feed_icons; ?>
        </div>
      </div>
    <?php endif; */ ?>

  </div>

</div>

<?php if ($region_footer_first || $region_footer_second || $region_footer_third): ?>
  <footer role="contentinfo" id="footer">
    <div class="container">
      <div class="region_footer_first">
        <?php print $region_footer_first; ?>
      </div>
      <div class="region_footer_second">
        <?php print $region_footer_second; ?>
      </div>
      <div class="region_footer_third">
        <?php print $region_footer_third; ?>
      </div>
    </div>
  </footer>
<?php endif; ?>
