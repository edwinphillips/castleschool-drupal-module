<?php

/**
 * Returns registration fee value.
 *
 * @return int
 */
function castleschool_get_registration_fee() {

  return 60;
}

/**
 * Returns accommodation finding fee value.
 *
 * @return int
 */
function castleschool_get_accommodation_finding_fee() {

  return 50;
}

/**
 * Returns accommodation types and prices.
 *
 * @return array
 */
function castleschool_accommodation_details() {

  return array(
    1 => array(
      'label' => t('Homestay (single room, half board)'),
      'periods' => array(
        1 => array(
          'start' => array(
            'month' => 1,
            'day' => 1
          ),
          'end' => array(
            'month' => 6,
            'day' => 30
          ),
          'priceperweek' => 145,
        ),
        2 => array(
          'start' => array(
            'month' => 7,
            'day' => 1
          ),
          'end' => array(
            'month' => 8,
            'day' => 28
          ),
          'priceperweek' => 165
        ),
        3 => array(
          'start' => array(
            'month' => 8,
            'day' => 29
          ),
          'end' => array(
            'month' => 12,
            'day' => 31
          ),
          'priceperweek' => 145
        )
      )
    ),
    2 => array(
      'label' => t('Homestay (twin room, half board)'),
      'periods' => array(
        1 => array(
          'start' => array(
            'month' => 1,
            'day' => 1
          ),
          'end' => array(
            'month' => 6,
            'day' => 30
          ),
          'priceperweek' => 125,
        ),
        2 => array(
          'start' => array(
            'month' => 7,
            'day' => 1
          ),
          'end' => array(
            'month' => 8,
            'day' => 28
          ),
          'priceperweek' => 145
        ),
        3 => array(
          'start' => array(
            'month' => 8,
            'day' => 29
          ),
          'end' => array(
            'month' => 12,
            'day' => 31
          ),
          'priceperweek' => 125
        )
      )
    ),
    3 => array(
      'label' => t('Room only (self-catering)'),
      'periods' => array(
        1 => array(
          'start' => array(
            'month' => 1,
            'day' => 1
          ),
          'end' => array(
            'month' => 6,
            'day' => 30
          ),
          'priceperweek' => 125,
        ),
        2 => array(
          'start' => array(
            'month' => 7,
            'day' => 1
          ),
          'end' => array(
            'month' => 8,
            'day' => 28
          ),
          'priceperweek' => 145
        ),
        3 => array(
          'start' => array(
            'month' => 8,
            'day' => 29
          ),
          'end' => array(
            'month' => 12,
            'day' => 31
          ),
          'priceperweek' => 125
        )
      )
    ),
    4 => array(
      'label' => t('Self-catering Twin room'),
      'periods' => array(
        1 => array(
          'start' => array(
            'month' => 1,
            'day' => 1
          ),
          'end' => array(
            'month' => 6,
            'day' => 30
          ),
          'priceperweek' => 105,
        ),
        2 => array(
          'start' => array(
            'month' => 7,
            'day' => 1
          ),
          'end' => array(
            'month' => 8,
            'day' => 28
          ),
          'priceperweek' => 125
        ),
        3 => array(
          'start' => array(
            'month' => 8,
            'day' => 29
          ),
          'end' => array(
            'month' => 12,
            'day' => 31
          ),
          'priceperweek' => 105
        )
      )
    ),
  );
}

/**
 * Returns airport transfer locations and prices.
 *
 * @return array
 */
function castleschool_get_airport_transfer_details() {

  return array(
    0 => array(
      'label' => t('I do not require an airport transfer'),
      'price' => 0,
    ),
    1 => array(
      'label' => t('London Gatwick Airport'),
      'price' => 80,
    ),
    2 => array(
      'label' => t('London Heathrow Airport'),
      'price' => 130,
    ),
    3 => array(
      'label' => t('London Stanstead Airport'),
      'price' => 160,
    ),
    4 => array(
      'label' => t('London Luton Airport'),
      'price' => 160,
    ),
  );
}

/**
 * Returns airport transfer type options.
 *
 * @return array
 */
function castleschool_get_airport_transfer_type_details() {

  return array(
    0 => t('- Select -'),
    1 => t('Arrival Transfer'),
    2 => t('Departure Transfer'),
    3 => t('Arrival & Departure Transfer'),
  );
}

/**
 * Returns an array of courses and pricing tiers.
 *
 * @param int $courseid Optional specific course filter by Id
 * @return array
 */
