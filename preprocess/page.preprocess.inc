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
  if (!empty($variables['page']['sidebar_first']) && $sidebar_pos === 'first') {
    $variables['page']['content']['#wrapper_classes'][] =  'span8-5';
    $variables['page']['sidebar_first']['#wrapper_classes'][] =  'span4-1';
  }
  elseif (!empty($variables['page']['sidebar_first']) && $sidebar_pos === 'second') {
    $variables['page']['content']['#wrapper_classes'][] =  'span8-1';
    $variables['page']['sidebar_first']['#wrapper_classes'][] =  'span4-9';
  }

  // Create attributes for the header region.
  $variables['page']['header']['classes_array'][] = 'l-header';
  $variables['page']['header']['classes_array'][] = 'pattern';
  $variables['page']['header']['attributes_array']['role'] = 'banner';
  $variables['page']['header']['attributes_array']['class'] = implode(" ", $variables['page']['header']['classes_array']);
  $variables['header_attributes'] = drupal_attributes($variables['page']['header']['attributes_array']);

  // Footer block grid def.
  foreach ($variables['page']['footer'] as $key => &$block) {
    if (isset($block['#block']) && $key != '#region') {
      $classes = array();
      $classes[] = 'floatspan4';
      if (!is_float($block['#weight']/3)) {
        $classes[] = 'clear';
      }
      $block['#wrapper_classes'] = $classes;
    }
  }
}
