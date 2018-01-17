<?php

/**
 *
 * Module configuration form
 * 
 * @return Returns loaded form array object
 */
function farmosnws_admin_form() {
  farmosnws_check_farmos_measurements();
  farmosnws_check_cron_time();
  
  $form = array();
  
  $form['farmosnws_weather_feeds_dir'] = array(
    '#type' => 'textfield',
    '#title' => t('Feeds Directory'),
    '#required' => TRUE,
    '#description' => t('The full directory path to where weather feeds should be saved to. Do not use <i>public:///</i> or <i>private://</i> schema.'),
    '#default_value' => variable_get('farmosnws_weather_feeds_dir'),
  );
  
  $form['farmosnws_locations'] = array(
    '#type' => 'textfield',
    '#title' => t('Locations'),
    '#description' => t('Enter the locations that you would like weather data pulled for. Each location must be entered must be separated by commas. Feeds can be found on the ' . l('NWS XML feeds page', 'http://w1.weather.gov/xml/current_obs/') . '.'),
    '#required' => TRUE,
    '#default_value' => variable_get('farmosnws_locations', 'KMGM'),
  );
  
  $form['farmosnws_delete_xml'] = array(
    '#type' => 'select',
    '#title' => t('Delete Processed XML'),
    '#required' => TRUE,
    '#options' => array(
      'yes' => 'Yes',
      'no' => 'No',
    ),
    '#description' => t('Delete the National Weather Service XML feed after it has been processed.'),
    '#default_value' => variable_get('farmosnws_delete_xml', 'yes'),
  );
  
  $form['farmosnws_feed_threshold'] = array(
    '#type' => 'select',
    '#title' => t('Feed Pull Frequency'),
    '#required' => TRUE,
    '#options' => array(
      // 'all' => 'Everytime Cron Runs',
      '3600' => '1 Hour',
      '' => '2 Hours',
      '' => '3 Hours',
      '' => '6 Hours',
      '' => '12 Hours', 
    ),
    '#description' => t('Select the frequency to pull the latest weather data. This depends on cron being properly configured.'),
    '#default_value' => variable_get('farmosnws_feed_threshold', 3600),
  );
  
  return system_settings_form($form);
}

/**
 *
 * Validate the module settings
 */
function farmosnws_admin_form_validate($form, &$form_state) {
  // validate that the work directory exists and can be created
  $weatherfeedsdir = $form_state['values']['farmosnws_weather_feeds_dir'];
  
  $direxist = farmosnws_create_feed_dir($weatherfeedsdir);
  if ( $direxist == FALSE ){
    form_set_error('farmosnws_weather_feeds_dir', 'The weather feed directory cannot be created. Please verify that Drupal as write permissions and try again.');
  }
} // end if

