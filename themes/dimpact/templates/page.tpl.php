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

$region_84_first    = render($page['region_84_first']);
$region_84_second   = render($page['region_84_second']);

$region_39_first    = render($page['region_39_first']);
$region_39_second   = render($page['region_39_second']);

$region_354_first   = render($page['region_354_first']);
$content_top        = render($page['content_top']);
$content            = render($page['content']);
$content_bottom     = render($page['content_bottom']);
$region_354_third   = render($page['region_354_third']);

$region_444_first   = render($page['region_444_first']);
$region_444_second  = render($page['region_444_second']);
$region_444_third   = render($page['region_444_third']);

$region_full_bottom = render($page['region_full_bottom']);

$tabs = render($tabs);
$actions = count($action_links);
$action_links = render($action_links);

?>
<?php if ($messages): ?>
  <section class="console">
    <h2 class="visuallyhidden"><?php print t('Console'); ?></h2>
    <?php print $messages; ?>
  </section>
<?php endif; ?>

<?php if ($region_meta_first || $region_meta_second): ?>
  <div class="container">
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
      <hgroup class="branding">
        <?php if ($site_name): ?>
          <h1 class="site-name">
            <?php if ($logo): ?>
              <a title="<?php print t('Home'); ?>" rel="home" href="<?php print $front_page; ?>" class="logo"><img src="<?php print $logo ?>" alt="<?php print $site_name ?> Logo"></a>
            <?php else: ?>
            <a title="<?php print t('Home'); ?>" rel="home" href="<?php print $front_page; ?>"><?php print $site_name; ?></a>
            <?php endif; ?>
          </h1>
        <?php endif; ?>
        <?php if ($site_slogan): ?>
          <h2 class="site-slogan"><?php print $site_slogan; ?></h2>
        <?php endif; ?>
      </hgroup>
      <?php print $header; ?>
    </div>
  </header>
  <?php if ($navigation): ?>
    <nav role="navigation" class="main-menu">
      <div class="container">
        <h2 class="visuallyhidden"><?php print t('Main menu'); ?></h2>
        <?php print $navigation; ?>
      </div>
    </nav>
  <?php endif; ?>

  <div class="main" id="main">

    <?php // Region 12/12 top ?>
    <div class="container">
      <div class="region_full_top">
        <?php print $region_full_top; ?>
      </div>
    </div>

    <?php // Region 8/4 ?>
    <div class="container">
      <div class="region_84_first">
        <?php print $region_84_first; ?>
      </div>
      <div class="region_84_second">
        <?php print $region_84_second; ?>
      </div>
    </div>

    <?php // Region 3/9 ?>
    <div class="container">
      <div class="region_39_first">
        <?php print $region_39_first; ?>
      </div>
      <div class="region_39_second">
        <?php print $region_39_second; ?>
      </div>
    </div>

    <?php // Region 3/5/4 ?>
    <div class="container">
      <div class="region_354_first">
        <?php print $region_354_first; ?>
      </div>
      <div role="main" class="column-main">
        <?php // print $breadcrumb; ?>
        <div id="content">
          <?php print render($title_prefix); ?>
          <?php if ($title): ?>
            <h1 class="title" id="page-title"><?php print $title; ?></h1>
          <?php endif; ?>
          <?php print render($title_suffix); ?>
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
          <?php // print $help; ?>
          <?php print $content_top; ?>
          <?php print $content; ?>
          <?php print $content_bottom; ?>
        </div>
        <?php // print $feed_icons; ?>
      </div>
      <div class="region_354_third">
        <?php print $region_354_third; ?>
      </div>
    </div>

    <?php // Region 4/4/4 bottom ?>
    <div class="container">
      <div class="region_444_first">
        <?php print $region_444_first; ?>
      </div>
      <div class="region_444_second">
        <?php print $region_444_second; ?>
      </div>
      <div class="region_444_third">
        <?php print $region_444_third; ?>
      </div>
    </div>

    <?php // Region 12/12 bottom ?>
    <div class="container">
      <div class="region_full_bottom">
        <?php print $region_full_bottom; ?>
      </div>
    </div>

  </div>
  <footer role="contentinfo" id="footer">
    <div class="container">
      <?php // print $footer; ?>
    </div>
  </footer>
</div>
