<?php

/**
 * @file
 * Single column layout for Sitenow standard service
 */

// Plugin definition.
$plugin = array(
  'title' => t('Zero'),
  'icon' => 'preview.png',
  'category' => t('Sitenow Standard content layouts'),
  'theme' => 'zero',
  'css' => '../../../css/layouts/zero/zero.layout.css',
  'regions' => array(
    'first' => t('Content'),
  ),
);

/**
 * Implements hook_preprocess_zero().
 */
function template_preprocess_zero(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-zero';
  $variables['attributes_array']['class'][] = 'panel-display--zero';

  foreach($variables['content'] as $name => $item) {
    $variables['region_attributes_array'][$name]['class'][] = 'zero-region';
    $variables['region_attributes_array'][$name]['class'][] = 'zero-region--' . drupal_clean_css_identifier($name);
  }
}
