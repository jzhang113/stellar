<?php

/**
 * @file
 * 5 region layout with full-width banner(first), header top(second), 
 * header left(third), header right(fourth) and content(fifth) region for 
 * SiteNow Standard service.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Aries'),
  'icon' => 'preview.png',
  'category' => t('Sitenow Standard content layouts'),
  'theme' => 'aries',
  'css' => '../../../css/layouts/aries/aries.layout.css',
  'regions' => array(
    'first' => t('Banner'),
    'second' => t('Header Left'),
    'third' => t('Header Right'),
    'fourth' => t('Content'),
  ),
);

/**
 * Implements hook_preprocess_aries().
 */
function template_preprocess_aries(&$variables) {
  $variables['attributes_array']['class'][] = 'panel-aries';
  $variables['attributes_array']['class'][] = 'panel-display--aries';

  foreach($variables['content'] as $name => $item) {
    if ($name == 'second') {
      $variables['region_attributes_array'][$name]['class'][] = 'span8-1';
    }
    if ($name == 'third'){
      $variables['region_attributes_array'][$name]['class'][] = 'span4-9';
    }
    if ($name == 'fourth') {
      $variables['region_attributes_array'][$name]['class'][] = 'clear';
    }
    $variables['region_attributes_array'][$name]['class'][] = 'aries-region';
    $variables['region_attributes_array'][$name]['class'][] = 'aries-region--' . drupal_clean_css_identifier($name);
  }
}
