jQuery(document).ajaxComplete(function(event, xhr, settings) {
  if (settings.extraData._triggering_element_name == 'castleschool_quote_months') {
    jQuery.getScript("//translate.google.com/translate_a/element.js?cb=googleTranslateElementInit2");
  }
});

jQuery('#edit-castleschool-quote-iwanttostudy').on('change', function() {
  updatequote();
});

jQuery('#edit-castleschool-quote-months').on('change', function() {
  updatequote();
});

jQuery('select[name="castleschool_quote_day"]').on('change', function() {
  updatequote();
});

jQuery('#edit-castleschool-quote-weeks').on('change', function() {
  updatequote();
});

function updatequote() {
  var bookingfee = 80;
  var quote = (jQuery('#edit-castleschool-quote-weeks').val() * 250) + bookingfee;
  var accomm = jQuery('#edit-castleschool-quote-weeks').val() * 150;
  jQuery('.castle-quote-total').text('£' + quote);
  jQuery('.castle-quote-accomm span').text('£' + accomm);
  jQuery('input[name=quotetotal]').val(quote);
}
