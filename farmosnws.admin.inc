<?php 

function farmosnws_menu() {

function farmosnws_admin_form() {
  $form = array();

  $form['farmosnws_loc_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Location Code'),
    '#required' => TRUE,
    '#maxlength' => 4,
    '#default_value' => variable_get('farmosnws_loc_code',''),
  );
  $form['farmosnws_file_loc'] = array(
    '#type' => 'textfield',
    '#title' => t('File Location'),
    '#required' => TRUE,
    '#description' => t('The location on the file system were the feed is to be saved.'),
    '#default_value' => variable_get('farmosnws_file_loc', ''),
  );
  
  return system_settings_save($form);
} // end function



