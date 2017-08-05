(function ($) {
  Drupal.behaviors.castleschool = {
    attach: function (context, settings) {
        $('select[name="accommodationduration"]').once(function(){
            $('select[name="accommodationduration"]').on('change',function() {
              if ($("#summary-accommodation-quote").text() != '0') {
                  updateaccommodationquote();
              }
            });
        });

        function updateaccommodationquote() {
            var weeks = $('select[name="accommodationduration"]').val();
            $('#summary-accommodation-quote').load('castleschool/accommodation-quote/' + weeks, function() {
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