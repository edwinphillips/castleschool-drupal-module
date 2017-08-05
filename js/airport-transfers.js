(function ($) {
  Drupal.behaviors.castleschool = {
    attach: function (context, settings) {
        $('select[name="whichairport"]').once(function(){
            $('select[name="whichairport"]').on('change',function() {
                updateextrasquote();
            });
        });
        $('select[name="arrivaldeparture"]').once(function(){
            $('select[name="arrivaldeparture"]').on('change',function() {
                updateextrasquote();
            });
        });

        function updateextrasquote() {
            var whichairport = $('select[name="whichairport"]').val();
            var arrivaldeparture = $('select[name="arrivaldeparture"]').val();
            $('#summary-extras-quote').load('castleschool/extras-quote/' + whichairport + '/' + arrivaldeparture, function() {
              var coursequotetotal = $("#summary-course-quote").text();
              var accommodationquotetotal = $("#summary-accommodation-quote").text();
              var optionalextrasquotetotal = $("#summary-extras-quote").text();
              $('#summary-quote-total').load('castleschool/summary-quote-total/'
                      + coursequotetotal + '/' + accommodationquotetotal + '/' + optionalextrasquotetotal, function() {
                $.getScript("//translate.google.com/translate_a/element.js?cb=googleTranslateElementInit2");
              });
            });
        }
    }
  }
})(jQuery);