(function ($) {
  Drupal.behaviors.customlists = {
    attach: function(context) {
      $('#edit-type').change(function(e) {
        if ($(this).val() == 'content') {
          $('.form-item-menu-item').hide();
          $('.form-item-node-type').show();
          $('.form-item-sort').show();
          $('.form-item-taxonomy').show();
        }
        else if ($(this).val() == 'menu') {
          $('.form-item-node-type').hide();
          $('.form-item-sort').hide();
          $('.form-item-taxonomy').hide();
          $('.form-item-menu-item').show();
        }
      });
      $('#edit-type').trigger('change');


      $('#edit-provide-block').change(function() {
        if ($(this).is(':checked')) {
          $('.form-item-block-items').show();
        }
        else {
          $('.form-item-block-items').hide();
        }
      });
      $('#edit-provide-block').trigger('change');

      $('#edit-provide-page').change(function() {
        if ($(this).is(':checked')) {
          $('.form-item-page-items').show();
          $('.form-item-path').show();
          $('.text-format-wrapper').show();
        }
        else {
          $('.form-item-page-items').hide();
          $('.form-item-path').hide();
          $('.text-format-wrapper').hide();
        }
      });
      $('#edit-provide-page').trigger('change');
    }
  };
})(jQuery);
