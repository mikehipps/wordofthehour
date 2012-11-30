<?php

/**
 * Admin settings for Word of the Hour
 *
 * @return
 */
function wordofthehour_settings($form, &$form_state) {
  $form = array();

  $form['wordofthehour_consumer_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Oauth Consumer Key'),
    '#default_value' => variable_get('wordofthehour_consumer_key', ''),
    '#required' => TRUE,
    '#description' => t('Oauth Consumer Key'),
  );

  $form['wordofthehour_consumer_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Oauth Consumer Secret'),
    '#default_value' => variable_get('wordofthehour_consumer_secret', ''),
    '#required' => TRUE,
    '#description' => t('Oauth Consumer Secret'),
  );

  $form['wordofthehour_user_token'] = array(
    '#type' => 'textfield',
    '#title' => t('Oauth User Token'),
    '#default_value' => variable_get('wordofthehour_user_token', ''),
    '#required' => TRUE,
    '#description' => t('Oauth User Token'),
  );

  $form['wordofthehour_user_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Oauth User Secret'),
    '#default_value' => variable_get('wordofthehour_user_secret', ''),
    '#required' => TRUE,
    '#description' => t('Oauth User Secret'),
  );


  return system_settings_form($form);
}
