<?php

if (!$response = $_REQUEST) {
  die;
}

define('DRUPAL_ROOT', dirname(__FILE__) . '/../../../..');
require_once(DRUPAL_ROOT . '/includes/bootstrap.inc');
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

if ($response['transStatus'] == 'Y') {

  // Create/retrieve the users Drupal account
  if (!$account = user_load_by_mail($response['email'])) {

    // Generate a random password
    $password = user_password(8);

    // Set up the user fields
    $fields = array(
      'name' => $response['email'],
      'mail' => $response['email'],
      'pass' => $password,
      'status' => 0,
      'init' => 'email address',
      'roles' => array(
        DRUPAL_AUTHENTICATED_RID => 'authenticated user',
        4 => 'Student',
      ),
    );

    // Create user
    $account = user_save('', $fields);
  }

  // Write the WorldPay response to the database
  $fields = array(
    'worldpay_data' => json_encode($response),
    'booking_id' => $response['cartId'],
    'user_id' => $account->uid,
  );
  $paymentid = db_insert('castleschool_payments')->fields($fields)->execute();

  // Look up the current outstanding balance on the booking
  $query = db_select('castleschool_bookings', 'b')
    ->fields('b', array('outstanding_fee'))
    ->condition('b.booking_id', $response['cartId'])
    ->execute();
  $result = $query->fetchObject();
  $outstandingfee = $result->outstanding_fee;

  // Set the booking new outstanding amount
  $fields = array(
    'outstanding_fee' => $outstandingfee - $response['authAmount']
  );

  // Set the booking status to confirmed if payment covers outstanding
  if ($response['authAmount'] >= $outstandingfee) {
    $fields['status_id'] = 1;
  }

  $bookingid = db_update('castleschool_bookings')->fields($fields)
          ->condition('booking_id', $response['cartId'], '=')->execute();

  // Send user an email
  $from = 'info@castle-school.co.uk';
  $to = $response['email'];
  $subject = 'Payment Received';
  $body = "Thanks, your payment for booking ID {$response['cartId']} has been received.";
  simple_mail_send($from, $to, $subject, $body);

  $url = 'payment-confirmation';
} else if ($response['rawAuthCode'] == 'C') {
  $url = 'payment-cancelled';
} else {
  $url = '';
}
?>
<meta http-equiv="refresh" content= "0;URL=<?php echo 'https://staging.castle-school.co.uk/' . $url; ?>" />