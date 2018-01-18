<?php

/**
 *
 * Module configuration form
 * 
 * @return Returns loaded form array object
 */
function farmosnws_admin_form() {
  // check the variables that support this module
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
      '7200' => '2 Hours',
      '10800' => '3 Hours',
      '21600' => '6 Hours',
      '43200' => '12 Hours', 
    ),
    '#description' => t('Select the frequency to pull the latest weather data. This depends on cron being properly configured.'),
    '#default_value' => variable_get('farmosnws_feed_threshold', 3600),
  );
  
  $form['farmosnws_dataset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Data to Save'),
    '#description' => t('Select the data elements that you wish to save'),
  );
  
  $form['farmosnws_dataset']['farmosnws_log_temperature'] = array(
    '#type' => 'checkbox',
    '#title' => t('Temperature'),
    '#default_value' => variable_get('farmosnws_log_temperature'),
  );
  
  $form['farmosnws_dataset']['farmosnws_log_pressure'] = array(
    '#type' => 'checkbox',
    '#title' => t('Barametric Pressure'),
    '#default_value' => variable_get('farmosnws_log_pressure'),
  );
  
  $form['farmosnws_dataset']['farmosnws_log_windspeed'] = array(
    '#type' => 'checkbox',
    '#title' => t('Wind Speed'),
    '#default_value' => variable_get('farmosnws_log_windspeed'),
  );
  
  $form['farmosnws_dataset']['farmosnws_log_winddirection'] = array(
    '#type' => 'checkbox',
    '#title' => t('Wind Direction'),
    '#default_value' => variable_get('farmosnws_log_winddirection'),
  );
  
  $form['farmosnws_dataset']['farmosnws_log_visibility'] = array(
    '#type' => 'checkbox',
    '#title' => t('Visibility'),
    '#default_value' => variable_get('farmosnws_log_visibility'),
  );
  
  $form['farmosnws_dataset']['farmosnws_log_weather'] = array(
    '#type' => 'checkbox',
    '#title' => t('Weather Description'),
    '#default_value' => variable_get('farmosnws_log_weather'),
  );
  
  $form['farmosnws_dataset']['farmosnws_log_dewpoint'] = array(
    '#type' => 'checkbox',
    '#title' => t('Dew Point'),
    '#default_value' => variable_get('farmosnws_log_dewpoint'),
  );

  $form['farmosnws_dataset']['farmosnws_log_humidity'] = array(
    '#type' => 'checkbox',
    '#title' => t('Relative Humidity'),
    '#default_value' => variable_get('farmosnws_log_humidity'),
  );
  
  return system_settings_form($form);
}

/**
 * Validate the module settings form
 */
function farmosnws_admin_form_validate($form, &$form_state) {
  // validate that the work directory exists and can be created
  $weatherfeedsdir = $form_state['values']['farmosnws_weather_feeds_dir'];
  
  $direxist = farmosnws_create_feed_dir($weatherfeedsdir);
  
  if ($direxist == FALSE) {
    form_set_error('farmosnws_weather_feeds_dir', 'The weather feed directory cannot be created. Please verify that Drupal as write permissions and try again.');
  }
} // end if

