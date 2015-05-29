<?php

/**
 * @file
 * 2 Region layout with content(first) and sidebar(second) region for Sitenow standard service.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Colossus'),
  'icon' => 'preview.png',
  'category' => t('Sitenow Standard content layouts'),
  'theme' => 'colossus',
  'css' => '../../../css/layouts/colossus/colossus.layout.css',
  'regions' => array(
    'first' => t('Content'),
    'second' => t('Sidebar'),
  ),
);

/**
 * Implements hook_preprocess_colossus().
 */
function template_preprocess_colossus(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-colossus';
  $variables['attributes_array']['class'][] = 'panel-display--colossus';

  foreach($variables['content'] as $name => $item) {
    if ($name == 'second') {
      $variables['region_attributes_array'][$name]['class'][] = 'span4-9';
    } else {
      $variables['region_attributes_array'][$name]['class'][] = 'span8-1';
    }
    $variables['region_attributes_array'][$name]['class'][] = 'colossus-region';
    $variables['region_attributes_array'][$name]['class'][] = 'colossus-region--' . drupal_clean_css_identifier($name);
  }
}
