api = 2
core = 7.x

includes[core] = "dimpact-core.make"
includes[develop] = "dimpact-develop.make"

defaults[projects][subdir] = "contrib"

; Modules
projects[admin_menu][version] = "3.0-rc5"

projects[admin_views][version] = "1.5"

projects[apachesolr][version] = "1.8"

projects[apachesolr_attachments][version] = "1.4"
projects[apachesolr_attachments][patch][1251308-23][url] = "https://www.drupal.org/files/issues/file-size-limit-correct-default-1251308-23.patch"
projects[apachesolr_attachments][patch][1251308-23][md5] = "162de26e6b86c9e349253dc955e10036"
projects[apachesolr_attachments][patch][bodytext] = patches/apachesolr-attachments-body.patch

projects[apachesolr_exclude_node][version] = "1.4"

projects[apachesolr_user][download][type] = git
projects[apachesolr_user][download][revision] = cadb26b
projects[apachesolr_user][download][branch] = 7.x-1.x
projects[apachesolr_user][patch][viewmodes] = patches/apachesolr_user-viewmodes.patch

projects[better_formats][version] = "1.0-beta1"

projects[block_class][version] = "2.3"

projects[cck_blocks][version] = "1.1"
projects[cck_blocks][patch][1309870-1][url] = http://drupal.org/files/cck-blocks-workbench-integration-1309870-1.patch
projects[cck_blocks][patch][1309870-1][md5] = 8ec9ab0c40781008a8b5025fe48abccd

projects[context][version] = "3.6"

projects[context_entity_field][version] = "1.1"

projects[ctools][version] = "1.9"

projects[cs_adaptive_image][version] = "1.0"

projects[date][version] = "2.8"

projects[diff][version] = "3.2"

projects[domain][version] = "3.11"

projects[domaincontext][version] = "1.0-alpha1"

projects[domain_entity][version] = "1.3"

projects[domain_taxonomy][download][type] = git
projects[domain_taxonomy][download][revision] = e489da0
projects[domain_taxonomy][download][branch] = 7.x-3.x

projects[domain_views][version] = "1.5"
projects[domain_views][patch][multiple_values] = http://drupal.org/files/multiple-values-2029419-1.patch

projects[domain_xmlsitemap][version] = "1.0-beta2"

projects[dominion][version] = "1.0-beta3"
projects[dominion][patch][regression-of-51d4d24-in-0f1e9b8] = "http://cgit.drupalcode.org/dominion/patch/?id=51d4d241c2b1ed0692e3129506e4e888012d4ac7"
projects[dominion][patch][varnish_images] = patches/dominon_access_varnish_images.patch
projects[dominion][patch][2619974][url] = "https://www.drupal.org/files/issues/custom_functions_as_context_conditions-2619974-5.patch"
projects[dominion][patch][2619974][md5] = "91a2a32049f8ea42b48cc33d5976d906"

projects[elysia_cron][version] = "2.1"

projects[email][version] = "1.3"

projects[empty_page][version] = "1.0"

projects[encrypt][version] = "2.3"

projects[entity][version] = "1.6"

projects[entityreference][version] = "1.1"
projects[entityreference][patch][1836106][url] = https://www.drupal.org/files/issues/entityreference-1836106-20.patch
projects[entityreference][patch][1836106][md5] = 544a81884a4590a11353ce659e1ebaa5

projects[expire][version] = "2.0-rc4"

projects[extlink][version] = "1.18"

projects[facetapi][version] = "1.3"

projects[faq][version] = "1.0-rc2"

projects[features][version] = "2.10"

projects[features_extra][version] = "1.0-beta1"

projects[feeds][version] = "2.0-alpha9"

projects[felix][version] = "1.0-beta4"
projects[felix][patch][nolinkit] = patches/felix-nolinkit.patch

projects[fences][version] = "1.2"

projects[field_group][version] = "1.5"

projects[field_group_multiple][version] = "1.0-beta2"

projects[file_entity][version] = "2.0-beta2"

projects[flag][version] = "3.6"

projects[galleryformatter][version] = "1.3"

projects[gmap][version] = "2.9"
projects[gmap][patch][duplicatefile] = patches/gmap-fixingduplicatefile.patch

projects[google_analytics][version] = "2.1"

projects[google_tag][version] = "1.0"

projects[hansel][version] = "1.4"
projects[hansel][patch][2399645-1][url] = "https://www.drupal.org/files/issues/hansel-broken-token-generation-2399645-1.patch"
projects[hansel][patch][2399645-1][md5] = "6135faaa96024e535139878e3d2b103a"

projects[homebox][version] = "2.0-rc2"

projects[hotjar][version] = "1.0"

projects[i18n][version] = "1.13"

projects[job_scheduler][version] = "2.0-alpha3"

projects[jquery_update][version] = "2.7"

projects[l10n_update][version] = "1.1"

projects[login_destination][version] = "1.1"

projects[ldap][version]= "2.0-beta6"

projects[libraries][version] = "2.2"

projects[lightbox2][version] = "1.0-beta1"

projects[link][version] = "1.2"
projects[link][patch][performance] = patches/link-performance-hack.patch

projects[linkit][version] = "3.5"

projects[location][version] = "3.2"
projects[location][patch][add_coords_to_location_url] = patches/add_coords_to_location_url.patch

projects[mail_edit][version] = "1.0"

