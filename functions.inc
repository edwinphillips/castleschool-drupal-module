<?php

/**
 * Returns an associative array of course ids and course names.
 *
 * @return array
 */
function castleschool_get_courses() {

  $courses = array();
  $coursedetails = castleschool_course_details();

  foreach ($coursedetails as $courseid => $coursedetail) {
    $courses[$courseid] = $coursedetail['name'];
  }

  return $courses;
}

/**
 * Returns an associative array of weekly hours available values and labels
 * for passed course by id.
 *
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
 * Returns an array of courses and pricing tiers.
 *
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
            24 => 145,
            30 => 140
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

function castleschool_get_airport_transfers() {

  $transfers = array();

  return $transfers;
}
/**
 * Returns an associative array of the next 18 months as
 * timestamps and friendly name values.
 *
 * @return array
 */
function castleschool_get_months() {

  $months = array();
  $startmonth = (int)date('n');

  $monthdays = (int)date('t');
  $mondaysinthismonth = array();
  for ($i = (int)date('j') + 1; $i <= $monthdays; $i++) {
    if ((date('w', mktime(0, 0, 0, $startmonth, $i))) == 1) {
      $mondaysinthismonth[] = 1;
    }
  }

  if (empty($mondaysinthismonth)) {
    $startmonth += 1;
  }

  for ($x = $startmonth; $x < $startmonth + 18; $x++) {
    $months[mktime(0, 0, 0, $x, 1)] = date('F Y', mktime(0, 0, 0, $x, 1));
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
function castleschool_get_mondays_in_month($timestamp) {

  $now = time();
  $mondays = array();

  $start = date('N', $timestamp);
  $month = date('m', $timestamp);

  $closest_monday = $timestamp - ($start - 1) * 60 * 60 * 24;

  if ($month == date('m', $closest_monday)) {
    if ($closest_monday > $now) {
      $mondays[$closest_monday] = date( 'l jS', $closest_monday);
    }
  } else {
    $closest_monday = $timestamp + (8 - $start) * 60 * 60 * 24;
    if ($closest_monday > $now) {
      $mondays[$closest_monday] = date('l jS', $closest_monday);
    }
  }

  for ($i = 1; $i < 6; $i++) {
    $prev = $closest_monday - $i * 7 * 60 * 60 * 24;
    $next = $closest_monday + $i * 7 * 60 * 60 * 24;
    if ($month == date('m', $next)) {
      if ($next > $now) {
        $mondays[$next] = date('l jS', $next);
      }
    }
    if ($month == date('m', $prev)) {
      if ($prev > $now) {
        $mondays[$prev] = date('l jS', $prev);
      }
    }
  }
  ksort($mondays);

  return $mondays;
}

/**
 * Returns HTML to populate the quote summary block.
 *
 * @return string
 */
function castleschool_quotesummary_content() {

  $coursequote = $_SESSION['castleschool_coursequote'];
  $accommodationtotal = $_SESSION['accommodationtotal'];
  $airporttransferquote = $_SESSION['airporttransferquote'];
  $quotetotal = $coursequote + $accommodationtotal + $airporttransferquote;
  $courses = castleschool_get_courses();
  $durationindays = ($_SESSION['castleschool_weeks'] * 7) - 3;

  $markup = '<h4>Quote summary</h4>';
  $markup .= '<h6>' . $courses[$_SESSION['castleschool_course']] . '<br/>';
  $markup .= date('M j, Y', $_SESSION['castleschool_day']) . ' - ';
  $markup .= date('M j, Y', strtotime("+{$durationindays} day", $_SESSION['castleschool_day'])) . '<br/>';
  $markup .= $_SESSION['castleschool_hoursperweek'] . t(' hours per week') . '</h6>';

  // Prices
  $markup .= '<div class="castleschool-quote-summary-price">';
  $markup .= '<div class="castleschool-quote-summary-price-item">';
  $markup .= '<h6>' . t('Course') . '</h6>';
  $markup .= '</div>';
  $markup .= '<div class="castleschool-quote-summary-price-ammount">';
  $markup .= '<h6>£' . $coursequote . '</h6>';
  $markup .= '</div>';
  $markup .= '</div>';

  $markup .= '<div class="castleschool-quote-summary-price">';
  $markup .= '<div class="castleschool-quote-summary-price-item">';
  $markup .= '<h6>' . t('Accommodation') . '</h6>';
  $markup .= '</div>';
  $markup .= '<div class="castleschool-quote-summary-price-ammount">';
  $markup .= '<h6>£' . $accommodationtotal . '</h6>';
  $markup .= '</div>';
  $markup .= '</div>';

  $markup .= '<div class="castleschool-quote-summary-price">';
  $markup .= '<div class="castleschool-quote-summary-price-item">';
  $markup .= '<h6>' . t('Optional Extras') . '</h6>';
  $markup .= '</div>';
  $markup .= '<div class="castleschool-quote-summary-price-ammount">';
  $markup .= '<h6>£' . $airporttransferquote . '</h6>';
  $markup .= '</div>';
  $markup .= '</div>';

  // Total Price
  $markup .= '<div class="castleschool-quote-summary-totalprice">';
  $markup .= '<div class="castleschool-quote-summary-totalprice-item">';
  $markup .= '<h5>' . t('Total Price') . '</h5>';
  $markup .= '</div>';
  $markup .= '<div class="castleschool-quote-summary-totalprice-ammount">';
  $markup .= '<h5>£' . $quotetotal . '</h5>';
  $markup .= '</div>';
  $markup .= '</div>';

  return $markup;
}

function castleschool_accommodation_selected($selection) {

  switch ($selection) {
    case 1:
      $accommodationfee = 145;
      break;
    case 2:
      $accommodationfee = 125;
      break;
    case 3:
      $accommodationfee = 125;
      break;
    case 4:
      $accommodationfee = 105;
      break;
  }

  $_SESSION['accommodationtotal'] = $_SESSION['accommodationduration'] * $accommodationfee;

  drupal_goto('airport-transfers');
}

function castleschool_get_quote($course, $hoursperweek, $weeks) {

  $markup  = '<span class="castle-quote-total">£' . castleschool_get_coursequote($course, $hoursperweek, $weeks) . '</span>';
  //$markup .= '<span class="castle-quote-fees"><em>inc. booking fees</em></span>';
  //$markup .= '<span class="castle-quote-accomm">+&nbsp;accommodation from <span data-bind="text: value">£600</span></span>';

  echo $markup;
}

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
