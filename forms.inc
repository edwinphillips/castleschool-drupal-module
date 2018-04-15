<?php

/**
 * Teaser quote form
 *
 * @param type $form
 * @param type $form_state
 * @param array $weeks
 * @return array
 */
function castleschool_teaser_form($form, &$form_state, $weeks) {

  $courseselected = isset($form_state['values']['course']) ? $form_state['values']['course'] : 1;
  $weeksselected = isset($form_state['values']['weeks']) ? $form_state['values']['weeks'] : 4;

  $form['course'] = array(
    '#type' => 'select',
    '#title' => t('I want to study'),
    '#options' => castleschool_get_course_names(),
    '#default_value' => $courseselected,
    '#ajax' => array(
      'callback' => 'castleschool_hoursperweek_callback',
      'wrapper' => 'castleschool_hoursperweek_wrapper',
    ),
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $form['hoursperweek'] = array(
    '#type' => 'select',
    '#title' => '&nbsp;',
    '#prefix' => '<div id="castleschool_hoursperweek_wrapper">',
    '#suffix' => '</div>',
    '#options' => castleschool_get_hoursperweek($courseselected, $weeksselected),
    '#default_value' => castleschool_get_hoursperweek($courseselected, $weeksselected)[0],
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $months = castleschool_get_months();
  $selected = isset($form_state['values']['month']) ? $form_state['values']['month'] : key($months);

  $form['month'] = array(
    '#type' => 'select',
    '#title' => t('From'),
    '#options' => $months,
    '#default_value' => $selected,
    '#ajax' => array(
      'callback' => 'castleschool_day_callback',
      'wrapper' => 'castleschool_day_wrapper',
    ),
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $form['day'] = array(
    '#type' => 'select',
    '#title' => t('&nbsp;'),
    '#prefix' => '<div id="castleschool_day_wrapper">',
    '#suffix' => '</div>',
    '#options' => castleschool_get_mondays_in_month($selected),
    '#default_value' => isset($form_state['values']['day']) ? $form_state['values']['day'] : '',
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $form['weeks'] = array(
    '#type' => 'select',
    '#title' => t('For'),
    '#default_value' => isset($form->weeks) ? $form->weeks : 4,
    '#options' => $weeks,
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $quotemarkup = '<div class="castle-quote-wrapper">';
  $quotemarkup .= '<span class="castle-quote-total">£<span id="teaser-quote-value"></span></span>';
  $quotemarkup .= '<span class="castle-quote-fees"><em>inc. registration fee</em></span>';
  $quotemarkup .= '<span class="castle-quote-accomm">+&nbsp;accommodation from £<span id="teaser-accommodation-value"></span></span>';
  $quotemarkup .= '</div>';

  $form['quote'] = array(
    '#markup' => $quotemarkup,
  );

  $form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Continue'),
    '#attributes' => array(
      'data-toggle' => 'tooltip',
      'data-placement' => 'bottom',
      'title' => t('Continue for additional options and booking.'),
    ),
  );

  return $form;
}

/**
 * Teaser for submit
 *
 * @param type $form
 * @param array $form_state
 */
function castleschool_teaser_form_submit($form, &$form_state) {

  unset($_SESSION['accommodationid']);
  unset($_SESSION['accommodationstartdate']);
  unset($_SESSION['accommodationtotal']);
  unset($_SESSION['accommodationduration']);
  unset($_SESSION['accommodationtotal']);
  unset($_SESSION['airporttransferquote']);
  unset($_SESSION['whichairport']);
  unset($_SESSION['arrivaldeparture']);
  unset($_SESSION['age']);

  extract($form_state['values']);

  $_SESSION['castleschool_course'] = $course;
  $_SESSION['castleschool_hoursperweek'] = $hoursperweek;
  $_SESSION['castleschool_month'] = $month;
  $_SESSION['castleschool_day'] = $day;
  $_SESSION['castleschool_weeks'] = $weeks;
  $_SESSION['castleschool_coursequote'] = castleschool_get_coursequote($course, $hoursperweek, $weeks);

  $form_state['redirect'] = 'search-for-accommodation';
}

/**
 * Hours per week callback
 *
 * @param array $form
 * @param array $form_state
 * @return array
 */
function castleschool_hoursperweek_callback($form, $form_state) {

  $hoursperweek = castleschool_get_hoursperweek($form['course']['#default_value'], $form_state['values']['weeks']);
  $form['hoursperweek']['#options'] = $hoursperweek;

  return $form['hoursperweek'];
}

/**
 * Day callback
 *
 * @param array $form
 * @param array $form_state
 * @return array
 */
function castleschool_day_callback($form, $form_state) {

  $form['day']['#options'] = castleschool_get_mondays_in_month($form['month']['#default_value']);

  return $form['day'];
}

/**
 * Choose your course form
 *
 * @param array $form
 * @param array $form_state
 * @param array $weeks
 * @return string
 */
function castleschool_choose_course_form($form, &$form_state, $weeks) {

  $courseoptions = castleschool_get_course_names();

  $defaultcourse = isset($_SESSION['castleschool_course']) ? $_SESSION['castleschool_course'] : 1;
  $courseselected = isset($form_state['values']['course']) ? $form_state['values']['course'] : $defaultcourse;

  $defaultstartdate = isset($_SESSION['castleschool_day']) ? $_SESSION['castleschool_day'] : castleschool_get_startdate()[0];
  $startdateselected = isset($form_state['values']['startdate']) ? $form_state['values']['startdate'] : $defaultstartdate;

  $defaultweeks = isset($_SESSION['castleschool_weeks']) ? $_SESSION['castleschool_weeks'] : 4;
  $weeksselected = isset($form_state['values']['weeks']) ? $form_state['values']['weeks'] : $defaultweeks;

  $defaulthoursperweek = isset($_SESSION['castleschool_hoursperweek']) ? $_SESSION['castleschool_hoursperweek'] : castleschool_get_hoursperweek($courseselected, $weeksselected)[0];
  $hoursperweekselected = isset($form_state['values']['hoursperweek']) ? $form_state['values']['hoursperweek'] : $defaulthoursperweek;

  $form['course'] = array(
    '#type' => 'select',
    '#title' => t('What do you want to study?'),
    '#options' => $courseoptions,
    '#default_value' => $courseselected,
    '#ajax' => array(
      'callback' => 'castleschool_hoursperweek_callback',
      'wrapper' => 'castleschool_hoursperweek_wrapper',
    ),
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $form['startdate'] = array(
    '#type' => 'select',
    '#title' => t('When do you want to start?'),
    '#description' => t('Classes begin on a Monday.'),
    '#options' => castleschool_get_startdate(),
    '#default_value' => $startdateselected,
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $form['hoursperweek'] = array(
    '#type' => 'select',
    '#title' => t('How many hours per week will you study for?'),
    '#prefix' => '<div id="castleschool_hoursperweek_wrapper">',
    '#suffix' => '</div>',
    '#options' => castleschool_get_hoursperweek($courseselected, $weeksselected),
    '#default_value' => $hoursperweekselected,
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $form['weeks'] = array(
    '#type' => 'select',
    '#title' => t('How long will you study for?'),
    '#options' => $weeks,
    '#default_value' => $weeksselected,
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Next'),
  );

  return $form;
}

/**
 * Choose your course form submit
 *
 * @param array $form
 * @param array $form_state
 */
function castleschool_choose_course_form_submit($form, &$form_state) {

  unset($_SESSION['accommodationid']);
  unset($_SESSION['accommodationstartdate']);
  unset($_SESSION['accommodationtotal']);
  unset($_SESSION['accommodationduration']);
  unset($_SESSION['accommodationtotal']);
  unset($_SESSION['airporttransferquote']);
  unset($_SESSION['whichairport']);
  unset($_SESSION['arrivaldeparture']);
  unset($_SESSION['age']);

  extract($form_state['values']);

  $_SESSION['castleschool_course'] = $course;
  $_SESSION['castleschool_hoursperweek'] = $hoursperweek;
  $_SESSION['castleschool_month'] = $startdate;
  $_SESSION['castleschool_day'] = $startdate;
  $_SESSION['castleschool_weeks'] = $weeks;
  $_SESSION['castleschool_coursequote'] = castleschool_get_coursequote($course, $hoursperweek, $weeks);

  $form_state['redirect'] = 'search-for-accommodation';
}

/**
 * Search for Accommodation form
 * @param array $form
 * @param array $form_state
 * @param array $weeks
 * @return array
 */
function castleschool_search_for_accommodation_form($form, &$form_state, $weeks) {

  $form['intro'] = array(
    '#markup' => '<p>' . t('We need to know a little bit about you before we can find suitable accommodation.') . '</p>',
  );

  $accommodationdurationdefault = (isset($_SESSION['accommodationduration']) && $_SESSION['accommodationduration'])
      ? $_SESSION['accommodationduration'] : array_keys($weeks)[0];

  $form['accommodationduration'] = array(
    '#type' => 'select',
    '#title' => t('How long do you want to stay?'),
    '#options' => $weeks,
    '#default_value' => $accommodationdurationdefault,
    '#required' => FALSE,
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $agedefault = (isset($_SESSION['age']) && $_SESSION['age']) ? $_SESSION['age'] : '';

  $form['age'] = array(
    '#type' => 'textfield',
    '#title' => t('Age when you start your course'),
    '#size' => 3,
    '#maxlength' => 3,
    '#default_value' => $agedefault,
    '#required' => TRUE,
    '#element_validate' => array('element_validate_number'),
  );

  $form['back_button'] = array(
    '#markup' => '<a id="back_button" class="btn btn-warning" href="/choose-your-course">Back</a>'
  );

  $form['no_accommodation_button'] = array(
    '#markup' => '<a class="btn btn-warning" href="/choose-your-accommodation/0">I do not require accommodation</a>',
  );

  $form['search_button'] = array(
    '#type' => 'submit',
    '#name' => 'search_button',
    '#value' => t('Search'),
    '#submit' => array('castleschool_search_for_accommodation_form_submit'),
  );

  return $form;
}

/**
 * Search for accommodation form validation
 *
 * @param array $form
 * @param array $form_state
 */
function castleschool_search_for_accommodation_form_validate($form, &$form_state) {

  if (!empty($form_state['values']['age']) && $form_state['values']['age'] > 150) {
    form_set_error('title', 'Seriously?');
  }

  if (!empty($form_state['values']['age']) && $form_state['values']['age'] < 16) {
    form_set_error('title', 'You must be at least 16 years old when you start your course');
  }
}

/**
 * Search for accommodation form submit
 *
 * @param array $form
 * @param array $form_state
 */
function castleschool_search_for_accommodation_form_submit($form, &$form_state) {

  $_SESSION['accommodationduration'] = $form_state['values']['accommodationduration'];
  $_SESSION['age'] = $form_state['values']['age'];

  $form_state['redirect'] = 'choose-your-accommodation';
}

/**
 * Choose Accommodation form
 *
 * @param array $form
 * @param array $form_state
 * @return array
 */
function castleschool_choose_accommodation_form($form, &$form_state) {

  $form['table'] = array(
    '#markup' => castleschool_accommodation_selection_table(),
  );

  $form['back_button'] = array(
    '#markup' => '<a class="btn btn-warning" href="/search-for-accommodation">' .t('Back') .'</a>',
  );

  $form['no_accommodation_button'] = array(
    '#markup' => '<a id="no_accommodation_button" class="btn btn-warning" href="/choose-your-accommodation/0">'
      . t('I don\'t require accommodation') . '</a>',
  );

  return $form;
}

/**
 * Accommodation selection table
 *
 * @return type
 */
function castleschool_accommodation_selection_table() {

  $accommodationfindingfee = castleschool_get_accommodation_finding_fee();

  $header = array();
  $rows = array();
  $accommodationdetails = castleschool_accommodation_details();

  foreach ($accommodationdetails as $accommodationid => $accommodationoption) {
    $rows[$accommodationid] = array('<p>' . $accommodationoption['label']
        . ' - <strong>£' . castleschool_calculate_accommodation_quote($accommodationid) . '</strong></p>',
        '<a class="btn btn-submit" href="/choose-your-accommodation/'
        . $accommodationid . '">' .t('Select') .'</a>'
    );
  }

  foreach ($rows as $key => $row) {
    if (isset($_SESSION['accommodationid']) && $_SESSION['accommodationid'] == $key) {
      $rows[$key] = array(
        'data' => $row,
        'class' => array(
          'info'
        )
      );
    }
  }

  $tablehtml = theme(
    'table',
    array(
      'header' => $header,
      'rows' => $rows
    )
  );

  $feehtml = '<p class="accommodation-finding-fee">' .
      t('Prices include a £@fee accommodation finding fee.', array('@fee' => $accommodationfindingfee))
      . '</p>';

  return $tablehtml . $feehtml;
}

/**
 * Airport Transfers Form
 *
 * @param array $form
 * @param array $form_state
 * @return array
 */
function castleschool_airport_transfers_form($form, &$form_state) {

  $form['intro'] = array(
    '#markup' => '<p>' . t('Would you like taxi transport from the airport to your accommodation?') . '</p>',
  );

  $whichairportdefault = (isset($_SESSION['whichairport']) && $_SESSION['whichairport']) ? $_SESSION['whichairport'] : 0;

  $form['whichairport'] = array(
    '#type' => 'select',
    '#title' => t('Which airport will you arrive at?'),
    '#options' => castleschool_get_airport_transfer_options(),
    '#default_value' => $whichairportdefault,
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $arrivaldeparturedefault = (isset($_SESSION['arrivaldeparture']) && $_SESSION['arrivaldeparture'])
      ? $_SESSION['arrivaldeparture'] : 0;

  $form['arrivaldeparture'] = array(
    '#type' => 'select',
    '#title' => t('Would you like just an Arrival transfer or Arrival and Departure?'),
    '#options' => castleschool_get_airport_transfer_type_details(),
    '#default_value' => $arrivaldeparturedefault,
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
    '#states' => array(
      'disabled' => array(
        ':input[name="whichairport"]' => array('value' => '0'),
      ),
      'required' => array(
        ':input[name="whichairport"]' => array('!value' => '0'),
      ),
    ),
  );

  $backurl = (isset($_SESSION['accommodationid']) && $_SESSION['accommodationid']) ?
      '/choose-your-accommodation' : '/search-for-accommodation';

  $form['back_button'] = array(
    '#markup' => '<a class="btn btn-warning" href="' . $backurl . '">Back</a>'
  );

  $form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Next'),
  );

  return $form;
}

/**
 * Airport Transfers Form validation
 *
 * @param array $form
 * @param array $form_state
 */
function castleschool_airport_transfers_form_validate($form, &$form_state) {

  if ($form_state['values']['whichairport'] != 0 &&
      $form_state['values']['arrivaldeparture'] == 0 &&
      $form_state['complete form']['arrivaldeparture']['#states']['required'][':input[name="whichairport"]']['!value'] == 0) {
    form_set_error('title', t('Would you like just an Arrival transfer or Arrival and Departure field is required.'));
  }
}

/**
 * Airport Transfers Form Submit
 *
 * @param array $form
 * @param array $form_state
 */
function castleschool_airport_transfers_form_submit($form, &$form_state) {

  $airporttransferdetails = castleschool_get_airport_transfer_details();
  if ($form_state['values']['whichairport']) {
    $airporttransferquote = $airporttransferdetails[$form_state['values']['whichairport']]['price'];
  }

  if ($form_state['values']['arrivaldeparture'] == 3) {
    $airporttransferquote *= 2;
  }

  $_SESSION['whichairport'] = $form_state['values']['whichairport'];
  $_SESSION['arrivaldeparture'] = ($form_state['values']['whichairport'] == 0)
      ? 0 : $form_state['values']['arrivaldeparture'];
  $_SESSION['airporttransferquote'] = $airporttransferquote;

  $form_state['redirect'] = 'your-quote';
}

/**
 * Final Quote Form
 *
 * @param array $form
 * @param array $form_state
 * @return array
 */
function castleschool_finalquote_form($form, &$form_state) {

  $registrationfee = castleschool_get_registration_fee();
  $coursequote = (isset($_SESSION['castleschool_coursequote']) && $_SESSION['castleschool_coursequote'])
      ? $_SESSION['castleschool_coursequote'] : 0;
  $accommodationquote = (isset($_SESSION['accommodationtotal']) && $_SESSION['accommodationtotal'])
      ? $_SESSION['accommodationtotal'] : 0;
  $accommodationfindingfee = ($accommodationquote) ? castleschool_get_accommodation_finding_fee() : 0;
  $extrasquote = (isset($_SESSION['airporttransferquote']) && $_SESSION['airporttransferquote'])
      ? $_SESSION['airporttransferquote'] : 0;
  $quotetotal = $registrationfee + $coursequote + $accommodationquote + $extrasquote;

  $markup = '<div class="table-responsive">';
  $markup .= '<table class="table table-bordered table-striped">';
  $markup .= '<thead>';
  $markup .= '<tr class="info">';
  $markup .= '<th><p class="text-left"><strong>' . t('Course') . '</strong></p></th>';
  $markup .= '<th class="price"><p><strong>' . t('Price') . '</strong></p></th>';
  $markup .= '</tr>';
  $markup .= '</thead>';
  $markup .= '<tbody>';
  $markup .= '<tr>';
  $markup .= '<td><p class="text-left">' . castleschool_get_course_name($_SESSION['castleschool_course'])
      . ' - ' . $_SESSION['castleschool_hoursperweek'] . t(' hours per week') . '<br/>'
      . castleschool_get_course_dates($_SESSION['castleschool_day'], $_SESSION['castleschool_weeks']) . '<br/>' 
      . t('Length') . ': ' . $_SESSION['castleschool_weeks'] . ' ' . t('weeks') . '</p></td>';
  $markup .= '<td class="price"><p>£' . $_SESSION['castleschool_coursequote'] . '</p></td>';
  $markup .= '</tr>';
  $markup .= '<tr>';
  $markup .= '<td><p class="text-left">' . t('Registration Fee') . '</p></td>';
  $markup .= '<td class="price"><p>£' . castleschool_get_registration_fee() . '</p></td>';
  $markup .= '</tr>';
  $markup .= '</tbody>';
  $markup .= '</table>';
  $markup .= '</div>';

  if ((isset($_SESSION['accommodationchoice']) && $_SESSION['accommodationchoice'])
      && ((isset($_SESSION['accommodationstartdate']) && $_SESSION['accommodationstartdate']))
      && ((isset($_SESSION['accommodationduration']) && $_SESSION['accommodationduration']))
      && ((isset($_SESSION['accommodationtotal']) && $_SESSION['accommodationtotal']))
      ) {
    $markup .= '<div class="table-responsive">';
    $markup .= '<table class="table table-bordered table-striped">';
    $markup .= '<thead>';
    $markup .= '<tr class="info">';
    $markup .= '<th><p class="text-left"><strong>' . t('Accommodation') . '</strong></p></th>';
    $markup .= '<th class="price"><p><strong>' . t('Price') . '</strong></p></th>';
    $markup .= '</tr>';
    $markup .= '</thead>';
    $markup .= '<tbody>';
    $markup .= '<tr>';
    $markup .= '<td><p class="text-left">' . $_SESSION['accommodationchoice']
        . '<br/>' . castleschool_get_accommodation_dates($_SESSION['accommodationstartdate'], $_SESSION['accommodationduration'])
        . '<br/>' . t('Duration') . ': ' . $_SESSION['accommodationduration'] . ' ' . t('weeks')
        . '<br/>' . t('Your accommodation starts on the date shown above. Please let us know if you plan to arrive on a different day.') . '</p></td>';
    $markup .= '<td class="price"><p>£' . ($accommodationquote - $accommodationfindingfee) . '</p></td>';
    $markup .= '</tr>';
    $markup .= '<tr>';
    $markup .= '<td>';
    $markup .= '<p class="text-left">' . t('Accommodation finding fee') . '</p>';
    $markup .= '</td>';
    $markup .= '<td class="price">';
    $markup .= '<p>£' . $accommodationfindingfee . '</p>';
    $markup .= '</td>';
    $markup .= '</tr>';
    $markup .= '</tbody>';
    $markup .= '</table>';
    $markup .= '</div>';
  }

  if ((isset($_SESSION['whichairport']) && $_SESSION['whichairport'])
      && ((isset($_SESSION['airporttransferquote']) && $_SESSION['airporttransferquote']))
      ) {
    $markup .= '<div class="table-responsive">';
    $markup .= '<table class="table table-bordered table-striped">';
    $markup .= '<thead>';
    $markup .= '<tr class="info">';
    $markup .= '<th><p class="text-left"><strong>' . t('Optional Extras') . '</strong></p></th>';
    $markup .= '<th class="price"><p><strong>' . t('Price') . '</strong></p></th>';
    $markup .= '</tr>';
    $markup .= '</thead>';
    $markup .= '<tbody>';
    $markup .= '<tr>';
    $markup .= '<td><p class="text-left">' . castleschool_get_airport_transfer_location($_SESSION['whichairport'])
        . ' - ' . castleschool_get_airport_transfer_type($_SESSION['arrivaldeparture']) . '</p></td>';
    $markup .= '<td class="price"><p>£' . $_SESSION['airporttransferquote'] . '</p></td>';
    $markup .= '</tr>';
    $markup .= '</tbody>';
    $markup .= '</table>';
    $markup .= '</div>';
  }

  $markup .= '<div class="table-responsive">';
  $markup .= '<table class="table table-bordered table-striped">';
  $markup .= '<thead>';
  $markup .= '<tr class="info">';
  $markup .= '<th><p class="text-left"><strong>' . t('Total Price') . '</strong></p></th>';
  $markup .= '<th class="price"><p><strong>£' . $quotetotal . '</strong></p></th>';
  $markup .= '</tr>';
  $markup .= '</thead>';
  $markup .= '</table>';
  $markup .= '</div>';

  $form['quotetable'] = array(
    '#markup' => $markup,
  );

  $form['back_button'] = array(
    '#markup' => '<a class="btn btn-warning" href="/airport-transfers">' . t('Back') . '</a>',
  );

  $form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Book now'),
    '#prefix' => '<div id="castleschool_button_wrapper">',
    '#suffix' => '</div>',
  );

  return $form;
}

/**
 * Final Quote Form submit
 *
 * @param array $form
 * @param array $form_state
 */
function castleschool_finalquote_form_submit($form, &$form_state) {

  $form_state['redirect'] = 'booking-form';
}

/**
 * Booking form
 *
 * @param array $form
 * @param array $form_state
 * @return array
 */
function castleschool_bookingform_form($form, &$form_state) {

  $markup = '<p>';
  $markup .= t('If you want to secure a place on this course press "BOOK NOW" at the bottom of the form. After you send us the enrolment form we will email you to confirm your place.');
  $markup .= '</p>';

  $form['intro'] = array(
    '#markup' => $markup,
  );

  $form['firstname'] = array(
    '#type' => 'textfield',
    '#title' => t('First name'),
    '#size' => 40,
    '#maxlength' => 40,
    '#required' => TRUE,
  );

  $form['lastname'] = array(
    '#type' => 'textfield',
    '#title' => t('Last name'),
    '#size' => 40,
    '#maxlength' => 40,
    '#required' => TRUE,
  );

  $form['dob'] = array(
    '#type' => 'textfield',
    '#title' => t('Date of birth'),
    '#size' => 10,
    '#maxlength' => 10,
    '#required' => TRUE,
    '#attributes' => array(
      'placeholder' => t('dd/mm/yyyy'),
    ),
  );

  $form['gender'] = array(
    '#type' => 'select',
    '#title' => t('Gender'),
    '#options' => array(
      '' => t('- Select -'),
      t('Male') => t('Male'),
      t('Female') => t('Female'),
    ),
    '#required' => TRUE,
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $form['nationality'] = array(
    '#type' => 'textfield',
    '#title' => t('Nationality'),
    '#size' => 20,
    '#maxlength' => 20,
    '#required' => TRUE,
  );

  $form['passport'] = array(
    '#type' => 'textfield',
    '#title' => t('Passport number/EU Citizen ID number'),
    '#size' => 30,
    '#maxlength' => 30,
    '#required' => TRUE,
  );

  $form['telephone'] = array(
    '#type' => 'textfield',
    '#title' => t('Telephone'),
    '#size' => 30,
    '#maxlength' => 30,
    '#required' => TRUE,
  );

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#size' => 40,
    '#maxlength' => 40,
    '#required' => TRUE,
  );

  $form['address'] = array(
    '#type' => 'textarea',
    '#title' => t('Address'),
    '#size' => 500,
    '#maxlength' => 500,
    '#required' => TRUE,
  );

  $form['nextofkin'] = array(
    '#type' => 'textfield',
    '#title' => t('Next of kin  (The name of the person we should contact in an emergency)'),
    '#size' => 40,
    '#maxlength' => 40,
    '#required' => TRUE,
  );

  $form['nextofkintelephone'] = array(
    '#type' => 'textfield',
    '#title' => t('Next of kin telephone'),
    '#size' => 40,
    '#maxlength' => 40,
    '#required' => TRUE,
  );

  $form['nextofkinaddress'] = array(
    '#type' => 'textarea',
    '#title' => t('Next of kin address'),
    '#size' => 500,
    '#maxlength' => 500,
    '#required' => TRUE,
  );

  $form['smoke'] = array(
    '#type' => 'select',
    '#title' => t('Do you smoke?'),
    '#required' => TRUE,
    '#options' => array(
      '' => t('- Select -'),
      t('Yes') => t('Yes'),
      t('No') => t('No'),
    ),
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $form['medicalconditions'] = array(
    '#type' => 'select',
    '#title' => t('Do you have any medical conditions?'),
    '#required' => TRUE,
    '#options' => array(
      '' => t('- Select -'),
      t('Yes') => t('Yes'),
      t('No') => t('No'),
    ),
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $form['petallergies'] = array(
    '#type' => 'select',
    '#title' => t('Are you allergic to any animals?'),
    '#required' => TRUE,
    '#options' => array(
      '' => t('- Select -'),
      t('Yes') => t('Yes'),
      t('No') => t('No'),
    ),
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $form['back_button'] = array(
    '#markup' => '<a class="btn btn-warning" href="/your-quote">' . t('Back') . '</a>',
  );

  $form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Book Now'),
  );

  return $form;
}

/**
 * Booking form validation
 *
 * @param array $form
 * @param array $form_state
 */
function castleschool_bookingform_form_validate($form, &$form_state) {

}

/**
 * Booking form submit
 *
 * @param array $form
 * @param array $form_state
 */
function castleschool_bookingform_form_submit($form, &$form_state) {

  $formvals = $form_state['values'];
  unset($formvals['submit_button']);
  unset($formvals['form_build_id']);
  unset($formvals['form_id']);
  unset($formvals['op']);
  extract($formvals);

  $from = 'no-reply@castle-school.co.uk';
  $to = variable_get('booking_notifications', 'info@castle-school.co.uk');
  $subject = 'Castle School Course Booking';

  $body  = '<p>A course booking has been received from the Castle School website.</p>';
  $body .= '<p>The details submitted are as follows:</p>';

  $body .= '<ul>';
  foreach ($formvals as $key => $value) {
    $title = $form_state['complete form'][$key]['#title'];
    $body .= '<li>' . $title . ': ' . $value . '</li>';
  }
  $body .= '</ul>';

  $registrationfee = castleschool_get_registration_fee();
  $coursequote = (isset($_SESSION['castleschool_coursequote']) && $_SESSION['castleschool_coursequote'])
      ? $_SESSION['castleschool_coursequote'] : 0;
  $accommodationquote = (isset($_SESSION['accommodationtotal']) && $_SESSION['accommodationtotal'])
      ? $_SESSION['accommodationtotal'] : 0;
  $accommodationfindingfee = ($accommodationquote) ? castleschool_get_accommodation_finding_fee() : 0;
  $accommodationfee = $accommodationquote - $accommodationfindingfee;
  $extrasquote = (isset($_SESSION['airporttransferquote']) && $_SESSION['airporttransferquote'])
      ? $_SESSION['airporttransferquote'] : 0;
  $quotetotal = $registrationfee + $coursequote + $accommodationquote + $extrasquote;

  $markup = '<div class="table-responsive">';
  $markup .= '<table class="table table-bordered table-striped">';
  $markup .= '<thead>';
  $markup .= '<tr class="info">';
  $markup .= '<th><p class="text-left"><strong>' . t('Course') . '</strong></p></th>';
  $markup .= '<th class="price"><p><strong>' . t('Price') . '</strong></p></th>';
  $markup .= '</tr>';
  $markup .= '</thead>';
  $markup .= '<tbody>';
  $markup .= '<tr>';
  $markup .= '<td><p class="text-left">' . castleschool_get_course_name($_SESSION['castleschool_course'])
      . ' - ' . $_SESSION['castleschool_hoursperweek'] . t(' hours per week') . '<br/>'
      . castleschool_get_course_dates($_SESSION['castleschool_day'], $_SESSION['castleschool_weeks']) . '<br/>'
      . t('Length') . ': ' . $_SESSION['castleschool_weeks'] . ' ' . t('weeks') . '</p></td>';
  $markup .= '<td class="price"><p>£' . $_SESSION['castleschool_coursequote'] . '</p></td>';
  $markup .= '</tr>';
  $markup .= '<tr>';
  $markup .= '<td><p class="text-left">' . t('Registration Fee') . '</p></td>';
  $markup .= '<td class="price"><p>£' . castleschool_get_registration_fee() . '</p></td>';
  $markup .= '</tr>';
  $markup .= '</tbody>';
  $markup .= '</table>';
  $markup .= '</div>';

  if ((isset($_SESSION['accommodationchoice']) && $_SESSION['accommodationchoice'])
      && ((isset($_SESSION['accommodationstartdate']) && $_SESSION['accommodationstartdate']))
      && ((isset($_SESSION['accommodationduration']) && $_SESSION['accommodationduration']))
      && ((isset($_SESSION['accommodationtotal']) && $_SESSION['accommodationtotal']))
      ) {
    $markup .= '<div class="table-responsive">';
    $markup .= '<table class="table table-bordered table-striped">';
    $markup .= '<thead>';
    $markup .= '<tr class="info">';
    $markup .= '<th><p class="text-left"><strong>' . t('Accommodation') . '</strong></p></th>';
    $markup .= '<th class="price"><p><strong>' . t('Price') . '</strong></p></th>';
    $markup .= '</tr>';
    $markup .= '</thead>';
    $markup .= '<tbody>';
    $markup .= '<tr>';
    $markup .= '<td><p class="text-left">' . $_SESSION['accommodationchoice']
        . '<br/>' . castleschool_get_accommodation_dates($_SESSION['accommodationstartdate'], $_SESSION['accommodationduration'])
        . '<br/>' . t('Duration') . ': ' . $_SESSION['accommodationduration'] . ' ' . t('weeks')
        . '<br/>' . t('Your accommodation starts on the date shown above. Please let us know if you plan to arrive on a different day.') . '</p></td>';
    $markup .= '<td class="price"><p>£' . ($accommodationquote - $accommodationfindingfee) . '</p></td>';
    $markup .= '</tr>';
    $markup .= '<tr>';
    $markup .= '<td>';
    $markup .= '<p class="text-left">' . t('Accommodation finding fee') . '</p>';
    $markup .= '</td>';
    $markup .= '<td class="price">';
    $markup .= '<p>£' . $accommodationfindingfee . '</p>';
    $markup .= '</td>';
    $markup .= '</tr>';
    $markup .= '</tbody>';
    $markup .= '</table>';
    $markup .= '</div>';
  }

  if ((isset($_SESSION['whichairport']) && $_SESSION['whichairport'])
      && ((isset($_SESSION['airporttransferquote']) && $_SESSION['airporttransferquote']))
      ) {
    $markup .= '<div class="table-responsive">';
    $markup .= '<table class="table table-bordered table-striped">';
    $markup .= '<thead>';
    $markup .= '<tr class="info">';
    $markup .= '<th><p class="text-left"><strong>' . t('Optional Extras') . '</strong></p></th>';
    $markup .= '<th class="price"><p><strong>' . t('Price') . '</strong></p></th>';
    $markup .= '</tr>';
    $markup .= '</thead>';
    $markup .= '<tbody>';
    $markup .= '<tr>';
    $markup .= '<td><p class="text-left">' . castleschool_get_airport_transfer_location($_SESSION['whichairport'])
        . ' - ' . castleschool_get_airport_transfer_type($_SESSION['arrivaldeparture']) . '</p></td>';
    $markup .= '<td class="price"><p>£' . $_SESSION['airporttransferquote'] . '</p></td>';
    $markup .= '</tr>';
    $markup .= '</tbody>';
    $markup .= '</table>';
    $markup .= '</div>';
  }

  $markup .= '<div class="table-responsive">';
  $markup .= '<table class="table table-bordered table-striped">';
  $markup .= '<thead>';
  $markup .= '<tr class="info">';
  $markup .= '<th><p class="text-left"><strong>' . t('Total Price') . '</strong></p></th>';
  $markup .= '<th class="price"><p><strong>£' . $quotetotal . '</strong></p></th>';
  $markup .= '</tr>';
  $markup .= '</thead>';
  $markup .= '</table>';
  $markup .= '</div>';

  $body .= $markup;

  simple_mail_send($from, $to, $subject, $body);

  $bookingid = db_insert('castleschool_bookings')->fields(array(
    'course_id' => $_SESSION['castleschool_course'],
    'hours_per_week' => $_SESSION['castleschool_hoursperweek'],
    'course_startdate' => $_SESSION['castleschool_day'],
    'course_enddate' => $_SESSION['castleschool_day'] + (60 * 60 * 24 * 7 * $_SESSION['castleschool_weeks']),
    'course_length_weeks' => $_SESSION['castleschool_weeks'],
    'course_fee' => $coursequote,
    'registration_fee' => $registrationfee,
    'accommodation_type_id' => $_SESSION['accommodationid'],
    'accommodation_start_date' => $_SESSION['accommodationstartdate'],
    'accommodation_end_date' => $_SESSION['accommodationstartdate'] + (60 * 60 * 24 * 7 * $_SESSION['accommodationduration']),
    'accommodation_duration_weeks' => $_SESSION['accommodationduration'],
    'accommodation_fee' => $accommodationfee,
    'accommodation_finding_fee' => $accommodationfindingfee,
    'airport_transfer_type_id' => $_SESSION['whichairport'],
    'airport_transfer_singleorreturn' => $_SESSION['arrivaldeparture'],
    'airport_transfer_fee' => $_SESSION['airporttransferquote'],
    'total_booking_fee' => $quotetotal,
    'firstname' => $formvals['firstname'],
    'lastname' => $formvals['lastname'],
    'date_of_birth' => $formvals['dob'],
    'gender' => $formvals['gender'],
    'nationality' => $formvals['nationality'],
    'passport_or_idnumber' => $formvals['passport'],
    'telephone' => $formvals['telephone'],
    'email' => $formvals['email'],
    'address' => $formvals['address'],
    'nextofkin_name' => $formvals['nextofkin'],
    'nextofkin_telephone' => $formvals['nextofkintelephone'],
    'nextofkin_address' => $formvals['nextofkinaddress'],
    'smokes' => $formvals['smoke'],
    'medical_conditions' => $formvals['medicalconditions'],
    'animal_allergies' => $formvals['petallergies'],
    'created' => REQUEST_TIME,
  ))->execute();

  $_SESSION['booking_id'] = $bookingid;

  $form_state['redirect'] = 'proceed-to-worldpay';
}

/**
 * Proceed to Worldpay form
 *
 * @param array $form
 * @param array $form_state
 * @return array
 */
function castleschool_worldpay_form($form, &$form_state) {
  global $base_url;

  $booking = db_select('castleschool_bookings', 'b')
    ->fields('b')
    ->condition('booking_id', $_SESSION['booking_id'], '=')
    ->execute()
    ->fetchAssoc();

  if (variable_get('worldpay_mode') == 1) {
    $testmode = 0;
  } else {
    $testmode = 100;
  }

  $instid = castleschool_get_worldpay_instid();
  $description = 'English language course';

  $form['instId'] = array(
    '#value' => $instid,
    '#type' => 'hidden',
  );

  $form['testMode'] = array(
    '#value' => $testmode,
    '#type' => 'hidden',
  );
  $form['cartId'] = array(
    '#value' => $booking['booking_id'],
    '#type' => 'hidden',
  );

  $form['amount'] = array(
    '#value' => $booking['total_booking_fee'],
    '#type' => 'hidden'
  );

  $form['currency'] = array(
    '#value' => 'GBP',
    '#type' => 'hidden',
  );

  $form['name'] = array(
    '#value' => $booking['firstname'] . ' ' . $booking['lastname'],
    '#type' => 'hidden',
  );

  $form['desc'] = array(
    '#value' => $description,
    '#type' => 'hidden',
  );

  $form['confirm_url'] = array(
    '#value' => $base_url . '/booking-confirmation',
    '#type' => 'hidden',
  );

  $form['cancel_url'] = array(
    '#value' => $base_url . '/payment-cancelled',
    '#type' => 'hidden',
  );

  $form['status_url'] = array(
    '#value' => 'hello@edwinphillips.net', # <-- not sure
    '#type' => 'hidden',
  );

  $form['address1'] = array(
    '#value' => $booking['address'],
    '#type' => 'hidden',
  );

  $form['tel'] = array(
    '#value' => $booking['telephone'],
    '#type' => 'hidden',
  );

  $form['postcode'] = array(
    '#value' => '', # <--  Missing from booking form
    '#type' => 'hidden',
  );

  $form['town'] = array(
    '#value' => '', # <--  Missing from booking form
    '#type' => 'hidden',
  );

  $form['region'] = array(
    '#value' => '', # <--  Missing from booking form
    '#type' => 'hidden',
  );

  $form['country'] = array(
    '#value' => '', # <--  Missing from booking form
    '#type' => 'hidden',
  );

  $form['email'] = array(
    '#value' => $booking['email'],
    '#type' => 'hidden',
  );

  return $form;
}