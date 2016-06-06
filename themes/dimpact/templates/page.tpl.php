<?php
/**
 * @file
 * Output for main HTML page content.
 */
$header = render($page['header']);
$navigation = render($page['navigation']);
$help = render($page['help']);

$region_meta_first = render($page['region_meta_first']);
$region_meta_second = render($page['region_meta_second']);

$region_full_top = render($page['region_full_top']);

$region_93_first = render($page['region_93_first']);
$region_93_second = render($page['region_93_second']);

$region_39_first = render($page['region_39_first']);
$region_39_second = render($page['region_39_second']);

$region_363_first = render($page['region_363_first']);
$content_top = render($page['content_top']);
$content = render($page['content']);
$region_39_content = render($page['region_39_content']);
$content_bottom = render($page['content_bottom']);
$region_363_third = render($page['region_363_third']);
$region_d = render($page['region_d']);

$region_444_first = render($page['region_444_first']);
$region_444_second = render($page['region_444_second']);
$region_444_third = render($page['region_444_third']);

$region_84_first = render($page['region_84_first']);
$region_84_second = render($page['region_84_second']);

$region_48_first = render($page['region_48_first']);
$region_48_second = render($page['region_48_second']);

$region_444_2_first = render($page['region_444_2_first']);
$region_444_2_second = render($page['region_444_2_second']);
$region_444_2_third = render($page['region_444_2_third']);

$region_444_3_first = render($page['region_444_3_first']);
$region_444_3_second = render($page['region_444_3_second']);
$region_444_3_third = render($page['region_444_3_third']);

$region_444_4_first = render($page['region_444_4_first']);
$region_444_4_second = render($page['region_444_4_second']);
$region_444_4_third = render($page['region_444_4_third']);

$region_444_5_first = render($page['region_444_5_first']);
$region_444_5_second = render($page['region_444_5_second']);
$region_444_5_third = render($page['region_444_5_third']);

$region_444_6_first = render($page['region_444_6_first']);
$region_444_6_second = render($page['region_444_6_second']);
$region_444_6_third = render($page['region_444_6_third']);

$region_content_full_bottom = render($page['region_content_full_bottom']);

