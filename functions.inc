<?php

/**
 * Returns Castle School Worldpay Installation Id.
 *
 * @return int
 */
function castleschool_get_worldpay_instid() {

  return 1213743;
}

/**
 * Returns registration fee value.
 *
 * @return int
 */
function castleschool_get_registration_fee() {

  return variable_get('registration_fee', 60);
}

/**
 * Returns accommodation finding fee value.
 *
 * @return int
 */
function castleschool_get_accommodation_finding_fee() {

  return variable_get('accommodation_finding_fee', 50);
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
  while ($mondaytimestamp <= $lastmonthdaytimestamp) {
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
 * Returns HTML to populate the payment confirmation block.
 *
 * @param int $bookingid The Booking Id
 * @return string
 */
function castleschool_payment_confirmation_content($bookingid) {

  if (!empty($bookingid)) {
    $markup = "<p>Your payment for booking Id {$bookingid} has been confirmed.</p>";
    $markup  = "<p>Thank you - your payment for Booking Id {$bookingid} has been authorised.</p>";
    $markup .= '<p>You will receive booking and payment confirmation emails which are your confirmation of this booking and this payment.</p>';
    $markup .= '<p>If you have any questions, please call +44 (0) 1273 748185</p>';
  } else {
    $markup = "<p>No booking Id found.</p>";
  }

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

  $sql = "SELECT cb.booking_id, cc.course_name,  cb.firstname, cb.lastname, cb.created AS booking_created, cbs.status_label AS status,
                 total_booking_fee, outstanding_fee
            FROM {castleschool_bookings} cb
            JOIN {castleschool_courses} cc ON cc.course_id = cb.course_id
            JOIN castleschool_booking_status cbs ON cbs.status_id = cb.status_id
        ORDER BY booking_id DESC";

  $query = db_query($sql);
  $bookings = $query->fetchAll();

  $t = get_t();

  $markup = '<table>';
  $markup .= '<tr>';
  $markup .= "<th>{$t('Booking ID')}</th>";
  $markup .= "<th>{$t('Booking Date')}</th>";
  $markup .= "<th>{$t('Student Name')}</th>";
  $markup .= "<th>{$t('Course')}</th>";
  $markup .= "<th>{$t('Total Fee')}</th>";
  $markup .= "<th>{$t('Outstanding Fee')}</th>";
  $markup .= "<th>{$t('Booking Status')}</th>";
  $markup .= "<th>{$t('Actions')}</th>";
  $markup .= '</tr>';

  foreach ($bookings as $booking) {

    if ($booking->status == 'Pending') {
      $colour = 'lightpink';
    } else if ($booking->status == 'Confirmed') {
      $colour = 'lightgreen';
    } else {
      $colour = 'white';
    }

    $markup .= "<tr style='background-color: {$colour}'>";
    $markup .= "<td>{$booking->booking_id}</td>";
    $markup .= '<td>' . date('M j, Y g:i:s A', $booking->booking_created) . '</td>';
    $markup .= "<td>{$booking->firstname} {$booking->lastname}</td>";
    $markup .= "<td>{$booking->course_name}</td>";
    $markup .= "<td>&pound;{$booking->total_booking_fee}</td>";
    $markup .= "<td>&pound;{$booking->outstanding_fee}</td>";
    $markup .= "<td>{$booking->status}</td>";
    $markup .= "<td>";
    $markup .= "<a href='/admin/settings/castleschool/coursebookings/{$booking->booking_id}'>View</a>";
    if ($booking->outstanding_fee > 0) {
      $markup .= " | <a href='/admin/settings/castleschool/coursebookings/{$booking->booking_id}/payment'>Make payment</a>";
    }
    $markup .= "</td>";
    $markup .= '</tr>';
  }

  $markup .= '</table>';

  $form['bookingstable'] = array(
    '#markup' => $markup,
  );

  return $form;
}

/**
 * Returns FORM of booking detail values
 * @todo: Return HTML for Course Bookings Administration Page
 *
 * @param type $bookingid
 * @return string
 */
function castleschool_show_course_booking_details($bookingid) {

  $sql = "SELECT cb.firstname, cb.lastname, cb.date_of_birth, cb.gender, cb.nationality, cb.passport_or_idnumber, cb.telephone, cb.email,
                 cb.address1, cb.address2, cb.towncity, cb.region, cb.postcode, cb.country, cb.nextofkin_name, cb.nextofkin_telephone,
                 cb.nextofkin_address, cb.smokes, cb.medical_conditions, cb.animal_allergies,
                 cc.course_name, cb.hours_per_week, cb.course_startdate, cb.course_enddate, cb.course_length_weeks,
                 cb.course_fee, cb.registration_fee, at.accommodation_type_name, cb.accommodation_start_date, cb.accommodation_end_date,
                 cb.accommodation_duration_weeks, cb.accommodation_fee, cb.accommodation_finding_fee, att.airport_transfer_type_label,
                 atsor.airport_transfer_singleorreturn_label, cb.airport_transfer_fee, cb.total_booking_fee
            FROM castleschool_bookings cb
            JOIN castleschool_courses cc ON cc.course_id = cb.course_id
       LEFT JOIN castleschool_accommodation_types at ON at.accommodation_type_id = cb.accommodation_type_id
       LEFT JOIN castleschool_airport_transfer_types att ON att.airport_transfer_type_id = cb.airport_transfer_type_id
       LEFT JOIN castleschool_airport_transfer_singleorreturn atsor ON atsor.airport_transfer_singleorreturn = cb.airport_transfer_singleorreturn
           WHERE cb.booking_id = :bookingid";
  $query = db_query($sql, array('bookingid' => $bookingid));
  $booking = $query->fetchAssoc();

  $markup  = '';
  $markup .= '<div class="table-responsive">';
  $markup .= '<table class="table table-bordered table-striped">';
  $markup .= '<thead>';
  $markup .= '<tr class="info">';
  $markup .= '<th colspan="4" width="100%">';
  $markup .= '<p class="text-left" style="margin-bottom: 0;"><strong>Student</strong></p>';
  $markup .= '</th>';
  $markup .= '</tr>';
  $markup .= '</thead>';
  $markup .= '<tbody>';
  $markup .= '<tr>';
  $markup .= '<td width="18%">';
  $markup .= '<p class="text-left"><strong>Name:</strong></p>';
  $markup .= '</td>';
  $markup .= '<td width="32%">';
  $markup .= '<p class="text-left">' . $booking['firstname'] . ' ' . $booking['lastname'] . '</p>';
  $markup .= '</td>';
  $markup .= '<td width="18%" rowspan="3" style="vertical-align:top;">';
  $markup .= '<p class="text-left"><strong>Address:</strong></p>';
  $markup .= '</td>';
  $markup .= '<td width="32%" rowspan="3" style="vertical-align:top;">';
  $address = $booking['address1'] . '<br/>';
  if ($booking['address2'] != '') {
    $address .= $booking['address2'] . '<br/>';
  }
  $address .= $booking['towncity'] . '<br/>' . $booking['region'] . '<br/>' . $booking['postcode'] . '<br/>' . $booking['country'];
  $markup .= '<p class="text-left">' . $address . '</p>';
  $markup .= '</td>';
  $markup .= '</tr>';
  $markup .= '<tr>';
  $markup .= '<td width="18%">';
  $markup .= '<p class="text-left"><strong>Date of birth:</strong></p>';
  $markup .= '</td>';
  $markup .= '<td width="32%">';
  $markup .= '<p class="text-left">' . date('F jS, Y', strtotime($booking['date_of_birth'])) . '</p>';
  $markup .= '</td>';
  $markup .= '</tr>';
  $markup .= '<tr>';
  $markup .= '<td width="18%">';
  $markup .= '<p class="text-left"><strong>Email:</strong></p>';
  $markup .= '</td>';
  $markup .= '<td width="32%">';
  $markup .= '<p class="text-left"><a href="mailto:' . $booking['email'] . '">' . $booking['email'] . '</a></p>';
  $markup .= '</td>';
  $markup .= '</tr>';
  $markup .= '<tr>';
  $markup .= '<td width="18%">';
  $markup .= '<p class="text-left"><strong>Telephone:</strong></p>';
  $markup .= '</td>';
  $markup .= '<td width="32%">';
  $markup .= '<p class="text-left">' . $booking['telephone'] . '</p>';
  $markup .= '</td>';
  $markup .= '<td>';
  $markup .= '<p><strong>Next of kin name:</strong></p>';
  $markup .= '</td>';
  $markup .= '<td>';
  $markup .= '<p>' . $booking['nextofkin_name'] . '</p>';
  $markup .= '</td>';
  $markup .= '</tr>';
  $markup .= '<tr>';
  $markup .= '<td>';
  $markup .= '<p><strong>Gender:</strong</p>';
  $markup .= '</td>';
  $markup .= '<td>';
  $markup .= '<p>' . $booking['gender'] . '</p>';
  $markup .= '</td>';
  $markup .= '<td>';
  $markup .= '<p><strong>Next of kin telephone:</strong</p>';
  $markup .= '</td>';
  $markup .= '<td>';
  $markup .= '<p>' . $booking['nextofkin_telephone'] . '</p>';
  $markup .= '</td>';
  $markup .= '</tr>';
  $markup .= '<tr>';
  $markup .= '<td>';
  $markup .= '<p><strong>Nationality:</strong</p>';
  $markup .= '</td>';
  $markup .= '<td>';
  $markup .= '<p>' . $booking['nationality'] . '</p>';
  $markup .= '</td>';
  $markup .= '<td>';
  $markup .= '<p><strong>Next of kin address:</strong</p>';
  $markup .= '</td>';
  $markup .= '<td>';
  $markup .= '<p>' . $booking['nextofkin_address'] . '</p>';
  $markup .= '</td>';
  $markup .= '</tr>';
  $markup .= '<tr>';
  $markup .= '<td>';
  $markup .= '<p><strong>Passport/ID number:</strong</p>';
  $markup .= '</td>';
  $markup .= '<td>';
  $markup .= '<p>' . $booking['passport_or_idnumber'] . '</p>';
  $markup .= '</td>';
  $markup .= '<td>';
  $markup .= '<p><strong>Smokes:</strong</p>';
  $markup .= '</td>';
  $markup .= '<td>';
  $markup .= '<p>' . $booking['smokes'] . '</p>';
  $markup .= '</td>';
  $markup .= '</tr>';
  $markup .= '<tr>';
  $markup .= '<td>';
  $markup .= '<p><strong>Medical conditions:</strong</p>';
  $markup .= '</td>';
  $markup .= '<td>';
  $markup .= '<p>' . $booking['medical_conditions'] . '</p>';
  $markup .= '</td>';
  $markup .= '<td>';
  $markup .= '<p><strong>Animal allergies:</strong</p>';
  $markup .= '</td>';
  $markup .= '<td>';
  $markup .= '<p>' . $booking['animal_allergies'] . '</p>';
  $markup .= '</td>';
  $markup .= '</tr>';
  $markup .= '</tbody>';
  $markup .= '</table>';
  $markup .= '</div>';

  $markup .= '<div class="table-responsive">';
  $markup .= '<table class="table table-bordered table-striped">';
  $markup .= '<thead>';
  $markup .= '<tr class="info">';
  $markup .= '<th width="65%">';
  $markup .= '<p class="text-left" style="margin-bottom: 0;"><strong>Course</strong></p>';
  $markup .= '</th>';
  $markup .= '<th class="price" style="text-align: right;" width="35%">';
  $markup .= '<p style="margin-bottom: 0;"><strong>Price</strong></p>';
  $markup .= '</th>';
  $markup .= '</tr>';
  $markup .= '</thead>';
  $markup .= '<tbody>';
  $markup .= '<tr>';
  $markup .= '<td>';
  $markup .= '<p class="text-left">' . $booking['course_name'] . ' - ' . $booking['hours_per_week'] . ' hours per week<br>' . date('M j, Y', $booking['course_startdate']) . ' - ' . date('M j, Y', $booking['course_enddate']) . '<br>Length: ' . $booking['course_length_weeks'] . ' weeks</p>';
  $markup .= '</td>';
  $markup .= '<td class="price" style="text-align: right;">';
  $markup .= '<p>&pound;' . $booking['course_fee'] . '</p>';
  $markup .= '</td>';
  $markup .= '</tr>';
  $markup .= '<tr>';
  $markup .= '<td>';
  $markup .= '<p class="text-left">Registration Fee</p>';
  $markup .= '</td>';
  $markup .= '<td class="price" style="text-align: right;">';
  $markup .= '<p>&pound;' . $booking['registration_fee'] . '</p>';
  $markup .= '</td>';
  $markup .= '</tr>';
  $markup .= '</tbody>';
  $markup .= '</table>';
  $markup .= '</div>';

  if (isset($booking['accommodation_fee']) && $booking['accommodation_fee'] > 0) {
    $markup .= '<div class="table-responsive">';
    $markup .= '<table class="table table-bordered table-striped">';
    $markup .= '<thead>';
    $markup .= '<tr class="info">';
    $markup .= '<th width="65%">';
    $markup .= '<p class="text-left" style="margin-bottom: 0;"><strong>Accommodation</strong></p>';
    $markup .= '</th>';
    $markup .= '<th class="price" style="text-align: right;" width="35%">';
    $markup .= '<p style="margin-bottom: 0;"><strong>Price</strong></p>';
    $markup .= '</th>';
    $markup .= '</tr>';
    $markup .= '</thead>';
    $markup .= '<tbody>';
    $markup .= '<tr>';
    $markup .= '<td>';
    $markup .= '<p class="text-left">' . $booking['accommodation_type_name'] . '<br>' . date('M j, Y', $booking['accommodation_start_date']) . ' - ' . date('M j, Y', $booking['accommodation_end_date']) . '<br>Duration: ' . $booking['accommodation_duration_weeks'] . ' weeks</p>';
    $markup .= '</td>';
    $markup .= '<td class="price" style="text-align: right;">';
    $markup .= '<p>&pound;' . $booking['accommodation_fee'] . '</p>';
    $markup .= '</td>';
    $markup .= '</tr>';
    $markup .= '<tr>';
    $markup .= '<td>';
    $markup .= '<p class="text-left">Accommodation finding fee</p>';
    $markup .= '</td>';
    $markup .= '<td class="price" style="text-align: right;">';
    $markup .= '<p>&pound;' . $booking['accommodation_finding_fee'] . '</p>';
    $markup .= '</td>';
    $markup .= '</tr>';
    $markup .= '</tbody>';
    $markup .= '</table>';
    $markup .= '</div>';
  }

  if (isset($booking['airport_transfer_fee']) && $booking['airport_transfer_fee'] > 0) {
    $markup .= '<div class="table-responsive">';
    $markup .= '<table class="table table-bordered table-striped">';
    $markup .= '<thead>';
    $markup .= '<tr class="info">';
    $markup .= '<th width="65%">';
    $markup .= '<p class="text-left" style="margin-bottom: 0;"><strong>Optional Extras</strong></p>';
    $markup .= '</th>';
    $markup .= '<th class="price" style="text-align: right;" width="35%">';
    $markup .= '<p style="margin-bottom: 0;"><strong>Price</strong></p>';
    $markup .= '</th>';
    $markup .= '</tr>';
    $markup .= '</thead>';
    $markup .= '<tbody>';
    $markup .= '<tr>';
    $markup .= '<td>';
    $markup .= '<p class="text-left">' . $booking['airport_transfer_type_label'] . ' - ' . $booking['airport_transfer_singleorreturn_label'] . '</p>';
    $markup .= '</td>';
    $markup .= '<td class="price" style="text-align: right;">';
    $markup .= '<p>&pound;' . $booking['airport_transfer_fee'] . '</p>';
    $markup .= '</td>';
    $markup .= '</tr>';
    $markup .= '</tbody>';
    $markup .= '</table>';
    $markup .= '</div>';
  }

  $markup .= '<div class="table-responsive">';
  $markup .= '<table class="table table-bordered table-striped">';
  $markup .= '<thead>';
  $markup .= '<tr class="info">';
  $markup .= '<th width="65%">';
  $markup .= '<p class="text-left" style="margin-bottom: 0;"><strong>Total Price</strong></p>';
  $markup .= '</th>';
  $markup .= '<th class="price" style="text-align: right;" width="35%">';
  $markup .= '<p style="margin-bottom: 0;"><strong>&pound;' . $booking['total_booking_fee'] . '</strong></p>';
  $markup .= '</th>';
  $markup .= '</tr>';
  $markup .= '</thead>';
  $markup .= '</table>';
  $markup .= '</div>';

  $payments = db_query("SELECT * FROM {castleschool_payments} WHERE booking_id = :bookingid", array('bookingid' => $bookingid))->fetchAll();

  if (!empty($payments)) {
    $markup .= '<div class="table-responsive">';
    $markup .= '<table class="table table-bordered table-striped">';
    $markup .= '<thead>';
    $markup .= '<tr class="info">';
    $markup .= '<th width="25%">';
    $markup .= '<p class="text-left" style="margin-bottom: 0;"><strong>Payment ID</strong></p>';
    $markup .= '</th>';
    $markup .= '<th width="25%">';
    $markup .= '<p class="text-left" style="margin-bottom: 0;"><strong>Payment Date/Time</strong></p>';
    $markup .= '</th>';
    $markup .= '<th width="25%">';
    $markup .= '<p class="text-left" style="margin-bottom: 0;"><strong>WorldPay Transaction ID</strong></p>';
    $markup .= '</th>';
    $markup .= '<th width="25%">';
    $markup .= '<p class="text-left" style="margin-bottom: 0;"><strong>Payment Amount</strong></p>';
    $markup .= '</th>';
    $markup .= '</tr>';
    $markup .= '</thead>';
    $markup .= '<tbody>';
  }

  foreach ($payments as $payment) {
    $worldpaydata = json_decode($payment->worldpay_data);
    $markup .= '<tr>';
    $markup .= '<td>';
    $markup .= $payment->payment_id;
    $markup .= '</td>';
    $markup .= '<td>';
    $markup .= date('M j, Y g:i:s A', $worldpaydata->transTime / 1000);
    $markup .= '</td>';
    $markup .= '<td>';
    $markup .= $worldpaydata->transId;
    $markup .= '</td>';
    $markup .= '<td>';
    $markup .= $worldpaydata->authAmountString;
    $markup .= '</td>';
    $markup .= '</tr>';
  }

  if (!empty($payments)) {
    $markup .= '</tbody>';
    $markup .= '</table>';
    $markup .= '</div>';
  }

  $markup .= '</tbody>';
  $markup .= '</table>';
  $markup .= '</div>';

  $form['bookingdetails'] = array(
    '#markup' => $markup,
  );

  $form['back_button'] = array(
    '#markup' => "<input type='button' class='form-submit' value='Back' onclick=\"window.location='/admin/settings/castleschool/coursebookings';\" />",
  );

  return $form;
}

/**
 * Returns country selection for form.
 *
 * @return array
 */
function castleschool_country_selection() {

  return array(
    "AF" => "Afghanistan",
    "AX" => "Aland Islands",
    "AL" => "Albania",
    "DZ" => "Algeria",
    "AS" => "American Samoa",
    "AD" => "Andorra",
    "AO" => "Angola",
    "AI" => "Anguilla",
    "AQ" => "Antarctica",
    "AG" => "Antigua and Barbuda",
    "AR" => "Argentina",
    "AM" => "Armenia",
    "AW" => "Aruba",
    "AU" => "Australia",
    "AT" => "Austria",
    "AZ" => "Azerbaijan",
    "BS" => "Bahamas",
    "BH" => "Bahrain",
    "BD" => "Bangladesh",
    "BB" => "Barbados",
    "BY" => "Belarus",
    "BE" => "Belgium",
    "BZ" => "Belize",
    "BJ" => "Benin",
    "BM" => "Bermuda",
    "BT" => "Bhutan",
    "BO" => "Bolivia",
    "BQ" => "Bonaire, Sint Eustatius and Saba",
    "BA" => "Bosnia and Herzegovina",
    "BW" => "Botswana",
    "BV" => "Bouvet Island",
    "BR" => "Brazil",
    "IO" => "British Indian Ocean Territory",
    "BN" => "Brunei Darussalam",
    "BG" => "Bulgaria",
    "BF" => "Burkina Faso",
    "BI" => "Burundi",
    "KH" => "Cambodia",
    "CM" => "Cameroon",
    "CA" => "Canada",
    "CV" => "Cape Verde",
    "KY" => "Cayman Islands",
    "CF" => "Central African Republic",
    "TD" => "Chad",
    "CL" => "Chile",
    "CN" => "China",
    "CX" => "Christmas Island",
    "CC" => "Cocos (Keeling) Islands",
    "CO" => "Colombia",
    "KM" => "Comoros",
    "CG" => "Congo",
    "CK" => "Cook Islands",
    "CR" => "Costa Rica",
    "HR" => "Croatia",
    "CU" => "Cuba",
    "CW" => "Curacao",
    "CY" => "Cyprus",
    "CZ" => "Czech Republic",
    "CI" => "Côte d'Ivoire",
    "DK" => "Denmark",
    "DJ" => "Djibouti",
    "DM" => "Dominica",
    "DO" => "Dominican Republic",
    "EC" => "Ecuador",
    "EG" => "Egypt",
    "SV" => "El salvador",
    "GQ" => "Equatorial Guinea",
    "ER" => "Eritrea",
    "EE" => "Estonia",
    "ET" => "Ethiopia",
    "FK" => "Falkland Islands",
    "FO" => "Faroe Islands",
    "FJ" => "Fiji",
    "FI" => "Finland",
    "FR" => "France",
    "GF" => "French Guiana",
    "PF" => "French Polynesia",
    "TF" => "French Southern Territories",
    "GA" => "Gabon",
    "GM" => "Gambia",
    "GE" => "Georgia",
    "DE" => "Germany",
    "GH" => "Ghana",
    "GI" => "Gibraltar",
    "GR" => "Greece",
    "GL" => "Greenland",
    "GD" => "Grenada",
    "GP" => "Guadeloupe",
    "GU" => "Guam",
    "GT" => "Guatemala",
    "GG" => "Guernsey",
    "GN" => "Guinea",
    "GW" => "Guinea-Bissau",
    "GY" => "Guyana",
    "HT" => "Haiti",
    "HM" => "Heard Island and McDonald Islands",
    "VA" => "Holy See (Vatican City State)",
    "HN" => "Honduras",
    "HK" => "Hong Kong",
    "HU" => "Hungary",
    "IS" => "Iceland",
    "IN" => "India",
    "ID" => "Indonesia",
    "IR" => "Iran",
    "IQ" => "Iraq",
    "IE" => "Ireland",
    "IM" => "Isle of Man",
    "IL" => "Israel",
    "IT" => "Italy",
    "JM" => "Jamaica",
    "JP" => "Japan",
    "JE" => "Jersey",
    "JO" => "Jordan",
    "KZ" => "Kazakhstan",
    "KE" => "Kenya",
    "KI" => "Kiribati",
    "KS" => "Kosovo",
    "KW" => "Kuwait",
    "KG" => "Kyrgyzstan",
    "LA" => "Lao",
    "LV" => "Latvia",
    "LB" => "Lebanon",
    "LS" => "Lesotho",
    "LR" => "Liberia",
    "LY" => "Libyan Arab Jamahiriya",
    "LI" => "Liechtenstein",
    "LT" => "Lithuania",
    "LU" => "Luxembourg",
    "MO" => "Macau",
    "MK" => "Macedonia (FYR)",
    "MG" => "Madagascar",
    "MW" => "Malawi",
    "MY" => "Malaysia",
    "MV" => "Maldives",
    "ML" => "Mali",
    "MT" => "Malta",
    "MH" => "Marshall Islands",
    "MQ" => "Martinique",
    "MR" => "Mauritania",
    "MU" => "Mauritius",
    "YT" => "Mayotte",
    "MX" => "Mexico",
    "FM" => "Micronesia",
    "MD" => "Moldova",
    "MC" => "Monaco",
    "MN" => "Mongolia",
    "ME" => "Montenegro",
    "MS" => "Montserrat",
    "MA" => "Morocco",
    "MZ" => "Mozambique",
    "MM" => "Myanmar",
    "NA" => "Namibia",
    "NR" => "Nauru",
    "NP" => "Nepal",
    "NL" => "Netherlands",
    "NC" => "New Caledonia",
    "NZ" => "New Zealand",
    "NI" => "Nicaragua",
    "NE" => "Niger",
    "NG" => "Nigeria",
    "NU" => "Niue",
    "NF" => "Norfolk Island",
    "KP" => "North Korea",
    "MP" => "Northern Mariana Islands",
    "NO" => "Norway",
    "OM" => "Oman",
    "PK" => "Pakistan",
    "PW" => "Palau",
    "PS" => "Palestinian Territory Occupied",
    "PA" => "Panama",
    "PG" => "Papua New Guinea",
    "PY" => "Paraguay",
    "PE" => "Peru",
    "PH" => "Philippines",
    "PN" => "Pitcairn",
    "PL" => "Poland",
    "PT" => "Portugal",
    "PR" => "Puerto Rico",
    "QA" => "Qatar",
    "RE" => "Reunion",
    "RO" => "Romania",
    "RU" => "Russian Federation",
    "RW" => "Rwanda",
    "BL" => "Saint Barthelemy",
    "SH" => "Saint Helena",
    "KN" => "Saint Kitts and Nevis",
    "LC" => "Saint Lucia",
    "MF" => "Saint Martin (French)",
    "PM" => "Saint Pierre and Miquelon",
    "VC" => "Saint Vincent and the Grenadines",
    "WS" => "Samoa",
    "SM" => "San Marino",
    "ST" => "Sao Tome and Principe",
    "SA" => "Saudi Arabia",
    "SN" => "Senegal",
    "RS" => "Serbia",
    "SC" => "Seychelles",
    "SL" => "Sierra Leone",
    "SG" => "Singapore",
    "SX" => "Sint Maarten (Dutch)",
    "SK" => "Slovakia",
    "SI" => "Slovenia",
    "SB" => "Solomon Islands",
    "SO" => "Somalia",
    "ZA" => "South Africa",
    "GS" => "South Georgia",
    "KR" => "South Korea",
    "ES" => "Spain",
    "LK" => "Sri Lanka",
    "SD" => "Sudan",
    "SR" => "Suriname",
    "SJ" => "Svalbard and Jan Mayen Islands",
    "SZ" => "Swaziland",
    "SE" => "Sweden",
    "CH" => "Switzerland",
    "SY" => "Syria",
    "TW" => "Taiwan",
    "TJ" => "Tajikistan",
    "TZ" => "Tanzania",
    "TH" => "Thailand",
    "CD" => "The Democratic Republic of the Congo",
    "TL" => "Timor-Leste",
    "TG" => "Togo",
    "TK" => "Tokelau",
    "TO" => "Tonga",
    "TT" => "Trinidad and Tobago",
    "TN" => "Tunisia",
    "TR" => "Turkey",
    "TM" => "Turkmenistan",
    "TC" => "Turks and Caicos Islands",
    "TV" => "Tuvalu",
    "UG" => "Uganda",
    "UA" => "Ukraine",
    "AE" => "United Arab Emirates",
    "GB" => "United Kingdom",
    "US" => "United States",
    "UM" => "United States Minor Outlying Islands",
    "UY" => "Uruguay",
    "UZ" => "Uzbekistan",
    "VU" => "Vanuatu",
    "VE" => "Venezuela",
    "VN" => "Viet Nam",
    "VG" => "Virgin Islands (British)",
    "VI" => "Virgin Islands (U.S.)",
    "WF" => "Wallis and Futuna Islands",
    "EH" => "Western Sahara",
    "YE" => "Yemen",
    "ZM" => "Zambia",
    "ZW" => "Zimbabwe",
  );
}

/**
 * Returns 'Make Course Booking Payment' form
 *
 * @param int $bookingid
 * @return drupal form
 */
function castleschool_make_course_booking_payment($bookingid) {

  return drupal_get_form('castleschool_make_course_booking_payment_form', $bookingid);
}

/**
 * Sets session vars and redirects to Worldpay Payment form
 *
 * @param int $bookingid
 */
function castleschool_course_booking_payment_link($bookingid) {

    $sql = "SELECT outstanding_fee
              FROM castleschool_bookings
             WHERE booking_id = :bookingid";
    $query = db_query($sql, array('bookingid' => $bookingid));
    $booking = $query->fetchAssoc();

    if (isset($booking['outstanding_fee']) && $booking['outstanding_fee'] > 0) {
      $_SESSION['booking_id'] = $bookingid;
      $_SESSION['payment_amount'] = $booking['outstanding_fee'];
      drupal_goto('make-worldpay-payment');
    } else {
      drupal_goto();
    }
}