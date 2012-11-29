<?php

function post_tweet($tweet_text) {
  $path = drupal_get_path('module', 'wordofthehour');

  // Use Matt Harris' OAuth library to make the connection
  // This lives at: https://github.com/themattharris/tmhOAuth
  require_once($path . '/includes/tmhOAuth.php');
      
  // Set the authorization values
  // In keeping with the OAuth tradition of maximum confusion, 
  // the names of some of these values are different from the Twitter Dev interface
  // user_token is called Access Token on the Dev site
  // user_secret is called Access Token Secret on the Dev site
  // The values here have asterisks to hide the true contents 
  // You need to use the actual values from Twitter
  $connection = new tmhOAuth(array(
    'consumer_key' => variable_get('wordofthehour_consumer_key', ''),
    'consumer_secret' => variable_get('wordofthehour_consumer_secret', ''),
    'user_token' => variable_get('wordofthehour_user_token', ''),
    'user_secret' => variable_get('wordofthehour_user_secret', ''),
  )); 
  
  // Make the API call
  $connection->request('POST', 
    $connection->url('1.1/statuses/update'), 
    array('status' => $tweet_text));
  watchdog('twitter', var_export($connection->response, TRUE));

  return $connection->response['response'];
}