$region_footer_first = render($page['region_footer_first']);
$region_footer_second = render($page['region_footer_second']);
$region_footer_third = render($page['region_footer_third']);

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
            <div class="site-name">
              <h1 <?php if (theme_get_setting('hide_site_title', 'dimpact')): ?>class="hide-text"<?php endif; ?>>
                <a title="<?php print t('Home'); ?>" rel="home" href="<?php print $front_page; ?>" class="name"><?php print $site_name; ?></a>
              </h1>
              <?php if ($logo): ?>
                <a title="<?php print t('Home'); ?>" rel="home" href="<?php print $front_page; ?>" class="logo"><img src="<?php print $logo ?>" alt="<?php print $site_name ?> Logo"></a>
              <?php endif; ?>
            </div>
            <?php /* if ($site_slogan): ?>
              <h2 class="site-slogan"><?php print $site_slogan; ?></h2>
              <?php endif; */ ?>
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
              <?php print $breadcrumb; ?>
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

    <?php // Region 12/12 top  ?>
    <?php if ($region_full_top): ?>
    <div class="rowcontainer row01container">
      <div class="container grid12 row01">
        <div class="region_full_top">
          <?php print $region_full_top; ?>
        </div>
      </div>
    </div>
    <?php endif; ?>

    <?php // Region 9/3  ?>
    <?php if ($region_93_first || $region_93_second): ?>
    <div class="rowcontainer row02container">
      <div class="container grid84 row02">
        <div class="region_93_first">
          <?php print $region_93_first; ?>
        </div>
        <div class="region_93_second">
          <?php print $region_93_second; ?>
        </div>
      </div>
    </div>
    <?php endif; ?>

    <?php // Region 3/9  ?>
    <?php if ($region_39_first || $region_39_second || (in_array($pagetype, array('searchpage', 'node-add-page', 'bekendmakingen', 'bestemmingsplannen', 'fotoalbum', 'forum')) && $content)): ?>
    <div class="rowcontainer row03container">  
      <div class="container grid39 row03">
        <div class="region_39_first">
          <?php print $region_39_first; ?>
        </div>
        <div class="region_39_second">
          <?php if (in_array($pagetype, array('searchpage', 'node-add-page', 'bekendmakingen', 'bestemmingsplannen', 'fotoalbum', 'forum'))): ?>
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
            <?php if ($title): ?>
              <h1 class="title" id="page-title"><?php print $title; ?></h1>
            <?php endif; ?>
            <?php print $content; ?>
          <?php endif; ?>
          <?php print $region_39_second; ?>
        </div>
      </div>
    </div>
    <?php endif; ?>

    <?php // Region 3/6/3  ?>
    <?php if (!$hidecontent): ?>
      <div class="rowcontainer row04container">
        <div class="container grid354 row04">
          <div role="main" class="column-main">
            <div id="content">
              <div class="content-inner">
                <?php print render($title_prefix); ?>
                <?php if ($title && !empty($content)): ?>
                  <h1 class="title" id="page-title"><?php print $title; ?></h1>
                <?php endif; ?>
                <?php print render($title_suffix); ?>
                <?php print $help; ?>
                <?php print $content_top; ?>
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
              <div class="region_363_third">
                <?php print $region_363_third; ?>
              </div>
              <?php print $region_39_content; ?>
              <div class="region-content-bottom-wrapper">
                <?php print $content_bottom; ?>
                <?php print $region_d; ?>
              </div>
            </div>
            <?php // print $feed_icons;  ?>
          </div>

          <?php if ($region_363_first): ?>
            <div class="region_363_first">
              <?php print $region_363_first; ?>
            </div>
          <?php endif; ?>

          <?php if ($region_363_third): ?>
            <div class="region_363_third">
              <?php print $region_363_third; ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php // Region 4/4/4 bottom  ?>
    <?php if ($region_444_first || $region_444_second || $region_444_third): ?>
      <div class="rowcontainer row05container">
        <div class="container grid444 row05">
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
      </div>
    <?php endif; ?>

    <?php // Region 4/4/4 2  ?>
    <?php if ($region_444_2_first || $region_444_2_second || $region_444_2_third): ?>
      <div class="rowcontainer row06container">
        <div class="container grid444 row06">
          <div class="region_444_2_first">
            <?php print $region_444_2_first; ?>
          </div>
          <div class="region_444_2_second">
            <?php print $region_444_2_second; ?>
          </div>
          <div class="region_444_2_third">
            <?php print $region_444_2_third; ?>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <?php // Region 8/4   ?>
    <?php if ($region_84_first || $region_84_second): ?>
      <div class="rowcontainer row07container">
        <div class="container grid84 row07">
          <div class="region_84_first">
            <?php print $region_84_first; ?>
          </div>
          <div class="region_84_second">
            <?php print $region_84_second; ?>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <?php // Region 4/4/4 3  ?>
    <?php if ($region_444_3_first || $region_444_3_second || $region_444_3_third): ?>
      <div class="rowcontainer row08container">
        <div class="container grid444 row08">
          <div class="region_444_3_first">
            <?php print $region_444_3_first; ?>
          </div>
          <div class="region_444_3_second">
            <?php print $region_444_3_second; ?>
          </div>
          <div class="region_444_3_third">
            <?php print $region_444_3_third; ?>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <?php // Region 12/12 bottom content  ?>
    <?php if ($region_content_full_bottom): ?>
      <div class="rowcontainer row09container">
        <div class="container grid12 row09">
          <div class="region_content_full_bottom">
            <?php print $region_content_full_bottom; ?>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <?php // Region 4/4/4 4  ?>
    <?php if ($region_444_4_first || $region_444_4_second || $region_444_4_third): ?>
      <div class="rowcontainer row10container">
        <div class="container grid444 row10">
          <div class="region_444_4_first">
            <?php print $region_444_4_first; ?>
          </div>
          <div class="region_444_4_second">
            <?php print $region_444_4_second; ?>
          </div>
          <div class="region_444_4_third">
            <?php print $region_444_4_third; ?>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <?php // Region 4/8  ?>
    <?php if ($region_48_first || $region_48_second): ?>
      <div class="rowcontainer row11container">
        <div class="container grid48 row11">
          <div class="region_48_first">
            <?php print $region_48_first; ?>
          </div>
          <div class="region_48_second">
            <?php print $region_48_second; ?>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <?php // Region 4/4/4 5  ?>
    <?php if ($region_444_5_first || $region_444_5_second || $region_444_5_third): ?>
      <div class="rowcontainer row12container">
        <div class="container grid444 row12">
          <div class="region_444_5_first">
            <?php print $region_444_5_first; ?>
          </div>
          <div class="region_444_5_second">
            <?php print $region_444_5_second; ?>
          </div>
          <div class="region_444_5_third">
            <?php print $region_444_5_third; ?>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <?php // Region 4/4/4 6  ?>
    <?php if ($region_444_6_first || $region_444_6_second || $region_444_6_third): ?>
      <div class="rowcontainer row13container">
        <div class="container grid444 row13">
          <div class="region_444_6_first">
            <?php print $region_444_6_first; ?>
          </div>
          <div class="region_444_6_second">
            <?php print $region_444_6_second; ?>
          </div>
          <div class="region_444_6_third">
            <?php print $region_444_6_third; ?>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <?php // Region 12/12 bottom  ?>
    <?php if ($region_full_bottom): ?>
    <div class="rowcontainer row14container">
      <div class="container container-nopadding grid12 row14">
        <div class="region_full_bottom">
          <?php print $region_full_bottom; ?>
        </div>
      </div>
    </div>
    <?php endif; ?>

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
