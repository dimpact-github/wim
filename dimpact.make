api = 2
core = 7.x

includes[core] = "dimpact-core.make"
includes[develop] = "dimpact-develop.make"

; Modules
projects[admin_menu][subdir] = contrib
projects[admin_menu][version] = "3.0-rc4"

projects[admin_views][subdir] = contrib
projects[admin_views][version] = "1.2"

projects[apachesolr][subdir] = contrib
projects[apachesolr][version] = "1.6"

projects[apachesolr_attachments][subdir] = contrib
projects[apachesolr_attachments][version] = "1.3"
projects[apachesolr_attachments][patch][bodytext] = patches/apachesolr-attachments-body.patch

projects[apachesolr_exclude_node][subdir] = contrib
projects[apachesolr_exclude_node][version] = "1.1"

projects[apachesolr_user][subdir] = contrib
projects[apachesolr_user][download][type] = git
projects[apachesolr_user][download][revision] = cadb26b
projects[apachesolr_user][download][branch] = 7.x-1.x
projects[apachesolr_user][patch][viewmodes] = patches/apachesolr_user-viewmodes.patch

projects[better_formats][subdir] = contrib
projects[better_formats][version] = "1.0-beta1"

projects[block_class][subdir] = contrib
projects[block_class][version] = "2.1"

projects[cck_blocks][subdir] = contrib
projects[cck_blocks][version] = "1.1"

projects[context][subdir] = contrib
projects[context][version] = "3.6"

projects[context_entity_field][subdir] = contrib
projects[context_entity_field][version] = "1.1"

projects[ctools][subdir] = contrib
projects[ctools][version] = "1.5"

projects[cs_adaptive_image][subdir] = contrib
projects[cs_adaptive_image][version] = "1.0"

projects[date][subdir] = contrib
projects[date][version] = "2.8"

projects[diff][subdir] = contrib
projects[diff][version] = "3.2"

projects[domain][subdir] = contrib
projects[domain][version] = "3.11"

projects[domaincontext][subdir] = contrib
projects[domaincontext][version] = "1.0-alpha1"

projects[domain_entity][subdir] = contrib
projects[domain_entity][version] = "1.3"

projects[domain_taxonomy][subdir] = contrib
projects[domain_taxonomy][download][type] = git
projects[domain_taxonomy][download][revision] = e489da0
projects[domain_taxonomy][download][branch] = 7.x-3.x

projects[domain_views][subdir] = contrib
projects[domain_views][version] = "1.5"
projects[domain_views][patch][multiple_values] = http://drupal.org/files/multiple-values-2029419-1.patch

projects[domain_xmlsitemap][subdir] = contrib
projects[domain_xmlsitemap][version] = "1.0-beta2"

projects[dominion][subdir] = contrib
projects[dominion][download][type] = "git"
projects[dominion][download][branch] = "7.x-1.x"
projects[dominion][download][revision] = 628f4cb
projects[dominion][patch][regression-of-51d4d24-in-0f1e9b8][url] = "http://cgit.drupalcode.org/dominion/patch/?id=51d4d241c2b1ed0692e3129506e4e888012d4ac7"
projects[dominion][patch][regression-of-51d4d24-in-0f1e9b8][md5] = "cfdfa699864b040d58c5141162d570ca"
projects[dominion][patch][varnish_images] = patches/dominon_access_varnish_images.patch

projects[elysia_cron][subdir] = contrib
projects[elysia_cron][version] = "2.1"

projects[email][subdir] = contrib
projects[email][version] = "1.2"

projects[empty_page][subdir] = contrib
projects[empty_page][version] = "1.0"

projects[entity][subdir] = contrib
projects[entity][version] = "1.3"

projects[entityreference][subdir] = contrib
projects[entityreference][version] = "1.1"
projects[entityreference][patch][1836106][url] = https://www.drupal.org/files/issues/entityreference-1836106-20.patch
projects[entityreference][patch][1836106][md5] = 544a81884a4590a11353ce659e1ebaa5

projects[expire][subdir] = contrib
projects[expire][version] = "2.0-rc4"

projects[extlink][subdir] = contrib
projects[extlink][version] = "1.13"

projects[facetapi][subdir] = contrib
projects[facetapi][version] = "1.3"

projects[faq][subdir] = contrib
projects[faq][version] = "1.0-rc2"

projects[features][subdir] = contrib
projects[features][version] = "2.0"

projects[features_extra][subdir] = contrib
projects[features_extra][version] = "1.0-beta1"

projects[feeds][subdir] = contrib
projects[feeds][version] = "2.0-alpha8"

projects[felix][subdir] = contrib
projects[felix][version] = "1.0-beta4"
projects[felix][patch][nolinkit] = patches/felix-nolinkit.patch

