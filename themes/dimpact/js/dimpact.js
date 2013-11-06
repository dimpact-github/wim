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

    $('.print-page').click(function(e) {
      window.print();
      e.preventDefault();
    });

    //Hoofdmenu responsive menu
    var mainMenu = $('.main-menu').find('ul.menu').eq(0);
    var menuToggle = $('<div>').addClass('menu-toggle').html('<a href="#">Menu</a>');
    mainMenu.before(menuToggle);

    $('.menu-toggle a').live("click", function(e) {
      if (mainMenu.hasClass('open')) {
        mainMenu.removeClass('open');
      }
      else {
        mainMenu.addClass('open');
      }
      e.preventDefault();
    });

    // Onderwerpen responsive menu
    var onderwerpenMenu = $('#quicktabs-alfabet');
    var onderwerpenToggle = $('<div>').addClass('onderwerpen-toggle').html('<a href="#">Onderwerpen</a>');
    onderwerpenMenu.before(onderwerpenToggle);
    $('.onderwerpen-toggle a').live("click", function(e) {
      if ($('#quicktabs-container-alfabet').hasClass('open')) {
        $('#quicktabs-container-alfabet').removeClass('open');
      }
      else {
        $('#quicktabs-container-alfabet').addClass('open');
      }
      e.preventDefault();
    });

//    var menuSelect = $("<select>").addClass('resp-menu');
//    menuSelect.append($("<option>").attr('value', '').text('-- menu --'));
//    $('.region_meta_first ul.menu a').each(function(i, e) {
//      menuSelect.append($("<option>").attr('value', $(e).attr('href')).text($(e).html()));
//    });
//    $('.region_meta_first ul.menu').before(menuSelect);
//    $('.resp-menu').live("change", function() {
//      document.location = $(this).attr('value');
//    });

    $('.quicktabs-tabpage').each(function(){
      var closeButton = $('<div>').addClass('close-button');
      $(this).append(closeButton);
    });


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
    if ($(".carousel .views-rows").length) {
      $(".carousel .views-rows").carouFredSel({
        items: 1,
        responsive: true,
        scroll: {
          fx: "directscroll",
          duration: 500,
          pauseOnHover: 'resume'
        },
        auto: {
          timeoutDuration: 10000,
          progress: ".progress"
        },
        next: {
          button: function() {
            return $(this).parents('.carousel').find('.btn_next');
          },
          key: "right"
        },
        prev: {
          button: function() {
            return $(this).parents('.carousel').find('.btn_prev');
          },
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

    // show dimpact service links on mouse over
    $('.dimpact_service_links_share_this').hover(function() {
      $('.dimpact_hide_service_links').show(222)
    },
    function() {
      $('.dimpact_hide_service_links').hide(222)
    });


    // Reset Font Size
    var htmlElem = $('html');
    var originalFontSize = htmlElem.css('font-size');
    $(".resetFont").click(function(){
      htmlElem.css('font-size', originalFontSize);
    });
    // Increase Font Size
    $(".text-larger").click(function(){
      var currentFontSize = htmlElem.css('font-size');
      var currentFontSizeNum = parseFloat(currentFontSize, 10);
      var newFontSize = currentFontSizeNum*1.2;
      htmlElem.css('font-size', newFontSize);
      return false;
    });
    // Decrease Font Size
    $(".text-smaller").click(function(){
      var currentFontSize = htmlElem.css('font-size');
      var currentFontSizeNum = parseFloat(currentFontSize, 10);
      var newFontSize = currentFontSizeNum*0.8;
      htmlElem.css('font-size', newFontSize);
      return false;
    });
  });

})(window.jQuery);
