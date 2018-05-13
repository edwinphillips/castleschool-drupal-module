<?php

$response = $_REQUEST;

// write the response to the database

// send user an email


// redirect the user
if ($response['transStatus'] == 'Y') {
  $url = 'payment-confirmation';
} else if ($response['rawAuthCode'] == 'C') {
  $url = 'payment-cancelled';
} else {
  $url = '';
}
?>
<meta http-equiv="refresh" content= "0;URL=<?php echo 'https://staging.castle-school.co.uk/' . $url; ?>" />