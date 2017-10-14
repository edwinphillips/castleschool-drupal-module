<?php

/**
 * 
 * @param type $accommodationid
 * @return type
 */
function castleschool_calculate_accommodation_quote($accommodationid) {

  $accommodationoptiontotal = 0;
  $accommodationfindingfee = castleschool_get_accommodation_finding_fee();
  $accommodationprices = castleschool_accommodation_details();

  $coursestartdate = $_SESSION['castleschool_day'];
  $accommodationstartdate = $coursestartdate - 2 * 24 * 60 * 60; // 2 days prior
  $weekstarttimestamp = $accommodationstartdate;
  $accommodationoptionperiods = $accommodationprices[$accommodationid]['periods'];

  for ($i = 1; $i <= $_SESSION['accommodationduration']; $i++) {

    foreach ($accommodationoptionperiods as $accommodationoptionperiodid => $accommodationoptionperiod) {

      $periodstartyear = date('Y', $weekstarttimestamp);
      $periodstartmonth = $accommodationoptionperiod['start']['month'];
      $periodstartday = $accommodationoptionperiod['start']['day'];
      $periodstart = strtotime("{$periodstartyear}-{$periodstartmonth}-{$periodstartday}");

      $periodendyear = date('Y', strtotime('+1 Week', $weekstarttimestamp));
      if ($periodendyear > $periodstartyear) {
        $periodendyear = $periodstartyear;
      }
      $periodendmonth = $accommodationoptionperiod['end']['month'];
      $periodendday = $accommodationoptionperiod['end']['day'];
      $periodend = strtotime("{$periodendyear}-{$periodendmonth}-{$periodendday}");

      if (($weekstarttimestamp >= $periodstart) && ($weekstarttimestamp <= $periodend)) {
        $accommodationoptiontotal += $accommodationoptionperiod['priceperweek'];
      }
    }
    $weekstarttimestamp += 7 * 24 * 60 * 60; // Add 7 days to the timestamp
  }

  $accommodationoptiontotal += $accommodationfindingfee;

  return $accommodationoptiontotal;
}