projects[fences][subdir] = contrib
projects[fences][version] = "1.0"

projects[field_group][subdir] = contrib
projects[field_group][version] = "1.3"

projects[field_group_multiple][subdir] = contrib
projects[field_group_multiple][version] = "1.0-beta2"

projects[file_entity][subdir] = contrib
projects[file_entity][download][type] = "git"
projects[file_entity][download][branch] = "7.x-2.x"
projects[file_entity][download][revision] = "39e9f08"

projects[flag][subdir] = contrib
projects[flag][version] = "3.5"

projects[galleryformatter][subdir] = contrib
projects[galleryformatter][version] = "1.3"

projects[gmap][subdir] = contrib
projects[gmap][version] = "2.9"
projects[gmap][patch][duplicatefile] = patches/gmap-fixingduplicatefile.patch

projects[google_analytics][subdir] = contrib
projects[google_analytics][version] = "1.4"

projects[hansel][subdir] = contrib
projects[hansel][version] = "1.4"
projects[hansel][patch][2399645-1][url] = "https://www.drupal.org/files/issues/hansel-broken-token-generation-2399645-1.patch"
projects[hansel][patch][2399645-1][md5] = "6135faaa96024e535139878e3d2b103a"

projects[homebox][subdir] = contrib
projects[homebox][version] = "2.0-rc1"

projects[i18n][subdir] = contrib
projects[i18n][version] = "1.10"

projects[job_scheduler][subdir] = contrib
projects[job_scheduler][version] = "2.0-alpha3"

projects[jquery_update][subdir] = contrib
projects[jquery_update][version] = "2.3"

projects[l10n_update][subdir] = contrib
projects[l10n_update][version] = "1.1"

projects[login_destination][subdir] = contrib
projects[login_destination][version] = "1.1"

projects[ldap][subdir] = contrib
projects[ldap][version]= "2.0-beta6"

projects[libraries][subdir] = contrib
projects[libraries][version] = "2.2"

projects[lightbox2][subdir] = contrib
projects[lightbox2][version] = "1.0-beta1"

projects[link][subdir] = contrib
projects[link][version] = "1.2"
projects[link][patch][performance] = patches/link-performance-hack.patch

projects[linkit][subdir] = contrib
projects[linkit][version] = "3.3"

projects[location][subdir] = contrib
projects[location][version] = "3.2"

projects[mail_edit][subdir] = contrib
projects[mail_edit][version] = "1.0"

projects[mailchimp][subdir] = contrib
projects[mailchimp][version] = "2.12"

projects[masquerade][subdir] = contrib
projects[masquerade][version] = "1.0-rc7"

projects[media][subdir] = contrib
projects[media][download][type] = "git"
projects[media][download][branch] = "7.x-2.x"
projects[media][download][revision] = "247b31f"
projects[media][patch][2367725][url] = "http://cgit.drupalcode.org/media/patch/?id=1e975ad09aa502d3a02af88805190f28013cfedf"
projects[media][patch][2367725][md5] = "adbdeec409d3c3807c7eec087b9a5d1a"
projects[media][patch][2401811-11][url] = "https://www.drupal.org/files/issues/file_entity-remove-contextual-links-2401811-11.patch"
projects[media][patch][2401811-11][md5] = "cd8fca6386cac7f3d87c6dece5ae7a6b"

projects[media_youtube][subdir] = contrib
projects[media_youtube][download][type] = git
projects[media_youtube][download][revision] = "9728dfb"
projects[media_youtube][download][branch] = 7.x-2.x

projects[media_vimeo][subdir] = contrib
projects[media_vimeo][download][type] = "git"
projects[media_vimeo][download][revision] = "546dfa3"
projects[media_vimeo][download][branch] = 7.x-2.x

projects[memcache][subdir] = contrib
projects[memcache][version] = "1.0"

projects[menu_attributes][subdir] = contrib
projects[menu_attributes][version] = "1.0-rc2"

projects[menu_block][subdir] = contrib
projects[menu_block][version] = "2.3"

projects[menu_token][subdir] = contrib
projects[menu_token][version] = "1.0-beta5"

projects[menu_view_unpublished][subdir] = contrib
projects[menu_view_unpublished][version] = "1.0-beta3"

projects[menuimage][subdir] = contrib
projects[menuimage][version] = "1.1"

projects[metatag][subdir] = contrib
projects[metatag][version] = "1.0-beta9"

projects[nodequeue][subdir] = contrib
projects[nodequeue][download][type] = git
projects[nodequeue][download][revision] = 70c0602
projects[nodequeue][download][branch] = 7.x-3.x
projects[nodequeue][patch][1154948][url] = http://drupal.org/files/taxonomy-sync-queue-1154948-15.patch
projects[nodequeue][patch][1154948][md5] = 2eae7ee249c90238cb0e8bfb6a98293b

