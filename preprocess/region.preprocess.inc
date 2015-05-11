<?php

/**
 * Implements hook_preprocess_region().
 */
function stellar_preprocess_region(&$variables) {
  // Combine wrapper classes with the region classes.
  if (isset($variables['elements']['#wrapper_classes'])) {
    $variables['classes_array'] = array_merge($variables['classes_array'], $variables['elements']['#wrapper_classes']);
  }

  switch ($variables['region']) {
    case 'content':
      // Unset region__mininmal set by omega base.
      unset($variables['theme_hook_suggestions'][0]);
      // Add role="main" to the main-content region.
      $variables['attributes_array']['role'] = 'main';
      break;
  }
}
