<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * itsecurity theme.
 */

/**
 * Implements theme_breadcrumb().
 */
function itsecurity_breadcrumb(&$variables) {
  $output = '';
  if (!empty($variables['breadcrumb'])) {
    $output = '<div id="breadcrumb" class="breadcrumb-container"><h2 class="element-invisible">You are here</h2><ul class="breadcrumb">';
    $switch = array('odd' => 'even', 'even' => 'odd');
    $zebra = 'even';
    $last = count($variables['breadcrumb']) - 1;
    $seperator = '<span class="breadcrumb-seperator">/</span>';
    foreach ($variables['breadcrumb'] as $key => $item) {
      $zebra = $switch[$zebra];
      $attributes['class'] = array('depth-' . ($key + 1), $zebra);
      if ($key == 0) {
        $attributes['class'][] = 'first';
      }
      if ($key == $last) {
        $attributes['class'][] = 'last';
        $output .= '<li' . drupal_attributes($attributes) . '>' . $item . '</li>' . '';
      }
      else {
        $output .= '<li' . drupal_attributes($attributes) . '>' . $item . '</li>' . $seperator;
      }
    }
    $output .= '</ul></div>';
    return $output;
  }
}

/**
 * Implements hook_omega_theme_libraries_info().
 */
function itsecurity_omega_theme_libraries_info() {
  $libraries['rem'] = array(
    'name' => t('REM unit polyfill'),
    'description' => t('A polyfill to parse CSS links and rewrite pixel equivalents into head for non supporting browsers.'),
    'vendor' => 'Chuck Carpenter',
    'vendor url' => 'http://chuckcarpenter.github.io/REM-unit-polyfill/',
    'package' => t('Polyfills'),
    'files' => array(
      'js' => array(
        'rem.min.js' => array(
          'browsers' => array('IE' => '(gte IE 6)&(lte IE 8)', '!IE' => FALSE),
          'weight' => 110,
          'every_page' => TRUE,
        ),
      ),
    ),
    'variants' => array(
      'source' => array(
        'name' => t('Source'),
        'description' => t('During development it might be useful to include the source files instead of the minified version.'),
        'files' => array(
          'js' => array(
            'rem.js' => array(
              'browsers' => array('IE' => '(gte IE 6)&(lte IE 8)', '!IE' => FALSE),
              'weight' => 110,
              'every_page' => TRUE,
            ),
          ),
        ),
      ),
    ),
  );

  return $libraries;
}
