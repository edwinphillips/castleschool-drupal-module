

(function ($) {
  Drupal.behaviors.castleschool = {
    attach: function (context, settings) {
        $('#castleschool-make-worldpay-payment-form').delay(5000).submit();
    }
  }
})(jQuery);