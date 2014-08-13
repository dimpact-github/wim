(function($) {

  /**
   * Hide all the tabs.
   */
  function hideProductTabs(){
    $(".main-menu .block-quicktabs .quicktabs-tabs li").removeClass("active");
    $(".main-menu .block-quicktabs .quicktabs-tabpage").addClass("quicktabs-hide");
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

    // collapse hoofdmenu if the menu-toggle is visible
    function toggleMainMenu() {
      var displayMode = (menuToggle.css("display") != "none") ? "none" : "block";
      mainMenu.css("display", displayMode);
    }
    // set initial display level
    toggleMainMenu();
    // set display level when changing window size, including switching layout mode for touch-enabled devices
    $(window).resize(function(){
      toggleMainMenu();
    });

    $('.menu-toggle a').live("click", function(e) {
      mainMenu.toggleClass('open');
      e.preventDefault();
    });

    // Onderwerpen responsive menu
    var onderwerpenMenu = $('.main-menu .block-quicktabs');
    var onderwerpenToggle = $('<div>').addClass('onderwerpen-toggle').html('<a href="#">Onderwerpen</a>');
    onderwerpenMenu.before(onderwerpenToggle);
    $('.onderwerpen-toggle a').live("click", function(e) {
      $('.quicktabs-tabpage').toggleClass('open');
      e.preventDefault();
    });

    // Sluiten quicktab-tabpage
    // voeg close-button link aan iedere quicktabs-tabpage toe
    $('.quicktabs-tabpage').each(function(){
      var closeButton = $('<a href="#">Sluit dit menu</a>').addClass('close-button');
      $(this).append(closeButton);
    });
    // sluit de quicktabs bij aan muisklik op de close-button link
    $('.quicktabs-tabpage .close-button').click(function() {
      hideProductTabs();
    });
    // sluit de quicktabs bij aan enter op de close-button link
    $('.quicktabs-tabpage .close-button').keydown(function() {
      var keycode = (event.keyCode ? event.keyCode : event.which);
      if(keycode == '13') {
        hideProductTabs();
      }
    });

    // Voeg donkere achtergrond toe zodra de alfabet-balk focus krijgt
    $('.quicktabs-tabs').focusin(function() {
      $('body').addClass('overlay-alpha');
    });

    // Sluit de quicktabs als het de focus verliest
    $(document).focusin(function(e) {
      var container = $(".main-menu .block-quicktabs .quicktabs-tabs li");
      if (container.has(e.target).length === 0){
        hideProductTabs();
      }
    });

    var quicktabscontainer = $(".main-menu .block-quicktabs");
    var leave = false;
    var enter = false;
    var opacityValue = 1;
    quicktabscontainer.focusout(function(){
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
    quicktabscontainer.focusin(function(){
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
    $('.block-menu-menu-toptaken > ul > li > a').click(function(e) {
      if (!$(this).parent().hasClass('toptaken-active')) {
        $('.block-menu-menu-toptaken > ul > li').removeClass('toptaken-active');
        $(this).parent().addClass('toptaken-active');
      }
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
