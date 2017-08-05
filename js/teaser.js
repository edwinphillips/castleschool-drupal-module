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

        function updatequote() {
            var course = $('select[name="course"]').val();
            var hoursperweek = $('select[name="hoursperweek"]').val();
            var weeks = $('select[name="weeks"]').val();
            $('.castle-quote-total').load('castleschool/quote/' + course + '/' + hoursperweek + '/' + weeks);
            $.getScript("//translate.google.com/translate_a/element.js?cb=googleTranslateElementInit2");
        }
    }
  }
})(jQuery);
