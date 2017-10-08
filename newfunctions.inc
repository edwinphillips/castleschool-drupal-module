<?php

/**
 * 
 * @param type $accommodationoption
 * @param type $accommodationfindingfee
 * @param type $accommodationid
 * @return type
 */
function castleschool_calculate_accommodation_quote($accommodationid, $accommodationoption, $accommodationfindingfee) {

  $accommodationprices = castleschool_accommodation_details();

  /*
  echo '<pre>';
  echo $accommodationstartdate;
  echo '</pre>';
  echo '<pre>';
  print_r($accommodationprices);
  echo '</pre>';
  die;
   * 
   */
  
  $coursestartdate = $_SESSION['castleschool_day'];
  $accommodationstartdate = $coursestartdate - 48 * 60 * 60; // 48 hours prior (Accommdation starts on a Saturday, courses on a Monday)
  $accommodationoptionperiods = $accommodationprices[$accommodationid]['periods'];
  $accommodationoptiontotal = 0;
  $weekstarttimestamp = $accommodationstartdate;

  for ($i = 2; $i <= $SESSION['accommodationduration']; $i++) {
    foreach ($accommodationoptionperiods as $accommodationoptionperiodid => $accommodationoptionperiod) {

      $weekstartmonth = date('n', $weekstarttimestamp);
      $weekstartday = date('j', $weekstarttimestamp);

      echo '<pre>';
      echo $weekstartmonth;
      echo '</pre>';
      echo '<pre>';
      echo $weekstartday;
      echo '</pre>';
      die;

      // is the month  between ['start']['month'] and ['end']['month']
      if ($weekstartmonth > $accommodationoptionperiod['start']['month']
          && $weekstartmonth < $accommodationoptionperiod['end']['month']) {

        $accommodationoptiontotal += $accommodationoptionperiod['priceperweek'];

      // or is the month one of the values ['start']['month'] or ['end']['month']
      } else if ($weekstartmonth == $accommodationoptionperiod['start']['month']
          || $weekstartmonth == $accommodationoptionperiod['end']['month']) {

        // Week start month is the same as the start month
        if ($weekstartmonth == $accommodationoptionperiod['start']['month']) {
          
          // Check the previous month period
          $accommodationoptiontotal += 50;
          
        // Week start month is the same as the start month
        } else if ($weekstartmonth == $accommodationoptionperiod['end']['month']) {
          
          // Check the next month period
          $accommodationoptiontotal += 100;
        }
      }

      $weekstarttimestamp += 7 * 24 * 60 * 60; // Add 7 days to the timestamp
    }
  }

  return array(
    '<p>' . $accommodationoption['label'] . ' - <strong>£' . $accommodationoptiontotal . '</strong></p>',
    '<a class="btn btn-submit" href="/choose-your-accommodation/' . $accommodationid . '">' .t('Select') .'</a>',
  );
  
}
