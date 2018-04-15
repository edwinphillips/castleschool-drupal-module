(function ($) {
  Drupal.behaviors.castleschool = {
    attach: function (context, settings) {
        $('#castleschool-worldpay-form').delay(5000).submit();
    }
  }
})(jQuery);