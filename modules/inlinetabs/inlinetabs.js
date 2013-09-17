(function ($) {
  Drupal.behaviors.inlinetabs = {
    attach: function(context) {
      $('.inlinetabs').each(function() {
        var container = this;
        
        $('> ul a', this).click(function() {
          $('> div', container).hide();
          $('> ul li, > ul a', container).removeClass('active');
          $($(this).attr('href')).show();
          $(this).addClass('active').parent().addClass('active');
          return false;
        });
        
        $('> ul a:first', this).click();
      });
    }
  };
})(jQuery);
