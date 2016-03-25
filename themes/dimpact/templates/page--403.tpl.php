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

$region_subfooter_first = render($page['region_subfooter_first']);
$region_subfooter_second = render($page['region_subfooter_second']);

$region_full_bottom = render($page['region_full_bottom']);

$tabs = render($tabs);
$actions = count($action_links);
$action_links = render($action_links);

$readspeaker_status = variable_get('bespoke_readspeaker_status', 0);
$readspeaker_id = variable_get('bespoke_readspeaker_id', 0);
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
  <div class="headercontainer-wrapper">
    <div class="headercontainer">
  <header role="banner" id="header">

    <div class="container">
      <div class="branding">
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
      </div>
      <?php print $header; ?>
    </div>
  </header>
  <?php if ($navigation): ?>
    <nav role="navigation" class="main-menu">
          <div class="container container-nopadding navigation">
        <?php print $navigation; ?>
      </div>
          <div class="container container-nopadding navigation-bottom">
      <?php if ($breadcrumb): ?>
        <div class="container container-nopadding">
          <?php print $breadcrumb; ?>
        </div>
      <?php endif; ?>
      <?php if ($readspeaker_status == 1): ?>
        <div id="readspeaker_button1" class="rs_skip rsbtn rs_preserve">
          <a class="rsbtn_play" title="<?php print t('Laat de tekst voorlezen met ReadSpeaker'); ?>" href="//app.readspeaker.com/cgi-bin/rsent?customerid=<?php print $readspeaker_id; ?>&amp;lang=nl_nl&amp;readid=main&amp;url=<?php echo urlencode($_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']); ?>">
            <span class="rsbtn_left rsimg rspart"><span class="rsbtn_text"><span><?php print t('Lees voor'); ?></span></span></span>
            <span class="rsbtn_right rsimg rsplay rspart"></span>
          </a>
        </div>
      <?php endif; ?>
          </div>
    </nav>
  <?php endif; ?>

      <a id="main-content" tabindex="-1"></a>
    </div>
  </div>
  <div class="main" id="main">

    <?php if ($messages): ?>
      <div class="container container-nopadding">
        <section class="console">
          <h2 class="visuallyhidden"><?php print t('Console'); ?></h2>
          <?php print $messages; ?>
        </section>
      </div>
    <?php endif; ?>

    <div class="container">
      <div class="region_full_top">
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
      </div>
    </div>

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

<?php if ($region_subfooter_first || $region_subfooter_second): ?>
  <div class="subfootercontainer">
      <div class="container">
          <div class="region_subfooter_first">
            <?php print $region_subfooter_first; ?>
          </div>
          <div class="region_subfooter_second">
            <?php print $region_subfooter_second; ?>
          </div>
      </div>
  </div>
<?php endif; ?>
