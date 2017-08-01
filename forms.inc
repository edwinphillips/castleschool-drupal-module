<?php

/* Teaser Form */

function castleschool_teaser_form($form, &$form_state, $weeks, $nodeid) {

  $courseselected = isset($form_state['values']['iwanttostudy']) ? $form_state['values']['iwanttostudy'] : t('General English');

  $form['iwanttostudy'] = array(
    '#type' => 'select',
    '#title' => t('I want to study'),
    '#options' => array(
      t('General English') => t('General English'),
      t('Cambridge Exam Prep') => t('Cambridge Exam Prep'),
      t('IELTS') => t('IELTS'),
      t('One to one') => t('One to one'),
    ),
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

  $months = castleschool_quote_month_options();
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
    '#options' => castleschool_quote_block_get_mondays($selected),
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

  $form['hoursperweek'] = array(
    '#type' => 'select',
    '#title' => '@',
    '#prefix' => '<div id="castleschool_hoursperweek_wrapper">',
    '#suffix' => '</div>',
    '#options' => castleschool_get_hoursperweek($courseselected),
    '#default_value' => isset($form_state['values']['day']) ? $form_state['values']['day'] : '',
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $form['quotetotal'] = array(
    '#type' => 'hidden',
    '#default_value' => 1080,
  );

  $markup = '<div class="castle-quote-wrapper">';
  $markup .= '<span data-bind="text: value" class="castle-quote-total">£1080</span>';
  $markup .= '<span class="castle-quote-fees"><em>inc. booking fees</em></span>';
  $markup .= '<span class="castle-quote-accomm">+&nbsp;accommodation from <span data-bind="text: value">£600</span></span>';
  $markup .= '</div>';

  $form['quote'] = array(
    '#markup' => $markup,
  );

  $form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Continue'),
  );

  return $form;
}

function castleschool_teaser_form_submit($form, &$form_state) {

  $_SESSION['castleschool_iwanttostudy'] = $form_state['values']['iwanttostudy'];
  $_SESSION['castleschool_month']        = $form_state['values']['month'];
  $_SESSION['castleschool_day']          = $form_state['values']['day'];
  $_SESSION['castleschool_weeks']        = $form_state['values']['weeks'];
  $_SESSION['castleschool_quotetotal']   = $form_state['values']['quotetotal'];

  $form_state['redirect'] = 'search-for-accommodation';
}

function castleschool_hoursperweek_callback($form, $form_state) {
  $form['hoursperweek']['#options'] = castleschool_get_hoursperweek($form['iwanttostudy']['#default_value']);

  return $form['hoursperweek'];
}

function castleschool_day_callback($form, $form_state) {
  $form['day']['#options'] = castleschool_quote_block_get_mondays($form['month']['#default_value']);

  return $form['day'];
}

function castleschool_get_hoursperweek($courseselected) {

  switch ($courseselected) {
    case t('General English'):
      $array = array(
        15 => '15 hours per week',
        21 => '21 hours per week',
        24 => '24 hours per week',
        30 => '30 hours per week'
      );
      break;
    case t('Cambridge Exam Prep'):
      $array = array(
        15 => '15 hours per week',
      );
      break;
    case t('IELTS'):
      $array = array(
        15 => '15 hours per week',
      );
      break;
    case t('One to one'):
      $array = array(
        10 => '10 hours per week',
      );
      break;
  }

  return $array;
}

/* Choose Your Course Form */

function castleschool_choose_course_form($form, &$form_state, $weeks) {

  $form['iwanttostudy'] = array(
    '#type' => 'select',
    '#title' => t('I want to study'),
    '#default_value' => $form->iwanttostudy,
    '#options' => array(
      t('General English') => t('General English'),
      t('Cambridge Exam Prep') => t('Cambridge Exam Prep'),
      t('IELTS') => t('IELTS'),
      t('One to one') => t('One to one'),
    ),
    '#default_value' => t('General English'),
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $months = castleschool_quote_month_options();
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
    '#options' => castleschool_quote_block_get_mondays($selected),
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

  $form['quotetotal'] = array(
    '#type' => 'hidden',
    '#default_value' => 1080,
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

  $form['howlong'] = array(
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
    '#size' => 40,
    '#maxlength' => 40,
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

  /* Todo: Save session vars */

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

  $weeks = $_SESSION['weeks'];

  $header = array();
  $rows = array(
    array(
      '<h5>Homestay (single room, half board) - <strong>£' . 145 * $weeks . '</strong></h5>',
      '<a class="btn btn-submit" href="/choose-your-accommodation/1">' .t('Select') .'</a>',
    ),
    array(
      '<h5>Homestay (twin room, half board) - <strong>£' . 125 * $weeks . '</strong></h5>',
      '<a class="btn btn-submit" href="/choose-your-accommodation/2">' .t('Select') .'</a>',
    ),
    array(
      '<h5>Room only (self-catering) - <strong>£' . 125 * $weeks . '</strong></h5>',
      '<a class="btn btn-submit" href="/choose-your-accommodation/3">' .t('Select') .'</a>',
    ),
    array(
      '<h5>Self-catering Twin room - <strong>£' . 105 * $weeks . '</strong></h5>',
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
      '' => t('I do not require an airport transfer'),
      t('Gatwick') => t('Gatwick'),
      t('Heathrow') => t('Heathrow'),
      t('Stanstead') => t('Stanstead'),
      t('Luton') => t('Luton'),
    ),
    '#required' => FALSE,
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
      '' => t('- Select -'),
      t('Arrival Transfer') => t('Arrival Transfer'),
      t('Departure Transfer') => t('Departure Transfer'),
      t('Arrival & Departure Transfer') => t('Arrival & Departure Transfer'),
    ),
    '#required' => FALSE,
      '#attributes' => array(
      'class' => array(
        'without-styles'
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

}

function castleschool_airport_transfers_form_submit($form, &$form_state) {

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
