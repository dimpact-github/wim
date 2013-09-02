(function($) {
  $(window).load(function () {

    $(".carousel-93 .views-rows").carouFredSel({
      items: 1,
      scroll: {
        fx: "directscroll",
        duration: 1000,
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

  });
})(window.jQuery);
