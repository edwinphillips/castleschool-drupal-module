(function ($) {
  Drupal.behaviors.castleschool = {
    attach: function (context, settings) {

        $('select[name="hoursperweek"]').once(function(){
            $('select[name="hoursperweek"]').on('change',function() {
                updatequote();
            });
        });
        $('select[name="day"]').once(function(){
            $('select[name="day"]').on('change',function() {
                updatequote();
            });
        });
        $('select[name="weeks"]').once(function(){
            $('select[name="weeks"]').on('change',function() {
                updatequote();
            });
        });
        updatequote();

        var item1 = $('#castleschool-teaser-form .form-item-course');
        var width1 = item1.width();

        var item2 = $('#castleschool-teaser-form #castleschool_hoursperweek_wrapper .form-item-hoursperweek');
        var width2 = item2.width();
        var margin2 = parseInt(item2.css('margin-left'));

        var item3 = $('#castleschool-teaser-form .form-item-month');
        var width3 = item3.width();
        var margin3 = parseInt(item3.css('margin-left'));

        var item4 = $('#castleschool-teaser-form #castleschool_day_wrapper .form-item-day');
        var width4 = item4.width();
        var margin4 = parseInt(item4.css('margin-left'));

        var item5 = $('#castleschool-teaser-form .form-item-weeks');
        var width5 = item5.width();
        var margin5 = parseInt(item5.css('margin-left'));

        var item6 = $('#castleschool-teaser-form .castle-quote-wrapper');
        var width6 = item6.width();
        var margin6 = parseInt(item6.css('margin-left')) + parseInt(item6.css('margin-right'));

        var item7 = $('#castleschool-teaser-form #edit-submit-button');
        var width7 = item7.width();

        var formwidth = width1 + width2 + margin2 + width3 + margin3 + width4 + margin4 + width5 + margin5 + width6 + margin6 + width7;
        var teaserblockwidth = $('#block-castleschool-castleschool-teaser').width();

        if (teaserblockwidth > formwidth) {
            var form = $('#castleschool-teaser-form');
            form.width(formwidth);
            form.css('margin-left', 'auto');
            form.css('margin-right', 'auto');
        }

        function updatequote() {
            var course = $('select[name="course"]').val();
            var hoursperweek = $('select[name="hoursperweek"]').val();
            var weeks = $('select[name="weeks"]').val();
            $('#teaser-quote-value').load('castleschool/course-quote/' + course + '/' + hoursperweek + '/' + weeks, function() {
              var day = $('select[name="day"]').val();
              $('#teaser-accommodation-value').load('castleschool/accommodation-from-quote/' + weeks + '/' + day, function() {
                $.getScript("//translate.google.com/translate_a/element.js?cb=googleTranslateElementInit2");
              })
            });
        }
    }
  }
})(jQuery);
