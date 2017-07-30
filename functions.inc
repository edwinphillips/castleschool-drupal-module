<?php

/**
 * Returns an associative array of the next 18 months as
 * timestamps and friendly name values.
 *
 * @return array
 */
function castleschool_quote_month_options() {

  $months = array();
  $currentmonth = (int)date('m');

  for ($x = $currentmonth; $x < $currentmonth + 18; $x++) {
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

  $markup = 'I want to study: ' . $_SESSION['castleschool_quote_iwanttostudy'] . '<br/>';
  $markup .= 'Starting: ' . date('l jS F Y', $_SESSION['castleschool_quote_day']) . '<br/>';
  $markup .= 'Duration: ' . $_SESSION['castleschool_quote_weeks'] . ' weeks<br/>';
  $markup .= 'Total: £' . $_SESSION['quotetotal'] . '<br/>';

  return $markup;
}