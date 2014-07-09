(function ($) {
  Drupal.behaviors.inlinetabs = {
    attach: function(context) {
      $('.inlinetabs').each(function() {
        var container = this;

        $('> ul a', this).click(function() {
          $('> div', container).hide();
          $('> ul li, > ul a', container).removeClass('active');
          $('> ul a', container).attr('aria-selected', 'false');
          $($(this).attr('href')).show();
          $(this).addClass('active').parent().addClass('active');
          $(this).addClass('active').attr('aria-selected', 'true');
          return false;
        });

        $('> ul a:first', this).click();
      });
    }
  };
})(jQuery);