projects[password_policy][subdir] = contrib
projects[password_policy][version] = "1.8"

projects[pathauto][subdir] = contrib
projects[pathauto][version] = "1.2"

projects[pathauto_persist][subdir] = contrib
projects[pathauto_persist][version] = "1.3"

projects[pathologic][subdir] = contrib
projects[pathologic][version] = "2.12"

projects[piwik][subdir] = contrib
projects[piwik][version] = "2.7"

projects[purge][subdir] = contrib
projects[purge][version] = "1.6"
projects[purge][patch][1892028-26][url] = "https://www.drupal.org/files/issues/1892028-26-fix-curl-multi-select-bug.patch"
projects[purge][patch][1892028-26][md5] = "1f65e6937213ed985536b02919508007"


projects[quicktabs][subdir] = contrib
projects[quicktabs][version] = "3.6"

projects[redirect][subdir] = contrib
projects[redirect][version] = "1.0-rc1"
projects[redirect][patch][1796596-48][url] = http://drupal.org/files/redirect-detect_prevent_circular_redirects_patch_and_test-1796596-48.patch
projects[redirect][patch][1796596-48][md5] = a04d97c14445471ffd1a6a357540e47e

projects[remote_stream_wrapper][subdir] = contrib
projects[remote_stream_wrapper][version] = "1.0-beta4"

projects[rules][subdir] = contrib
projects[rules][version] = "2.6"

projects[securepages][subdir] = contrib
projects[securepages][version] = "1.0-beta2"

projects[static_404][subdir] = contrib
projects[static_404][version] = "1.0-beta4"

projects[site_map][subdir] = contrib
projects[site_map][version] = "1.2"

projects[scheduler][subdir] = contrib
projects[scheduler][version] = "1.3"

projects[service_links][subdir] = contrib
projects[service_links][version] = "2.2"

projects[strongarm][subdir] = contrib
projects[strongarm][version] = "2.0"

projects[submenutree][subdir] = contrib
projects[submenutree][version] = "2.3"

projects[subscriptions][subdir] = contrib
projects[subscriptions][version] = "1.1"

projects[token][subdir] = contrib
projects[token][version] = "1.5"

projects[translation_helpers][subdir] = contrib
projects[translation_helpers][version] = "1.0"

projects[transliteration][subdir] = contrib
projects[transliteration][version] = "3.1"

projects[variable][subdir] = contrib
projects[variable][version] = "2.4"

projects[views][subdir] = contrib
projects[views][version] = "3.10"

projects[views_bulk_operations][subdir] = contrib
projects[views_bulk_operations][version] = "3.2"

projects[views_rss][subdir] = contrib
projects[views_rss][version] = "2.0-rc3"

projects[webform][subdir] = contrib
projects[webform][download][type] = git
projects[webform][download][tag] = 7.x-3.20

projects[weight][subdir] = contrib
projects[weight][version] = "2.3"

projects[wikitools][subdir] = contrib
projects[wikitools][version] = "1.0-alpha1"

projects[workbench][subdir] = contrib
projects[workbench][version] = "1.2"

projects[workbench_moderation][subdir] = contrib
projects[workbench_moderation][version] = "1.3"

projects[wysiwyg][subdir] = contrib
projects[wysiwyg][download][type] = git
projects[wysiwyg][download][branch] = "7.x-2.x"
projects[wysiwyg][download][revision] = "898d022"

projects[xmlsitemap][subdir] = contrib
projects[xmlsitemap][version] = "2.0"

; Themes
projects[] = rijkshuisstijl

; Rijkshuisstijl starterskit
libraries[starterskit][type] = "libraries"
libraries[starterskit][download][type] = "file"
libraries[starterskit][download][url] = "https://github.com/studiodumbar/starterskit-pb/zipball/1.2.3"

; CKEditor 3.6.2
libraries[ckeditor][download][type] = get
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.4.6/ckeditor_4.4.6_full.tar.gz

; Mailchimp
libraries[mailchimp][download][type] = "get"
libraries[mailchimp][download][url] = "http://apidocs.mailchimp.com/api/downloads/mailchimp-api-class.zip"
libraries[mailchimp][directory_name] = "mailchimp"
libraries[mailchimp][destination] = "libraries"

; Modernizr
;libraries[modernizr][download][type] = "get"
;libraries[modernizr][download][url] = "http://www.modernizr.com/downloads/modernizr-2.6.2.js"
;libraries[modernizr][directory_name] = "modernizr"
;libraries[modernizr][destination] = "libraries"
