(function($) {
  $(window).load(function () {

    $(".carousel-93 .views-rows").carouFredSel({
      items: 1,
      responsive: true,
      scroll: {
        fx: "directscroll",
        duration: 500,
        pauseOnHover: 'resume'
      },
      auto: {
        timeoutDuration: 10000,
        progress: ".progress",
        button: ".btn_play_pause"
      },
      pagination: ".pager",
      next: {
        button: ".btn_next",
        key: "right"
      },
      prev: {
        button: ".btn_prev",
        key: "left"
      }
    });

    $('.block-menu-menu-toptaken > ul > li.first').addClass('toptaken-active');
    $('.block-menu-menu-toptaken > ul > li').click(function() {
      $('.block-menu-menu-toptaken > ul > li').removeClass('toptaken-active');
      $(this).addClass('toptaken-active');
    });
    $('.block-menu-menu-toptaken > ul > li > a').click(function(e) {
      e.preventDefault();
    });
  });
})(window.jQuery);