projects[mailchimp][version] = "2.13"

projects[mailsystem][subdir] = contrib
projects[mailsystem][version] =  "2.34"

projects[masquerade][version] = "1.0-rc7"

projects[media][download][type] = "git"
projects[media][download][branch] = "7.x-2.x"
projects[media][download][revision] = "cfb0242"

projects[media_youtube][version] = "3.0"

projects[media_vimeo][version] = "2.1"

projects[memcache][version] = "1.0"

projects[menu_attributes][version] = "1.0"

projects[menu_block][version] = "2.7"

projects[menu_token][version] = "1.0-beta7"

projects[menu_view_unpublished][version] = "1.0-beta3"

projects[menuimage][version] = "1.1"

projects[metatag][version] = "1.0-beta9"

projects[mimemail][version] = "1.0-beta3"

projects[multiform][version] = "1.1"

projects[nodequeue][download][type] = git
projects[nodequeue][download][revision] = 70c0602
projects[nodequeue][download][branch] = 7.x-3.x
projects[nodequeue][patch][1154948][url] = http://drupal.org/files/taxonomy-sync-queue-1154948-15.patch
projects[nodequeue][patch][1154948][md5] = 2eae7ee249c90238cb0e8bfb6a98293b

projects[oauth][version] = 3.2

projects[password_policy][version] = "1.11"

projects[pathauto][version] = "1.2"

projects[pathauto_persist][version] = "1.3"

projects[pathologic][version] = "2.12"

projects[piwik][version] = "2.7"

projects[plupload][download][type] = "git"
projects[plupload][download][branch] = "7.x-1.x"
projects[plupload][download][revision] = "bba974c"

projects[purge][version] = "1.7"

projects[quicktabs][version] = "3.6"

projects[redirect][version] = "1.0-rc3"

projects[remote_stream_wrapper][version] = "1.0-beta4"

projects[rules][version] = "2.6"

projects[securepages][version] = "1.0-beta2"

projects[static_404][version] = "1.0-beta4"

projects[site_map][version] = "1.3"

projects[scheduler][version] = "1.3"

projects[service_links][version] = "2.3"

projects[strongarm][version] = "2.0"

projects[submenutree][version] = "2.3"

projects[subscriptions][version] = "1.1"

projects[textformatter][version] = "1.3"

projects[toc_filter][version] = 1.3

projects[token][version] = "1.6"

projects[translation_helpers][version] = "1.0"

projects[transliteration][version] = "3.2"
projects[transliteration][patch][862248-13][url] = https://www.drupal.org/files/transliteration-862248-13_punctuation_0.patch
projects[transliteration][patch][862248-13][md5] = be5b45301dc1b78ae7bcf4062b6d3ad4

projects[twitter][version] = "5.11"

projects[twitter_pull][version] = "2.0-alpha3"

projects[uuid][version] = "1.0-beta1"

projects[variable][version] = "2.4"

projects[views][version] = "3.13"

projects[views_bulk_operations][version] = "3.3"

projects[views_rss][version] = "2.0-rc3"

projects[webform][version] = "3.24"
projects[webform][patch][drupal_makes_file_upload_component_fail_for_anonymous_user] = patches/drupal_makes_file_upload_component_fail_for_anonymous_user.patch

projects[webform_clear] = "2.0"

projects[weight][version] = "2.5"

projects[wikitools][version] = "1.0-alpha1"

projects[workbench][version] = "1.2"

projects[workbench_moderation][download][type] = git
projects[workbench_moderation][download][branch] = "7.x-1.x"
projects[workbench_moderation][download][revision] = "c1573b6"
projects[workbench_moderation][patch][2021903_1][url] = http://drupal.org/files/workbench_moderation-draft_current_revision-2021903_1.patch
projects[workbench_moderation][patch][2021903_1][md5] = 29455a89821cab1c4085115f9743f600

projects[wysiwyg][download][type] = git
projects[wysiwyg][download][branch] = "7.x-2.x"
projects[wysiwyg][download][revision] = "898d022"

projects[xmlsitemap][version] = "2.2"

; Themes
projects[rijkshuisstijl][version] = "1.2"

; Rijkshuisstijl starterskit
libraries[starterskit][type] = "libraries"
libraries[starterskit][download][type] = "file"
libraries[starterskit][download][url] = "https://github.com/studiodumbar/starterskit-pb/zipball/1.2.3"

; CKEditor 4.4.6
libraries[ckeditor][download][type] = get
libraries[ckeditor][download][url] = http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.4.6/ckeditor_4.4.6_full.tar.gz

; a11ychecker_custom
libraries[a11ychecker][download][type] = "get"
libraries[a11ychecker][download][url] = "http://a11ychecker.download.cksource.com/custom/a11ychecker_custom.zip"
libraries[a11ychecker][destination] = "libraries"
libraries[a11ychecker][subdir] = "ckeditor_plugins"
libraries[a11ychecker][directory_name] = "a11ychecker_custom"

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

; Plupload
libraries[plupload][directory_name] = plupload
libraries[plupload][download][type] = file
libraries[plupload][download][url] = https://github.com/moxiecode/plupload/archive/v1.5.8.zip
libraries[plupload][patch][1903850] = https://www.drupal.org/files/issues/plupload-1_5_8-rm_examples-1903850-21.patch
libraries[plupload][type] = library
