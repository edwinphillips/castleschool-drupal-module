<?php

/**
 * Returns an associative array of the next 18 months as
 * timestamps and friendly name values.
 *
 * @return array
 */
function castleschool_quote_month_options() {

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
function castleschool_quote_block_get_mondays($timestamp) {

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

  $durationindays = ($_SESSION['castleschool_quote_weeks'] * 7) - 3;

  $markup = '<h4>Quote summary</h4>';
  $markup .= '<h6>' . $_SESSION['castleschool_quote_iwanttostudy'] . '<br/>';
  $markup .= date('M j, Y', $_SESSION['castleschool_quote_day']) . ' - ';
  $markup .= date('M j, Y', strtotime("+{$durationindays} day", $_SESSION['castleschool_quote_day'])) . '</h6>';

  // Prices
  $markup .= '<div class="castleschool-quote-summary-price">';
  $markup .= '<div class="castleschool-quote-summary-price-item">';
  $markup .= '<h6>' . t('Course') . '</h6>';
  $markup .= '</div>';
  $markup .= '<div class="castleschool-quote-summary-price-ammount">';
  $markup .= '<h6>£' . $_SESSION['quotetotal'] . '</h6>';
  $markup .= '</div>';
  $markup .= '</div>';

  $markup .= '<div class="castleschool-quote-summary-price">';
  $markup .= '<div class="castleschool-quote-summary-price-item">';
  $markup .= '<h6>' . t('Accommodation') . '</h6>';
  $markup .= '</div>';
  $markup .= '<div class="castleschool-quote-summary-price-ammount">';
  $markup .= '<h6>£0</h6>';
  $markup .= '</div>';
  $markup .= '</div>';

  $markup .= '<div class="castleschool-quote-summary-price">';
  $markup .= '<div class="castleschool-quote-summary-price-item">';
  $markup .= '<h6>' . t('Optional Extras') . '</h6>';
  $markup .= '</div>';
  $markup .= '<div class="castleschool-quote-summary-price-ammount">';
  $markup .= '<h6>£0</h6>';
  $markup .= '</div>';
  $markup .= '</div>';

  // Total Price
  $markup .= '<div class="castleschool-quote-summary-totalprice">';
  $markup .= '<div class="castleschool-quote-summary-totalprice-item">';
  $markup .= '<h5>' . t('Total Price') . '</h5>';
  $markup .= '</div>';
  $markup .= '<div class="castleschool-quote-summary-totalprice-ammount">';
  $markup .= '<h5>£' . $_SESSION['quotetotal'] . '</h5>';
  $markup .= '</div>';
  $markup .= '</div>';

  return $markup;
}

function castleschool_accommodation_selected($selection) {

  // Todo: Save session data.

  drupal_goto('airport-transfers');
}
