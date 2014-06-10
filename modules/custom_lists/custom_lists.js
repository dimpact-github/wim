(function ($) {
  Drupal.behaviors.customlists = {
    attach: function(context) {

      function showSettings() {
        $('.block-setting').parent().hide();
        $('.page-setting').parent().hide();
        $('.type-setting').parent().hide();
        $('.text-format-wrapper').hide();


        if ($('#edit-type').val() == 'content') {
          $('.type-setting-content').parent().show();
          if ($('#edit-provide-block').is(':checked')) {
            $('.block-setting-content').parent().show();
            if ($('#edit-show-more-link').val() != 'custom') {
              $('#edit-more-link').parent().hide();
            }
          }
          if ($('#edit-provide-page').is(':checked')) {
            $('.page-setting-content').parent().show();
            $('.text-format-wrapper').show();
          }
        }
        else if ($('#edit-type').val() == 'menu') {
          $('.type-setting-menu').parent().show();
          if ($('#edit-provide-block').is(':checked')) {
            $('.block-setting-menu').parent().show();
          }
          if ($('#edit-provide-page').is(':checked')) {
            $('.page-setting-menu').parent().show();
            $('.text-format-wrapper').show();
          }
        }
      }

      // Trigger to change the shown settings fields.
      $('#edit-type').change(function(e) {
        showSettings();
      });
      $('#edit-provide-block').change(function() {
        showSettings();
      });
      $('#edit-provide-page').change(function() {
        showSettings();
      });
      $('#edit-show-more-link').change(function() {
        showSettings();
      });

      // Initialise fields.
      showSettings();
    }
  };
})(jQuery);
