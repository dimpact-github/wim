api = 2
core = 7.x
projects[drupal][type] = core
projects[drupal][patch][htaccess_iecompat] = patches/htaccess_iecompat.patch

; Modules
projects[libraries][subdir] = contrib

; Themes
projects[] = rijkshuisstijl

; Libraries
libraries[starterskit][type] = "libraries"
libraries[starterskit][download][type] = "file"
libraries[starterskit][download][url] = "https://github.com/studiodumbar/starterskit-pb/zipball/1.2.3"