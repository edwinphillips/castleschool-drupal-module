<?php

echo '<pre>';
print_r($_REQUEST);
echo '</pre>';
die;

class WorldPay_Response {

  // define properties
  public $transaction_id = null;
  public $transaction_status = null;
  public $transaction_time = null;
  public $authorisation_amount = null;
  public $authorisation_currency = null;
  public $authorisation_amount_string = null;
  public $raw_auth_message = null;
  public $raw_auth_code = null;
  public $callback_password = null;
  public $card_type = null;
  public $authentication = null;
  public $ip_address = null;
  public $character_encoding = null;
  public $future_payment_id = null;
  public $future_payment_status_change = null;

  // custom properties not included by worldpay
  public $mc_custom_property = null;

  // constructor
  public function __construct() {
    $this->cartId = $_POST['cartId'];
    $this->courseId = $_POST['MC_courseId'];
    $this->paymentType = $_POST['MC_paymentType'];
    $this->transaction_id = $_POST['transId'];
    $this->transaction_status = $_POST['transStatus']; // should be either Y (successful) or C (cancelled)
    $this->transaction_time = $_POST['transTime'];
    $this->authorisation_amount = $_POST['authAmount'];
    $this->authorisation_currency = $_POST['authCurrency'];
    $this->authorisation_amount_string = $_POST['authAmountString'];
    $this->raw_auth_message = $_POST['rawAuthMessage'];
    $this->raw_auth_code = $_POST['rawAuthCode'];
    $this->callback_password = $_POST['callbackPW'];
    $this->card_type = $_POST['cardType'];
    $this->country_match = $_POST['countryMatch']; // Y - Match, N - Mismatch, B - Not Available, I - Country not supplied, S - Issue Country not available
    $this->waf_merchant_message = $_POST['wafMerchMessage'];
    $this->authentication = $_POST['authentication'];
    $this->ip_address = $_POST['ipAddress'];
    $this->character_encoding = $_POST['charenc'];
    $this->future_payment_id = $_POST['futurePayId'];
    $this->future_payment_status_change = $_POST['futurePayStatusChange'];

    //custom properties
    $this->mc_custom_property = $_POST['MC_custom_property'];
    $this->cartType = $_POST['MC_cartType'];
  }
}

$wp_response = new WorldPay_Response();

?>
<meta http-equiv="refresh" content= "0;URL=<?php echo LINK_URL_HOME ?>thankyou.php" />
<?php
echo '<pre>';
print_r($wp_response);
echo '</pre>';
die;