function castleschool_course_details($courseid=null) {

  $coursedetails = array(
    1 => array(
      'name'=> t('General English'),
      'pricetiers' => array(
        1 => array(
          'weeks' => array(
            'from' => 2,
            'to' => 3,
          ),
          'hoursperweek-priceperweek' => array(
            15 => 120,
            21 => 160,
            24 => 180,
            30 => 215
          ),
        ),
        2 => array (
          'weeks' => array(
            'from' => 4,
            'to' => 11,
          ),
          'hoursperweek-priceperweek' => array(
            15 => 115,
            21 => 155,
            24 => 175,
            30 => 210
          ),
        ),
        3 => array (
          'weeks' => array(
            'from' => 12,
            'to' => 23,
          ),
          'hoursperweek-priceperweek' => array(
            15 => 110,
            21 => 150,
            24 => 170,
            30 => 205
          ),
        ),
        4 => array (
          'weeks' => array(
            'from' => 24,
            'to' => 35,
          ),
          'hoursperweek-priceperweek' => array(
            15 => 105,
            21 => 145,
            24 => 165,
            30 => 200
          ),
        ),
        5 => array (
          'weeks' => array(
            'from' => 36,
            'to' => 52,
          ),
          'hoursperweek-priceperweek' => array(
            15 => 100,
            21 => 140,
            24 => 160,
            30 => 195,
          ),
        ),
      ),
    ),
    2 => array(
      'name' => t('Cambridge Exam Prep'),
      'pricetiers' => array(
        1 => array(
          'weeks' => array(
            'from' => 2,
            'to' => 3,
          ),
          'hoursperweek-priceperweek' => array(
            15 => 120,
            21 => 160,
          ),
        ),
        2 => array (
          'weeks' => array(
            'from' => 4,
            'to' => 11,
          ),
          'hoursperweek-priceperweek' => array(
            15 => 115,
            21 => 155,
          ),
        ),
        3 => array (
          'weeks' => array(
            'from' => 12,
            'to' => 23,
          ),
          'hoursperweek-priceperweek' => array(
            15 => 110,
            21 => 150,
          ),
        ),
        4 => array (
          'weeks' => array(
            'from' => 24,
            'to' => 35,
          ),
          'hoursperweek-priceperweek' => array(
            15 => 105,
            21 => 145,
          ),
        ),
        5 => array (
          'weeks' => array(
            'from' => 36,
            'to' => 52,
          ),
          'hoursperweek-priceperweek' => array(
            15 => 100,
            21 => 140,
          ),
        ),
      ),
    ),
    3 => array(
      'name' => t('IELTS'),
      'pricetiers' => array(
        1 => array(
          'weeks' => array(
            'from' => 2,
            'to' => 3,
          ),
          'hoursperweek-priceperweek' => array(
            15 => 120,
          ),
        ),
        2 => array (
          'weeks' => array(
            'from' => 4,
            'to' => 11,
          ),
          'hoursperweek-priceperweek' => array(
            15 => 115,
          ),
        ),
        3 => array (
          'weeks' => array(
            'from' => 12,
            'to' => 23,
          ),
          'hoursperweek-priceperweek' => array(
            15 => 110,
          ),
        ),
        4 => array (
          'weeks' => array(
            'from' => 24,
            'to' => 35,
          ),
          'hoursperweek-priceperweek' => array(
            15 => 105,
          ),
        ),
        5 => array (
          'weeks' => array(
            'from' => 36,
            'to' => 52,
          ),
          'hoursperweek-priceperweek' => array(
            15 => 100,
          ),
        ),
      ),
    ),
    4 => array(
      'name' => t('One to one'),
      'pricetiers' => array(
        1 => array(
          'weeks' => array(
            'from' => 2,
            'to' => 52,
          ),
          'hoursperweek-priceperweek' => array(
            10 => 350,
          ),
        ),
      ),
    )
  );

  if ($courseid) {
    return $coursedetails[$courseid];
  } else {
    return $coursedetails;
  }
}

/**
 * Returns airport transfer options.
 *
 * @return array
 */
function castleschool_get_airport_transfer_options() {

  $airporttransferoptions = array();
  $airporttransferinfo = castleschool_get_airport_transfer_details();

  foreach ($airporttransferinfo as $airporttransferid => $airporttransferdetails) {
    $airporttransferoptions[$airporttransferid] = $airporttransferdetails['label'];
  }

  return $airporttransferoptions;
}

