<?php

/**
 * @file
 * Stellar theme template overrides as well as (pre-)process and alter hooks.
 */

/**
 * Implements theme_breadcrumb().
 */
function stellar_breadcrumb(&$variables) {
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
function stellar_omega_theme_libraries_info() {
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

/**
 * Implements hook_preprocess_views_view_unformatted().
 */
function stellar_preprocess_views_view_unformatted(&$variables) {

  // Apply float spans to views-grids views.
  $view_classes = $variables['view']->display_handler->options['css_class'];
  if (!empty($view_classes)) {
    // There might be multiple classes defined in the view.
    $view_classes = explode(' ', $view_classes);
    if (in_array('views-grid', $view_classes)) {
      // Apply floatspan and grid classes to each row.
      foreach ($variables['classes'] as $delta => &$row) {
        $row_count = $delta + 1;
        // Grid of 12, so 4 spans of 3.
        $row[] = 'floatspan3';
        // First of row.
        if ($row_count % 4 == 1) {
          $row[] = 'grid-first';
        }
        // Last of row.
        elseif ($row_count % 4 == 0) {
          $row[] = 'grid-last';
        }
        // Also apply classes to classes_array[].
        $variables['classes_array'][$delta] = implode(' ', $row);
      }
    }
  }

}
