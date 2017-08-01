jQuery(document).ajaxComplete(function(event, xhr, settings) {
  if (settings.extraData._triggering_element_name == 'month') {
    jQuery.getScript("//translate.google.com/translate_a/element.js?cb=googleTranslateElementInit2");
  }
});

jQuery(document).ajaxComplete(function(event, xhr, settings) {
  if (settings.extraData._triggering_element_name == 'iwanttostudy') {
    jQuery.getScript("//translate.google.com/translate_a/element.js?cb=googleTranslateElementInit2");
  }
});

jQuery('#block-castleschool-castleschool-teaser .form-item-iwanttostudy').on('change', function() {
  updatequote();
});

jQuery('#block-castleschool-castleschool-teaser .form-item-month').on('change', function() {
  updatequote();
});

jQuery('#block-castleschool-castleschool-teaser select[name="day"]').on('change', function() {
  updatequote();
});

jQuery('#block-castleschool-castleschool-teaser .form-item-weeks').on('change', function() {
  updatequote();
});

function updatequote() {
  var bookingfee = 80;
  var quote = (jQuery('#block-castleschool-castleschool-teaser .form-item-weeks').val() * 250) + bookingfee;
  var accomm = jQuery('#block-castleschool-castleschool-teaser .form-item-weeks').val() * 150;
  jQuery('.castle-quote-total').text('£' + quote);
  jQuery('.castle-quote-accomm span').text('£' + accomm);
  jQuery('input[name=quotetotal]').val(quote);
}