/**
 * Returns airport transfer name from passed airport transfer Id.
 *
 * @param int $airporttransferid Airport transfer Id
 * @return string
 */
function castleschool_get_airport_transfer_location($airportid) {

  $airporttransferdetails = castleschool_get_airport_transfer_details();

  return $airporttransferdetails[$airportid]['label'];
}

/**
 * Returns airport transfer type name from passed airport transfer type Id.
 *
 * @param int $airporttransferid
 * @return string
 */
function castleschool_get_airport_transfer_type($airporttransferid) {

  $airporttransfertypedetails = castleschool_get_airport_transfer_type_details();

  return $airporttransfertypedetails[$airporttransferid];
}

/**
 * Returns course name from passed course Id.
 *
 * @param int $courseid Course Id
 * @return string
 */
function castleschool_get_course_name($courseid) {

  $courses = castleschool_get_course_names();

  return $courses[$courseid];
}

/**
 * Returns an associative array of course ids and course names.
 *
 * @return array
 */
function castleschool_get_course_names() {

  $courses = array();
  $coursedetails = castleschool_course_details();

  foreach ($coursedetails as $courseid => $coursedetail) {
    $courses[$courseid] = $coursedetail['name'];
  }

  return $courses;
}

/**
 * Returns an associative array of weekly hours available values and labels.
 * for passed course by id.
 *
 * @param int $courseid Course Id
 * @param int $weeksselected Weeks selected
 * @return array
 */
function castleschool_get_hoursperweek($courseid, $weeksselected) {

  $hoursperweek = array();
  $coursedetails = castleschool_course_details($courseid);

  foreach ($coursedetails['pricetiers'] as $pricetiers => $coursedetail) {
    if ($weeksselected >= $coursedetail['weeks']['from'] && $weeksselected <= $coursedetail['weeks']['to']) {
      foreach ($coursedetail['hoursperweek-priceperweek'] as $hours => $price) {
        $hoursperweek[$hours] = $hours . t(' hours per week');
      }
      break;
    }
  }

  return $hoursperweek;
}

/**
 * Returns an associative array of the next 18 months as
 * timestamps and friendly name values.
 *
 * @return array
 */
function castleschool_get_months() {

  $months = array();
  $startmonth = (int) date('n');
  $monthdays = (int) date('t');
  $mondaysinthismonth = array();

  for ($i = (int) date('j') + 1; $i <= $monthdays; $i++) {
    if ((date('w', mktime(0, 0, 0, $startmonth, $i))) == 1) {
      $mondaysinthismonth[] = 1;
    }
  }

  if (empty($mondaysinthismonth)) {
    $startmonth += 1;
  }

  for ($i = $startmonth; $i < $startmonth + 18; $i++) {
    $months[mktime(0, 0, 0, $i, 1)] = date('F Y', mktime(0, 0, 0, $i, 1));
  }

  return $months;
}

/**
 * Returns an associative array of timestamps and friendly name values
 * for every Monday in the passed month timestamp.
 *
 * @param int $timestamp
 * @return array
 */
function castleschool_get_mondays_in_month($monthtimestamp) {

  $mondays = array();

  for ($i = 1; $i <= 7; $i++) {
    $timestamp = mktime(0, 0, 0, date('n', $monthtimestamp), $i, date('Y', $monthtimestamp));
    if (date('N', $timestamp) == 1) {
      $firstmondaytimestamp = $timestamp;
      break;
    }
  }
  $mondaytimestamp = $firstmondaytimestamp;
  $lastmonthdaytimestamp = mktime(0, 0, 0, date('n', $monthtimestamp),
      date('t', $monthtimestamp), date('Y', $monthtimestamp));

  $now = time();
  while ($mondaytimestamp < $lastmonthdaytimestamp) {
    if ($mondaytimestamp > $now) {
      $mondays[$mondaytimestamp] = date('l jS', $mondaytimestamp);
    }
    $mondaytimestamp = strtotime('+1 week', $mondaytimestamp);
  }

  return $mondays;
}

/**
 * Returns date formatted string of overall start and end dates
 *
 * @param int $startdate Timestamp of start date
 * @param int $weeks Number of weeks of course
 * @return string
 */
