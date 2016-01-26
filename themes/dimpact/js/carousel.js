(function($) {
// Start carousels.
Drupal.behaviors.dimpact_carousel = {
  attach: function(context, settings) {
    // Carousels
    if ($(".carousel .views-rows", context).length) {
        // Create Pagination elements via javascript because of reasons.
        var next = '<button class="btn_next" title="' + Drupal.t('Next') + '"><span class="icon-chevron-sign-right"><span class="element-invisible">' + Drupal.t('Next') + '</span></span></a>';
        $(".carousel .views-rows", context).after(next);

        var play_pauze = '<button class="btn_play" title="' + Drupal.t('Play / Pause carousel') + '"><span class="icon-"><span class="element-invisible">' + Drupal.t('Play/Pause') + '</span></span></a>';
        $(".carousel .views-rows", context).after(play_pauze);

        var previous = '<button class="btn_prev" title="' + Drupal.t('Previous') + '"><span class="icon-chevron-sign-left"><span class="element-invisible">' + Drupal.t('Previous') + '</span></span></a>';
        $(".carousel .views-rows", context).after(previous);

        $(".carousel .views-rows", context).after('<div class="progress"></div>');

        // Instantiate carousels.
        $(".carousel .views-rows", context).carouFredSel({
            items: 1,
            responsive: true,
            scroll: {
                fx: "directscroll",
                duration: 500,
                // pauseOnHover: 'resume'
            },
            auto: {
                // button makes play/pause functionality possible. pauseonhover must be off, else
                // it overides the button everytime you hover over other parts of the carousel.
                button: function() {
                    return $(this).parents('.carousel').find('.btn_play');
                },
                timeoutDuration: 10000,
                progress: {
                    bar: function() {
                        return $(this).parents('.carousel').find('.progress');
                    }
                }
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
    }
};

})(jQuery);
