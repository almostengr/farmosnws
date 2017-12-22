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
    '#type' => 'textfield',
    '#title' => t('Locations'),
    '#description' => t('Enter the locations that you would like weather data pulled for. Each location must be entered must be separated by commas.'),
    '#required' => TRUE,
    '#default_value' => variable_get('farmosnws_locations'),
  );
  
  $form['farmosnws_temp_units'] = array(
    '#type' => 'select',
    '#title' => t('Measurement Units'),
    '#required' => TRUE,
    '#options' => array(
      'us' => t('Fahrenheit'),
      'metric' => t('Celsius'),
    ),
    '#description' => t('Select the system of measurement that you would like to use.'),
    '#default_value' => variable_get('farmosnws_temp_units'),
  );
  $form['farmosnws_delete_xml'] = array(
    '#type' => 'select',
    '#title' => t('Delete Processed XML'),
    '#required' => TRUE,
    '#options' => array(
      'Yes',
      'No',
    ),
    '#description' => t('Delete the National Weather Service XML feed after it has been processed.'),
    '#default_value' => variable_get('farmosnws_delete_xml', 'Yes'),
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
    // watchdog('farmosnws', 'Unable to create the weather feed directory.', array(), WATCHDOG_ERROR, NULL);
    form_set_error('farmosnws_weather_feeds_dir', 'The weather feed directory cannot be created. Please verify that Drupal as write permissions and try again.');
  }
} // end if