function castleschool_get_overall_dates() {

  if ((isset($_SESSION['accommodationstartdate']) && $_SESSION['accommodationstartdate'])
      && (isset($_SESSION['accommodationduration']) && $_SESSION['accommodationduration'])) {
    if (isset($_SESSION['castleschool_weeks']) && $_SESSION['castleschool_weeks'] > $_SESSION['accommodationduration']) {
      $durationindays = $_SESSION['castleschool_weeks'] * 7;
      return date('M j, Y', $_SESSION['accommodationstartdate'])
          . ' - ' . date('M j, Y', strtotime("+{$durationindays} day", $_SESSION['accommodationstartdate']));
    } else {
      return castleschool_get_accommodation_dates($_SESSION['accommodationstartdate'], $_SESSION['castleschool_weeks']);
    }
  } else if ((isset($_SESSION['castleschool_day']) && $_SESSION['castleschool_day'])
      && (isset($_SESSION['castleschool_weeks']) && $_SESSION['castleschool_weeks'])) {
    return castleschool_get_course_dates($_SESSION['castleschool_day'], $_SESSION['castleschool_weeks']);
  }
}

/**
 * Returns date formatted string of accommodation start and end dates
 *
 * @param int $startdate Timestamp of start date
 * @param int $weeks Number of weeks of course
 * @return string
 */
function castleschool_get_accommodation_dates($startdate, $weeks) {

  $durationindays = $weeks * 7;

  return date('M j, Y', $startdate) . ' - ' . date('M j, Y', strtotime("+{$durationindays} day", $startdate));
}

/**
 * Returns date formatted string of course start and end dates
 *
 * @param int $startdate Timestamp of start date
 * @param int $weeks Number of weeks of course
 * @return string
 */
function castleschool_get_course_dates($startdate, $weeks) {

  $durationindays = ($weeks * 7) - 3;

  return date('M j, Y', $startdate) . ' - ' . date('M j, Y', strtotime("+{$durationindays} day", $startdate));
}

/**
 * Returns HTML to populate the quote summary block.
 *
 * @return string
 */
function castleschool_quotesummary_content() {

  $coursequote = $_SESSION['castleschool_coursequote'] + castleschool_get_registration_fee();
  $accommodationtotal = ($_SESSION['accommodationtotal']) ?
      $_SESSION['accommodationtotal'] : 0;
  $airporttransferquote = ($_SESSION['airporttransferquote']) ? $_SESSION['airporttransferquote'] : 0;
  $quotetotal = $coursequote + $accommodationtotal + $airporttransferquote;

  $markup = '<h4>Quote summary</h4>';
  $markup .= '<h6><span id="summary-course-details">' . castleschool_get_course_name($_SESSION['castleschool_course']);
  $markup .= '<br/>' . $_SESSION['castleschool_hoursperweek'] . t(' hours per week');
  $markup .= '<br/>' . castleschool_get_overall_dates() . '</span></h6>';
  $markup .= '<div class="castleschool-quote-summary-price">';
  $markup .= '<div class="castleschool-quote-summary-price-item">';
  $markup .= '<h6>' . t('Course') . '</h6>';
  $markup .= '</div>';
  $markup .= '<div class="castleschool-quote-summary-price-ammount">';
  $markup .= '<h6>£<span id="summary-course-quote">' . $coursequote . '</span></h6>';
  $markup .= '</div>';
  $markup .= '</div>';
  $markup .= '<div class="castleschool-quote-summary-price">';
  $markup .= '<div class="castleschool-quote-summary-price-item">';
  $markup .= '<h6>' . t('Accommodation') . '</h6>';
  $markup .= '</div>';
  $markup .= '<div class="castleschool-quote-summary-price-ammount">';
  $markup .= '<h6>£<span id="summary-accommodation-quote">' . $accommodationtotal . '</span<</h6>';
  $markup .= '</div>';
  $markup .= '</div>';
  $markup .= '<div class="castleschool-quote-summary-price">';
  $markup .= '<div class="castleschool-quote-summary-price-item">';
  $markup .= '<h6>' . t('Optional Extras') . '</h6>';
  $markup .= '</div>';
  $markup .= '<div class="castleschool-quote-summary-price-ammount">';
  $markup .= '<h6>£<span id="summary-extras-quote">' . $airporttransferquote . '</span></h6>';
  $markup .= '</div>';
  $markup .= '</div>';
  $markup .= '<div class="castleschool-quote-summary-totalprice">';
  $markup .= '<div class="castleschool-quote-summary-totalprice-item">';
  $markup .= '<h5>' . t('Total Price') . '</h5>';
  $markup .= '</div>';
  $markup .= '<div class="castleschool-quote-summary-totalprice-ammount">';
  $markup .= '<h5>£<span id="summary-quote-total">' . $quotetotal . '</span></h5>';
  $markup .= '</div>';
  $markup .= '</div>';

  return $markup;
}

