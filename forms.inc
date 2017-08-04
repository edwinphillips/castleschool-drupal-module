<?php

/* Teaser Form */

function castleschool_teaser_form($form, &$form_state, $weeks, $nodeid) {

  $courseselected = isset($form_state['values']['course']) ? $form_state['values']['course'] : 1;
  $weeksselected = isset($form_state['values']['weeks']) ? $form_state['values']['weeks'] : 4;

  $form['course'] = array(
    '#type' => 'select',
    '#title' => t('I want to study'),
    '#options' => castleschool_get_courses(),
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

  $form['quote'] = array(
    '#markup' => '<div class="castle-quote-wrapper"></div>',
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

function castleschool_teaser_form_submit($form, &$form_state) {

  extract($form_state['values']);

  $_SESSION['castleschool_course'] = $course;
  $_SESSION['castleschool_hoursperweek'] = $hoursperweek;
  $_SESSION['castleschool_month'] = $month;
  $_SESSION['castleschool_day'] = $day;
  $_SESSION['castleschool_weeks'] = $weeks;
  $_SESSION['castleschool_coursequote'] = castleschool_get_coursequote($course, $hoursperweek, $weeks);

  $form_state['redirect'] = 'search-for-accommodation';
}

function castleschool_hoursperweek_callback($form, $form_state) {

  $hoursperweek = castleschool_get_hoursperweek($form['course']['#default_value'], $form_state['values']['weeks']);
  $form['hoursperweek']['#options'] = $hoursperweek;

  return $form['hoursperweek'];
}

function castleschool_day_callback($form, $form_state) {

  $form['day']['#options'] = castleschool_get_mondays_in_month($form['month']['#default_value']);

  return $form['day'];
}

/* Choose Your Course Form */

function castleschool_choose_course_form($form, &$form_state, $weeks) {

  $form['course'] = array(
    '#type' => 'select',
    '#title' => t('I want to study'),
    '#default_value' => $form->course,
    '#options' => castleschool_get_courses(),
    '#default_value' => 1,
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $months = castleschool_get_months();
  $selected = isset($form_state['values']['months']) ? $form_state['values']['months'] : key($months);

  $form['months'] = array(
    '#type' => 'select',
    '#title' => t('From'),
    '#options' => $months,
    '#default_value' => $selected,
    '#ajax' => array(
      'callback' => 'castleschool_quote_select_callback',
      'wrapper' => 'castleschool_quote_day_wrapper',
    ),
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $form['firstday'] = array(
    '#type' => 'select',
    '#title' => t(' '),
    '#prefix' => '<div id="castleschool_quote_day_wrapper">',
    '#suffix' => '</div>',
    '#options' => castleschool_get_mondays_in_month($selected),
    '#default_value' => isset($form_state['values']['firstday']) ? $form_state['values']['firstday'] : '',
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

  $form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Start Quote'),
  );

  return $form;
}

function castleschool_choose_course_form_validate($form, &$form_state) {

}

function castleschool_choose_course_form_submit($form, &$form_state) {

  $form_state['redirect'] = 'search-for-accommodation';
}

/* Search for Accommodation form */

function castleschool_search_for_accommodation_form($form, &$form_state, $weeks) {

  $form['intro'] = array(
    '#markup' => '<p>' . t('We need to know a little bit about you before we can find suitable accommodation.') . '</p>',
  );

  $form['accommodationduration'] = array(
    '#type' => 'select',
    '#title' => t('How long do you want to stay?'),
    '#options' => $weeks,
    '#default_value' => array_keys($weeks)[0],
    '#required' => FALSE,
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $form['age'] = array(
    '#type' => 'textfield',
    '#title' => t('Age when you start your course'),
    '#size' => 3,
    '#maxlength' => 3,
    '#default_value' => $_SESSION['age'],
    '#required' => TRUE,
    '#element_validate' => array('element_validate_number'),
  );

  $form['back_button'] = array(
    '#markup' => '<a id="back_button" class="btn btn-warning" href="/choose-your-course">Back</a>'
  );

  $form['no_accommodation_button'] = array(
    '#markup' => '<a class="btn btn-warning" href="/airport-transfers">I do not require accommodation</a>',
  );

  $form['search_button'] = array(
    '#type' => 'submit',
    '#name' => 'search_button',
    '#value' => t('Search'),
    '#submit' => array('castleschool_search_for_accommodation_form_submit'),
  );

  return $form;
}

function castleschool_search_for_accommodation_form_validate($form, &$form_state) {

  if (!empty($form_state['values']['age']) && $form_state['values']['age'] < 16) {
    form_set_error('title', 'You must be at least 16 years old when you start your course');
  }
}

function castleschool_search_for_accommodation_form_submit($form, &$form_state) {

  $_SESSION['accommodationduration'] = $form_state['values']['accommodationduration'];
  $_SESSION['age'] = $form_state['values']['age'];

  $form_state['redirect'] = 'choose-your-accommodation';
}

/* Choose Accommodation Form */

function castleschool_choose_accommodation_form($form, &$form_state) {

  $form['table'] = array(
    '#markup' => castleschool_accommodation_selection_table(),
  );

  $form['back_button'] = array(
    '#markup' => '<a class="btn btn-warning" href="/search-for-accommodation">' .t('Back') .'</a>',
  );

  $form['no_accommodation_button'] = array(
    '#markup' => '<a id="no_accommodation_button" class="btn btn-warning" href="/airport-transfers">' . t('I don\'t require accommodation') . '</a>',
  );

  return $form;
}

function castleschool_accommodation_selection_table() {

  $accommodationduration = $_SESSION['accommodationduration'];

  $header = array();
  $rows = array(
    array(
      '<h5>Homestay (single room, half board) - <strong>£' . 145 * $accommodationduration . '</strong></h5>',
      '<a class="btn btn-submit" href="/choose-your-accommodation/1">' .t('Select') .'</a>',
    ),
    array(
      '<h5>Homestay (twin room, half board) - <strong>£' . 125 * $accommodationduration . '</strong></h5>',
      '<a class="btn btn-submit" href="/choose-your-accommodation/2">' .t('Select') .'</a>',
    ),
    array(
      '<h5>Room only (self-catering) - <strong>£' . 125 * $accommodationduration . '</strong></h5>',
      '<a class="btn btn-submit" href="/choose-your-accommodation/3">' .t('Select') .'</a>',
    ),
    array(
      '<h5>Self-catering Twin room - <strong>£' . 105 * $accommodationduration . '</strong></h5>',
      '<a class="btn btn-submit" href="/choose-your-accommodation/4">' .t('Select') .'</a>',
    ),
  );

  return theme(
    'table',
    array(
      'header' => $header,
      'rows' => $rows
    )
  );
}

/* Airport Transfers Form */

function castleschool_airport_transfers_form($form, &$form_state) {

  $form['intro'] = array(
    '#markup' => '<p>' . t('Would you like taxi transport from the airport to your accommodation?') . '</p>',
  );

  $form['whichairport'] = array(
    '#type' => 'select',
    '#title' => t('Which airport will you arrive at?'),
    '#options' => array(
      0 => t('I do not require an airport transfer'),
      1 => t('Gatwick'),
      2 => t('Heathrow'),
      3 => t('Stanstead'),
      4 => t('Luton'),
    ),
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $form['arrivaldeparture'] = array(
    '#type' => 'select',
    '#title' => t('Would you like just an Arrival transfer or Arrival and Departure?'),
    '#options' => array(
      0 => t('- Select -'),
      1 => t('Arrival Transfer'),
      2 => t('Departure Transfer'),
      3 => t('Arrival & Departure Transfer'),
    ),
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

  // Note: Needs to be 2 options here - either choose accommodation or search for accommodation

  $form['back_button'] = array(
    '#markup' => '<a class="btn btn-warning" href="/search-for-accommodation">Back</a>'
  );

  $form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Next'),
  );

  return $form;
}

function castleschool_airport_transfers_form_validate($form, &$form_state) {

  if ($form_state['values']['whichairport'] != 0 &&
      $form_state['values']['arrivaldeparture'] == 0 &&
      $form_state['complete form']['arrivaldeparture']['#states']['required'][':input[name="whichairport"]']['!value'] == 0) {
    form_set_error('title', t('Would you like just an Arrival transfer or Arrival and Departure field is required.'));
  }
}

function castleschool_airport_transfers_form_submit($form, &$form_state) {

  if ($form_state['values']['whichairport']) {
    switch ($form_state['values']['whichairport']) {
      case 1:
        $airporttransferquote = 80;
        break;
      case 2:
        $airporttransferquote = 130;
        break;
      case 3:
        $airporttransferquote = 160;
        break;
      case 4:
        $airporttransferquote = 160;
    }
  }

  if ($form_state['values']['arrivaldeparture'] == 3) {
    $airporttransferquote *= 2;
  }

  $_SESSION['airporttransferquote'] = $airporttransferquote;

  $form_state['redirect'] = 'your-quote';
}

/* Final Quote Form */

function castleschool_finalquote_form($form, &$form_state) {

  $form['back_button'] = array(
    '#markup' => '<a class="btn btn-warning" href="/airport-transfers">' . t('Back') . '</a>',
  );

  $form['contactus_button'] = array(
    '#markup' => '<a class="btn btn-warning" href="/">' . t('Contact Us') . '</a>',
  );

  $form['emailquote_button'] = array(
    '#markup' => '<a class="btn btn-warning" href="/">' . t('Email Quote') . '</a>',
  );

  $form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Book now'),
  );

  return $form;
}

function castleschool_finalquote_form_validate($form, &$form_state) {

}

function castleschool_finalquote_form_submit($form, &$form_state) {

  $form_state['redirect'] = 'booking-form';
}

/* Booking Form */

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
    '#required' => FALSE,
  );

  $form['lastname'] = array(
    '#type' => 'textfield',
    '#title' => t('Last name'),
    '#size' => 40,
    '#maxlength' => 40,
    '#required' => FALSE,
  );

  $form['dob'] = array(
    '#type' => 'textfield',
    '#title' => t('Date of birth'),
    '#size' => 10,
    '#maxlength' => 10,
    '#required' => FALSE,
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
    '#required' => FALSE,
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
    '#required' => FALSE,
  );

  $form['passport'] = array(
    '#type' => 'textfield',
    '#title' => t('Passport Number'),
    '#size' => 30,
    '#maxlength' => 30,
    '#required' => FALSE,
  );

  $form['telephone'] = array(
    '#type' => 'textfield',
    '#title' => t('Telephone'),
    '#size' => 30,
    '#maxlength' => 30,
    '#required' => FALSE,
  );

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#size' => 40,
    '#maxlength' => 40,
    '#required' => FALSE,
  );

  $form['address'] = array(
    '#type' => 'textarea',
    '#title' => t('Address'),
    '#size' => 500,
    '#maxlength' => 500,
    '#required' => FALSE,
  );

  $form['nextofkin'] = array(
    '#type' => 'textfield',
    '#title' => 'Next of kin',
    '#size' => 40,
    '#maxlength' => 40,
    '#required' => FALSE,
  );

  $form['nextofkintelephone'] = array(
    '#type' => 'textfield',
    '#title' => 'Next of kin telephone',
    '#size' => 40,
    '#maxlength' => 40,
    '#required' => FALSE,
  );

  $form['nextofkinaddress'] = array(
    '#type' => 'textarea',
    '#title' => t('Next of kin address'),
    '#size' => 500,
    '#maxlength' => 500,
    '#required' => FALSE,
  );

  $form['married'] = array(
    '#type' => 'select',
    '#title' => 'Are you married?',
    '#required' => FALSE,
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

  $form['smoke'] = array(
    '#type' => 'select',
    '#title' => 'Do you smoke?',
    '#required' => FALSE,
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
    '#title' => 'Do you have any medical conditions?',
    '#required' => FALSE,
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
    '#title' => 'Are you allergic to any animals?',
    '#required' => FALSE,
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

  $form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Book Now'),
  );

  return $form;
}

function castleschool_bookingform_form_validate($form, &$form_state) {

}

function castleschool_bookingform_form_submit($form, &$form_state) {

  $formvals = $form_state['values'];
  unset($formvals['submit_button']);
  unset($formvals['form_build_id']);
  unset($formvals['form_id']);
  unset($formvals['op']);
  extract($formvals);

  $from = 'no-reply@castle-school.co.uk';
  $to = 'info@castle-school.co.uk';
  $subject = 'Castle School Course Booking';
  $body = '<p>A course booking has been received from the Castle School website.</p>';
  $body .= '<p>The details submitted are as follows:</p>';
  $body .= '<ul>';
  foreach ($formvals as $key => $value) {
    $title = $form_state['complete form'][$key]['#title'];
    $body .= '<li>' . $title . ': ' . $value . '</li>';
  }
  $body .= '</ul>';

  simple_mail_send($from, $to, $subject, $body); // not on dev

  $form_state['redirect'] = 'booking-confirmation';
}
