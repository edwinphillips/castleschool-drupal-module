<?php

if (!$response = $_REQUEST) {
  die;
}

define('DRUPAL_ROOT', dirname(__FILE__) . '/../../../..');
require_once(DRUPAL_ROOT . '/includes/bootstrap.inc');
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

if ($response['transStatus'] == 'Y') {

  // Write the WorldPay response to the database
  $fields = array(
    'worldpay_data' => json_encode($response),
    'booking_id' => $response['cartId'],
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
  $subject = 'Payment Confirmation from The Castle School of English';

  $markup  = '<h1>Payment Confirmation from The Castle School of English</h1>';
  $markup .= "<p>Thank you for your payment to The Castle School of English against course booking Id #{$response['cartId']}. This email is confirmation of your payment.</p>";
  $markup .= "<p>Your payment ID is #{$paymentid}.</p>";
  $markup .= '<table>';
  $markup .= '<tr>';
  $markup .= '<td>Amount:</td>';
  $markup .= "<td>&pound;{$response['amount']}</td>";
  $markup .= '</tr>';
  $markup .= '</table>';

  if (($outstandingfee - $response['authAmount']) > 0) {
    $markup .= '<p>You selected to make a partial payment against your booking - in order to settle the outstanding balance of £' . ($outstandingfee - $response['authAmount']) . ', please <a href="' . $base_root . '/castleschool/payment/' . $response['cartId'] . '">click here</a>.</p>';
  }

  $markup .= '<table style="width:400px" cellspacing="0" cellpadding="0" border="0">';
  $markup .= '<tbody>';
  $markup .= '<tr>';
  $markup .= '<td>';
  $markup .= '<p>Yours sincerely,</p>';
  $markup .= '</td>';
  $markup .= '</tr>';
  $markup .= '<tr>';
  $markup .= '<td>';
  $markup .= '<span style="font-family:Calibri;font-size:12pt;font-weight:bold;color:rgb(51,51,51)"><br/>The Castle School of English</span>';
  $markup .= '</td>';
  $markup .= '</tr>';
  $markup .= '<tr>';
  $markup .= '<td>';
  $markup .= '<span style="color:#333333;font-size:10pt;font-family:Calibri"><br/>T: <a href="denied:tel:+4401273748185" style="color:#06c">+44 (0) 1273 748185</a></span>';
  $markup .= '</td>';
  $markup .= '</tr>';
  $markup .= '<tr>';
  $markup .= '<td>';
  $markup .= '<span style="color:#333333;font-size:10pt;font-family:Calibri">E: <a href="mailto:info@castle-school.co.uk" style="color:#06c">info@castle-school.co.uk</a></span>';
  $markup .= '</td>';
  $markup .= '</tr>';
  $markup .= '<tr>';
  $markup .= '<span style="color:#333333;font-size:10pt;font-family:Calibri">W: <a href="' . $base_root . '" style="color:#06c">' . $base_root . '</a></span>';
  $markup .= '</td>';
  $markup .= '</tr>';
  $markup .= '<tr>';
  $markup .= '<td style="padding-top:20px;padding-bottom:20px"><a href="' . $base_root . '"><img src="' . $base_root . '/sites/default/files/castle-school-logo_1.png" alt="The Castle School of English" style="display:block" width="170" height="52"></a></td>';
  $markup .= '</tr>';
  $markup .= '<tr>';
  $markup .= '<td style="padding-top:10px;padding-bottom:6px" valign="middle">';
  $markup .= '<table cellspacing="0" cellpadding="0" border="0">';
  $markup .= '<tbody>';
  $markup .= '<tr>';
  $markup .= '<td style="padding-right:5px"><a href="https://www.facebook.com/CastleSchoolofEnglish"> <img style="display:block" src="' . $base_root . '/sites/all/modules/castleschool/img/facebook.jpg" alt="image" width="24" height="24"></a></td>';
  $markup .= '<td style="padding-right:5px"><a href="https://twitter.com/castleschool"> <img style="display:block" src="' . $base_root . '/sites/all/modules/castleschool/img/twitter.jpg" alt="image" width="24" height="24"></a></td>';
  $markup .= '<td style="padding-right:5px"><a href="https://www.youtube.com/channel/UC-sFhlO1P8I2Jq4SpnmgWcA"> <img style="display:block" src="' . $base_root . '/sites/all/modules/castleschool/img/youtube.jpg" alt="image" width="24" height="24"></a></td>';
  $markup .= '</tr>';
  $markup .= '</tbody>';
  $markup .= '</table>';
  $markup .= '</td>';
  $markup .= '</tr>';
  $markup .= '<tr>';
  $markup .= '<td style="max-width:400px;text-align:justify;border-top:1px solid rgb(169, 169, 169);padding-top:3px;font-size:8pt;color:rgb(136, 136, 136)" colspan="2"> <span style="font-family:Calibri;font-size:8pt;color:rgb(136, 136, 136)"><br/><strong>The Castle School of English is registered in the UK as company number 6405679 12 Dyke Road, Brighton, East Sussex, England, BN1 3FE</strong><br><br>The information within this email is confidential and solely for the use of the intended recipient(s). If you receive this email in error, please notify the sender and delete the email from your system immediately. In such instances you must not make use of the email or its contents. Views expressed in this email do not necessarily reflect the views of The Castle School of English.<br><br></span></td>';
  $markup .= '</tr>';
  $markup .= '</tbody>';
  $markup .= '</table>';

  $body = $markup;

  simple_mail_send($from, $to, $subject, $body);

  $url = '/payment-confirmation';
} else if ($response['rawAuthCode'] == 'C') {
  $url = '/payment-cancelled';
} else {
  $url = '';
}
?>
<meta http-equiv="refresh" content= "0;URL=<?php echo $base_root . $url; ?>" />