/**
 * Accommodation selected action
 *
 * @param int $selection
 */
function castleschool_accommodation_selected($selection) {

  if ($selection) {
    $_SESSION['accommodationid'] = $selection;
    $accommodationdetails = castleschool_accommodation_details();
    $_SESSION['accommodationchoice'] = $accommodationdetails[$selection]['label'];
    $_SESSION['accommodationstartdate'] = strtotime(date('M j, Y', strtotime("-1 day", $_SESSION['castleschool_day'])));
    $_SESSION['accommodationtotal'] = castleschool_calculate_accommodation_quote($selection);
  } else {
    unset($_SESSION['accommodationid']);
    unset($_SESSION['accommodationchoice']);
    unset($_SESSION['accommodationstartdate']);
    unset($_SESSION['accommodationtotal']);
    unset($_SESSION['accommodationduration']);
  }

  drupal_goto('airport-transfers');
}

/**
 * Echos course quote value
 *
 * @param int $course
 * @param int $hoursperweek
 * @param int $weeks
 */
function castleschool_get_course_quote($course, $hoursperweek, $weeks) {

  echo castleschool_get_coursequote($course, $hoursperweek, $weeks) + castleschool_get_registration_fee();
}

/**
 * Echos extra options quote value
 *
 * @param int $airportid
 * @param int $arrivaldeparture
 */
function castleschool_get_extras_quote($airportid, $arrivaldeparture) {

  if ($arrivaldeparture == 0) {
    $_SESSION['whichairport'] = 0;
    $_SESSION['arrivaldeparture'] = 0;
    $_SESSION['airporttransferquote'] = 0;
    echo '0';
  } else {
    $airportdetails = castleschool_get_airport_transfer_details();
    $airporttransferprice = $airportdetails[$airportid]['price'];
    if ($arrivaldeparture == 3) {
      $airporttransferprice *= 2;
    }
    $_SESSION['whichairport'] = $airportid;
    $_SESSION['arrivaldeparture'] = $arrivaldeparture;
    $_SESSION['airporttransferquote'] = $airporttransferprice;
    echo $airporttransferprice;
  }
}

/**
 * Echos accommodation quote total
 *
 * @param int $accommodationduration
 */
function castleschool_get_accommodation_quote($accommodationduration) {

  if ($accommodationduration == 0) {
    unset($_SESSION['accommodationid']);
  }

  if (isset($_SESSION['accommodationid'])) {
    $accommodationdetails = castleschool_accommodation_details();
    $weeklyaccommodationprice = $accommodationdetails[$_SESSION['accommodationid']]['priceperweek'];
  } else {
    $weeklyaccommodationprice = 0;
  }
  $accommodationtotal = $weeklyaccommodationprice * $accommodationduration;

  $_SESSION['accommodationduration'] = $accommodationduration;
  $_SESSION['accommodationtotal'] = $accommodationtotal;

  echo $accommodationtotal;
}

/**
 * Echos accommodation from value
 *
 * @param int $duration
 */
function castleschool_get_accommodation_from_quote($duration, $timestamp) {

  $lowestweeklyprice = '';
  $accommodationdetails = castleschool_accommodation_details();

  foreach ($accommodationdetails as $accommodationid => $accommodationitem) {
    $accommodationquote = castleschool_calculate_accommodation_quote($accommodationid, $timestamp, $duration);
    if (($accommodationquote < $lowestweeklyprice) || ($lowestweeklyprice == '')) {
      $lowestweeklyprice = $accommodationquote;
    }
  }

  echo $lowestweeklyprice;
}

/**
 * Echos quote total value
 *
 * @param int $coursequotetotal
 * @param int $accommodationquotetotal
 * @param int $optionalextrasquotetotal
 */
function castleschool_get_summary_quote_total($coursequotetotal, $accommodationquotetotal, $optionalextrasquotetotal) {

  echo $coursequotetotal + $accommodationquotetotal + $optionalextrasquotetotal;
}

/**
 * Returns course quote value
 *
 * @param int $course
 * @param int $hoursperweek
 * @param int $weeks
 * @return int
 */
