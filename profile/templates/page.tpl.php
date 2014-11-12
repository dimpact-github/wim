<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en" dir="ltr">
  <head>
    <title>Installatie Dimpact distributie</title>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<link rel="shortcut icon" href="misc/favicon.ico" type="image/vnd.microsoft.icon" />
<meta name="Generator" content="Drupal 7 (http://drupal.org)" />
<meta name="robots" content="noindex, nofollow" />
    <style type="text/css" media="all">@import url("modules/system/system.base.css?0");
@import url("modules/system/system.admin.css?0");
@import url("modules/system/system.menus.css?0");
@import url("modules/system/system.messages.css?0");
@import url("modules/system/system.theme.css?0");
@import url("modules/system/system.maintenance.css?0");</style>
<style type="text/css" media="screen">@import url("themes/seven/reset.css?0");
@import url("themes/seven/style.css?0");</style>

<!--[if lte IE 8]>
<link type="text/css" rel="stylesheet" href="themes/seven/ie.css?0" media="all" />
<![endif]-->

<!--[if lte IE 7]>
<link type="text/css" rel="stylesheet" href="themes/seven/ie7.css?0" media="all" />
<![endif]-->

<!--[if lte IE 6]>
<link type="text/css" rel="stylesheet" href="themes/seven/ie6.css?0" media="all" />
<![endif]-->
    <script type="text/javascript" src="misc/jquery.js?v=1.4.4"></script>
<script type="text/javascript" src="misc/jquery.once.js?v=1.2"></script>
<script type="text/javascript" src="misc/drupal.js?0"></script>
<script type="text/javascript">
<!--//--><![CDATA[//><!--
jQuery.extend(Drupal.settings, {"basePath":"\/","pathPrefix":"","ajaxPageState":{"css":{"modules\/system\/system.base.css":1,"modules\/system\/system.admin.css":1,"modules\/system\/system.menus.css":1,"modules\/system\/system.messages.css":1,"modules\/system\/system.theme.css":1,"modules\/system\/system.maintenance.css":1,"themes\/seven\/reset.css":1,"themes\/seven\/style.css":1,"themes\/seven\/ie.css":1,"themes\/seven\/ie7.css":1,"themes\/seven\/ie6.css":1},"js":{"misc\/jquery.js":1,"misc\/jquery.once.js":1,"misc\/drupal.js":1}}});
//--><!]]>
</script>
  </head>
  <body class="maintenance-page in-maintenance db-offline one-sidebar sidebar-first">


  <div id="branding">
    <h1 class="page-title">Installatie Dimpact distributie</h1>  </div>

  <div id="page">

          <div id="sidebar-first" class="sidebar">
                  <img id="logo" src="profiles/dimpact/logo.png" alt="Drupal" />
                <h2 class="element-invisible">Installatie taken</h2><ol class="task-list">
    <?php foreach (install_steps() as $step => $name): ?>
      <?php if ($step == install_step_current()): ?>
                <li class="active"><?php print $name; ?> <span class="element-invisible">(active)</span></li>
      <?php endif; ?>
      <?php if (array_search($step, array_keys(install_steps())) < array_search(install_step_current(), array_keys(install_steps()))): ?>
                <li class="done"><?php print $name; ?></span></li>
      <?php endif; ?>
      <?php if (array_search($step, array_keys(install_steps())) > array_search(install_step_current(), array_keys(install_steps()))): ?>
                <li><?php print $name; ?></li>
      <?php endif; ?>
    <?php endforeach; ?>
                </ol>      </div>

    <div id="content" class="clearfix">
      <?php print $content; ?>
    </div>

  </div>


  </body>
</html>