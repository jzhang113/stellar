<?php

/**
 * Implements hook_preprocess_block().
 */
function tier_preprocess_block(&$variables) {
  // Set classes from page_preprocess().
  if (isset($variables['elements']['#wrapper_classes'])) {
    foreach ($variables['elements']['#wrapper_classes'] as $class) {
      $variables['classes_array'][] = $class;
    }
  }
}