function castleschool_get_coursequote($course, $hoursperweek, $weeks) {

  $coursedetails = castleschool_course_details();
  $pricetiers = $coursedetails[$course]['pricetiers'];

  foreach ($pricetiers as $pricetier => $conditions) {
    if ($weeks >= $conditions['weeks']['from'] && $weeks <= $conditions['weeks']['to']) {
      $priceperweek = $conditions['hoursperweek-priceperweek'][$hoursperweek];
      break;
    }
  }

  return $priceperweek * $weeks;
}

/**
 * Returns start date options
 *
 * @return array
 */
function castleschool_get_startdate() {

  $nextmonday = strtotime('next monday');
  $firstmonday = mktime(0, 0, 0, date('n', $nextmonday), date('j', $nextmonday), date('Y', $nextmonday));
  $lastmonday = strtotime('+72 week', $firstmonday);

  $startdates = array();
  $startdate = $firstmonday;

  while ($startdate < $lastmonday) {
    $startdates[$startdate] = date('F j, Y', $startdate);
    $startdate = strtotime('+1 week', $startdate);
  }

  return $startdates;
}

/**
 * Echos course summary details
 *
 * @param int $course
 * @param int $hoursperweek
 * @param int $startdate
 * @param int $weeks
 */
function castleschool_get_course_summary_details($course, $hoursperweek, $startdate, $weeks) {

  $_SESSION['castleschool_day'] = $startdate;
  $_SESSION['castleschool_weeks'] = $weeks;

  echo castleschool_get_course_name($course) . '<br/>' . $hoursperweek . t(' hours per week')
      . '<br>' . castleschool_get_overall_dates();
}

/**
 * Return accommodation option total amount from passed Id
 *
 * @param int $accommodationid Accommodation type Id
 * @param int $coursestartdate Unix timestamp of course start date
 * @param int $duration Number of weeks accommodation required
 * @return int
 */
function castleschool_calculate_accommodation_quote($accommodationid, $coursestartdate=null, $duration=null) {

  $accommodationoptiontotal = 0;
  $accommodationfindingfee = castleschool_get_accommodation_finding_fee();
  $accommodationprices = castleschool_accommodation_details();

  if (is_null($coursestartdate)) {
    $coursestartdate = $_SESSION['castleschool_day'];
  }

  if (is_null($duration)) {
    $duration = $_SESSION['accommodationduration'];
  }

  $accommodationstartdate = $coursestartdate - 24 * 60 * 60; // 1 day prior
  $weekstarttimestamp = $accommodationstartdate;
  $accommodationoptionperiods = $accommodationprices[$accommodationid]['periods'];

  for ($i = 1; $i <= $duration; $i++) {

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

/**
 * Returns HTML for Course Bookings Administration Page
 *
 * @return string
 */
function castleschool_show_course_bookings() {

  $query = db_query('SELECT cb.booking_id, cc.course_name,  cb.firstname, cb.lastname, cb.created AS booking_created
                    FROM {castleschool_bookings} cb
                    JOIN {castleschool_courses} cc ON cc.course_id = cb.course_id
                    ORDER BY booking_id DESC');
  $bookings = $query->fetchAll();

  $t = get_t();

  $markup = '<table>';
  $markup .= '<tr>';
  $markup .= "<th>{$t('Booking ID')}</th>";
  $markup .= "<th>{$t('Name')}</th>";
  $markup .= "<th>{$t('Date')}</th>";
  $markup .= "<th>{$t('Course')}</th>";
  $markup .= "<th>{$t('Status')}</th>";
  $markup .= "<th>{$t('Actions')}</th>";
  $markup .= '</tr>';

  foreach ($bookings as $booking) {
    $markup .= '<tr>';
    $markup .= "<td>{$booking->booking_id}</td>";
    $markup .= "<td>{$booking->firstname} {$booking->lastname}</td>";
    $markup .= '<td>' . date('jS M Y H:i', $booking->booking_created) . '</td>';
    $markup .= "<td>{$booking->course_name}</td>";
    $markup .= "<td>Pending</td>";
    $markup .= "<td><a href='/admin/settings/castleschool/coursebookings/view/{$booking->booking_id}'>View</a></td>";
    $markup .= '</tr>';
  }

  $markup .= '</table>';

  $form['quotetable'] = array(
    '#markup' => $markup,
  );

  return $form;
}