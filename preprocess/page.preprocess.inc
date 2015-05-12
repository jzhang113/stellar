<?php

/**
 * Implements hook_preprocess_page().
 */
function stellar_preprocess_page(&$variables) {
  // Set the sidebar position.
  if (omega_extension_enabled('layouts')) {
    $sidebar_pos = omega_theme_get_setting('omega_sidebar');
  }
  else {
    $sidebar_pos = 'second';
  }

  // Add a grid def. for the main-content region.
  if (!empty($variables['page']['sidebar']) && $sidebar_pos === 'first') {
    $variables['page']['content']['#wrapper_classes'][] =  'span8-5';
    $variables['page']['sidebar']['#wrapper_classes'][] =  'span4-1';
  }
  elseif (!empty($variables['page']['sidebar']) && $sidebar_pos === 'second') {
    $variables['page']['content']['#wrapper_classes'][] =  'span8-1';
    $variables['page']['sidebar']['#wrapper_classes'][] =  'span4-9';
  }
}
