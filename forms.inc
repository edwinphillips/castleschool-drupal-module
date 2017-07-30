<?php

/**
 * Choose your course form
 */

function castleschool_quote_block_form($form, &$form_state, $weeks) {

  $form['castleschool_quote_iwanttostudy'] = array(
    '#type' => 'select',
    '#title' => t('I want to study'),
    '#default_value' => $form->castleschool_quote_iwanttostudy,
    '#options' => array(
      '' => t('- Select -'),
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

  $selected = isset($form_state['values']['castleschool_quote_months']) ? $form_state['values']['castleschool_quote_months'] : key($months);

  $form['castleschool_quote_months'] = array(
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

  $form['castleschool_quote_day'] = array(
    '#type' => 'select',
    '#title' => t(' '),
    '#prefix' => '<div id="castleschool_quote_day_wrapper">',
    '#suffix' => '</div>',
    '#options' => castleschool_quote_block_get_mondays($selected),
    '#default_value' => isset($form_state['values']['castleschool_quote_day']) ? $form_state['values']['castleschool_quote_day'] : '',
    '#attributes' => array(
      'class' => array(
        'without-styles'
      ),
    ),
  );

  $form['castleschool_quote_weeks'] = array(
    '#type' => 'select',
    '#title' => t('For'),
    '#default_value' => isset($form->castleschool_quote_weeks) ? $form->castleschool_quote_weeks : 4,
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

function castleschool_quote_block_form_validate($form, &$form_state) {

}

function castleschool_quote_block_form_submit($form, &$form_state) {

  $_SESSION['castleschool_quote_iwanttostudy'] = $form_state['values']['castleschool_quote_iwanttostudy'];
  $_SESSION['castleschool_quote_months'] = $form_state['values']['castleschool_quote_months'];
  $_SESSION['castleschool_quote_day'] = $form_state['values']['castleschool_quote_day'];
  $_SESSION['castleschool_quote_weeks'] = $form_state['values']['castleschool_quote_weeks'];
  $_SESSION['quotetotal'] = $form_state['values']['quotetotal'];

  $form_state['redirect'] = 'search-for-accommodation';
}

function castleschool_quote_select_callback($form, $form_state) {
  $form['castleschool_quote_day']['#options'] = castleschool_quote_block_get_mondays($form['castleschool_quote_months']['#default_value']);

  return $form['castleschool_quote_day'];
}

/**
 * Search for Accommodation form
 */

function castleschool_search_for_accommodation_form($form, &$form_state) {

  $form['howlong'] = array(
    '#type' => 'textfield',
    '#title' => t('How long do you want to stay?'),
    '#size' => 40,
    '#maxlength' => 40,
    '#required' => TRUE,
  );

  $form['age'] = array(
    '#type' => 'textfield',
    '#title' => t('Age when you start your course'),
    '#size' => 40,
    '#maxlength' => 40,
    '#required' => TRUE,
  );

  $form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
  );

  return $form;
}

function castleschool_search_for_accommodation_form_validate($form, &$form_state) {

}

function castleschool_search_for_accommodation_form_submit($form, &$form_state) {

  $form_state['redirect'] = 'choose-your-accommodation';
}

/**
 * Choose Accommodation Form
 */

function castleschool_choose_accommodation_form($form, &$form_state) {

  $options = array(
    1 => t('Homestay, Comfort Single room, Bed & breakfast, Private bathroom'),
    2 => t('Homestay, Comfort Single room, Half board, Private bathroom'), 
    3 => t('Homestay, Standard Single room, Bed & breakfast'),
    4 => t('Homestay, Standard Single room, Half board'),
  );

  $form['accommodation_type'] = array(
    '#type' => 'radios',
    '#title' => t('Choose your accommodation'),
    '#options' => $options,
  );

  $form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Next'),
  );

  return $form;
}

function castleschool_choose_accommodation_form_validate($form, &$form_state) {

}

function castleschool_choose_accommodation_form_submit($form, &$form_state) {

  $form_state['redirect'] = 'airport-transfers';
}

/**
 * Airport Transfers Form
 */

function castleschool_airport_transfers_form($form, &$form_state) {

  $form['whichairport'] = array(
    '#type' => 'textfield',
    '#title' => t('Which airport will you arrive at?'),
    '#size' => 40,
    '#maxlength' => 40,
    '#required' => TRUE,
  );

  $form['arrivaldeparture'] = array(
    '#type' => 'textfield',
    '#title' => t('Would you like just an Arrival transfer or Arrival and Departure?'),
    '#size' => 40,
    '#maxlength' => 40,
    '#required' => TRUE,
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

/**
 * Final Quote Form
 */
function castleschool_finalquote_form($form, &$form_state) {

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

/*
 * Booking form
 */
function castleschool_bookingform_form($form, &$form_state) {

  $markup = '<p>';
  $markup .= 'If you want to secure a place on this course press "BOOK NOW" at the bottom of the form. After you send us the enrolment form we will email you to confirm your place.';
  $markup .= '</p>';

  $form['details'] = array(
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
    '#title' => t('Passport Number'),
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
    '#title' => 'Next of kin',
    '#size' => 40,
    '#maxlength' => 40,
    '#required' => TRUE,
  );

  $form['nextofkintelephone'] = array(
    '#type' => 'textfield',
    '#title' => 'Next of kin telephone',
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

  $form['married'] = array(
    '#type' => 'select',
    '#title' => 'Are you married?',
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

  $form['smoke'] = array(
    '#type' => 'select',
    '#title' => 'Do you smoke?',
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
    '#title' => 'Do you have any medical conditions?',
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
    '#title' => 'Are you allergic to any animals?',
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
