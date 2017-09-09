<?php
/**
 * @file
 * farmosnws.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function farmosnws_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'weather_history';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Weather History';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Weather History';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Temperature F */
  $handler->display->display_options['fields']['field_wthr_temp_f']['id'] = 'field_wthr_temp_f';
  $handler->display->display_options['fields']['field_wthr_temp_f']['table'] = 'field_data_field_wthr_temp_f';
  $handler->display->display_options['fields']['field_wthr_temp_f']['field'] = 'field_wthr_temp_f';
  $handler->display->display_options['fields']['field_wthr_temp_f']['label'] = 'Temp';
  $handler->display->display_options['fields']['field_wthr_temp_f']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Weather */
  $handler->display->display_options['fields']['field_wthr_weather']['id'] = 'field_wthr_weather';
  $handler->display->display_options['fields']['field_wthr_weather']['table'] = 'field_data_field_wthr_weather';
  $handler->display->display_options['fields']['field_wthr_weather']['field'] = 'field_wthr_weather';
  /* Field: Content: Wind Direction */
  $handler->display->display_options['fields']['field_wthr_wind_dir']['id'] = 'field_wthr_wind_dir';
  $handler->display->display_options['fields']['field_wthr_wind_dir']['table'] = 'field_data_field_wthr_wind_dir';
  $handler->display->display_options['fields']['field_wthr_wind_dir']['field'] = 'field_wthr_wind_dir';
  /* Field: Content: Wind MPH */
  $handler->display->display_options['fields']['field_wthr_wind_mph']['id'] = 'field_wthr_wind_mph';
  $handler->display->display_options['fields']['field_wthr_wind_mph']['table'] = 'field_data_field_wthr_wind_mph';
  $handler->display->display_options['fields']['field_wthr_wind_mph']['field'] = 'field_wthr_wind_mph';
  $handler->display->display_options['fields']['field_wthr_wind_mph']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'imported_weather_conditions' => 'imported_weather_conditions',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'weather-history';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Weather';
  $handler->display->display_options['menu']['name'] = 'farm';
  $export['weather_history'] = $view;

  return $export;
}
