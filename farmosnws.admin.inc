<?php

/**
 *
 * Module configuration form
 * 
 * @return Returns loaded form array object
 */
function farmosnws_admin_form() {
  $form = array();
  
  $form['farmosnws_weather_feeds_dir'] = array(
    '#type' => 'textfield',
    '#title' => t('Feeds Directory'),
    '#required' => TRUE,
    '#description' => t('The full directory path to where weather feeds should be saved to.'),
    '#default_value' => variable_get('farmosnws_weather_feeds_dir'),
  );
  
  $form['farmosnws_locations'] = array(
    '#type' => 'textarea',
    '#title' => t('Locations'),
    '#description' => t('Enter the locations that you would like weather data pulled for. Each location must be entered on a separate line.'),
    '#required' => TRUE,
    '#default_value' => variable_get('farmosnws_locations'),
  );
  
  return system_settings_form($form);
}

/**
 *
 * Validate the module settings
 */
function farmosnws_admin_form_validate($form, &$form_state) {
  $weatherfeedsdir = $form_state['values']['farmosnws_weather_feeds_dir'];
  
  $direxist = farmosnws_create_feed_dir($weatherfeedsdir);
  if ( $direxist == FALSE ){
    watchdog('farmosnws', 'Unable to create the weather feed directory.', array(), WATCHDOG_ERROR, NULL);
    form_set_error('farmosnws_weather_feeds_dir', 'The weather feed directory cannot be created. Please verify that Drupal as write permissions and try again.');
  }
  else {
    // watchdog('farmosnws', 'Created weather feed directory.', array(), WATCHDOG_INFO, NULL);
  } // end if
} // end if
