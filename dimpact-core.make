api = 2
core = 7.x

projects[drupal][type] = core
projects[drupal][version] = "7.39"
projects[drupal][patch][htaccess_iecompat] = patches/htaccess_iecompat.patch
projects[drupal][patch][htaccess_directories404] = patches/htaccess_directories404.patch
projects[drupal][patch][etag] = patches/etag.patch
