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
    }
  };
})(jQuery);
