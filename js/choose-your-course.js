(function ($) {
  Drupal.behaviors.castleschool = {
    attach: function (context, settings) {
      $('select[name="course"]').once(function(){
          $('select[name="course"]').on('change',function() {
              updatechoosecoursequote();
          });
      });
      $('select[name="startdate"]').once(function(){
          $('select[name="startdate"]').on('change',function() {
              updatechoosecoursequote();
          });
      });
      $('select[name="hoursperweek"]').once(function(){
          $('select[name="hoursperweek"]').on('change',function() {
              updatechoosecoursequote();
          });
      });
      $('select[name="weeks"]').once(function(){
          $('select[name="weeks"]').on('change',function() {
              updatechoosecoursequote();
          });
      });
      updatechoosecoursequote();

      function updatechoosecoursequote() {
        var course = $('select[name="course"]').val();
        var startdate = $('select[name="startdate"]').val();
        var hoursperweek = $('select[name="hoursperweek"]').val();
        var weeks = $('select[name="weeks"]').val();
        $('#summary-course-quote').load('castleschool/course-quote/' + course + '/'
                + hoursperweek + '/' + weeks, function() {
          $('#summary-course-details').load('castleschool/course-summary-details/'
                  + course + '/' + hoursperweek + '/' + startdate + '/' + weeks, function() {
            var summarycoursequote = $('#summary-course-quote').text();
            var summaryaccommodationquote = $('#summary-accommodation-quote').text();
            var summaryextrasquote = $('#summary-extras-quote').text();
            $('#summary-quote-total').load('castleschool/summary-quote-total/' + summarycoursequote
                    + '/' + summaryaccommodationquote + '/' + summaryextrasquote, function() {
              $.getScript("//translate.google.com/translate_a/element.js?cb=googleTranslateElementInit2");
            });
          });
        });
      }
    }
  }
})(jQuery);
