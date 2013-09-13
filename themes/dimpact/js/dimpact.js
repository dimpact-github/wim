(function($) {
  /**
   * Hide all the tabs.
   */
  function hideProductTabs(){
    $("#quicktabs-alfabet .quicktabs-tabs li").removeClass("active");
    $("#quicktabs-container-alfabet .quicktabs-tabpage").addClass("quicktabs-hide");
    $('body').removeClass('overlay-alpha');
  }

  $(window).load(function () {

    // Alphabet menus
    hideProductTabs();
    $(document).mouseup(function(e) {
      var container = $("#quicktabs-alfabet");
      $('body').addClass('overlay-alpha');
      if (container.has(e.target).length === 0){
        hideProductTabs();
      }
    });

    var quicktabscontainer = $("#quicktabs-alfabet");
    var leave = false;
    var enter = false;
    var opacityValue = 1;
    quicktabscontainer.mouseleave(function(){
      leave = true;
      enter = false;
      $('*').clearQueue();
      $(this).animate({opacity : opacityValue},1000,function(){
        if(enter == false){
          hideProductTabs();
        }
        leave = false;
      });
    });
    quicktabscontainer.mouseenter(function(){
      enter = true;
      if(leave){
        $('*').clearQueue();
        $(this).animate({opacity : 1},1000);
      }
    });

    // Carousels
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
      next: {
        button: ".btn_next",
        key: "right"
      },
      prev: {
        button: ".btn_prev",
        key: "left"
      }
    });

    // Toptaken block
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
