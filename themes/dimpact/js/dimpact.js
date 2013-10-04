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

    $('.quicktabs-tabpage').each(function(){
      var closeButton = $('<div>').addClass('close-button');
      $(this).append(closeButton);
    });

    // Alphabet menus
    hideProductTabs();

    $('#quicktabs-alfabet').mouseup(function() {
      $('body').addClass('overlay-alpha');
    });

    $(document).mouseup(function(e) {
      var container = $("#quicktabs-alfabet .quicktabs-tabs li");
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
    if ($(".carousel-93 .views-rows").length) {
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
    }

    // Toptaken block
    $('.block-menu-menu-toptaken > ul > li.first').addClass('toptaken-active');
    $('.block-menu-menu-toptaken > ul > li').click(function() {
      $('.block-menu-menu-toptaken > ul > li').removeClass('toptaken-active');
      $(this).addClass('toptaken-active');
    });
    $('.block-menu-menu-toptaken > ul > li > a').click(function(e) {
      e.preventDefault();
    });

//    var stickyHeaderTop = $('.block-system-main-menu').offset().top;
//    $(window).scroll(function(){
//      if( $(window).scrollTop() > stickyHeaderTop ) {
//        $('.block-system-main-menu').addClass('fixed');
//        $('body').addClass('fixed-menu');
//      } else {
//        $('.block-system-main-menu').removeClass('fixed');
//        $('body').removeClass('fixed-menu');
//      }
//    });

    // show dimpact service links on mouse over
    $('.dimpact_service_links_share_this').hover(function() {
      $('.dimpact_hide_service_links').show(222)
    }, 
    function() {
      $('.dimpact_hide_service_links').hide(222)
    });

  });



})(window.jQuery);
