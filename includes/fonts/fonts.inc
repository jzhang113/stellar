<?php

/**
 * @file
 * Main extension file for the 'fonts' extension.
 */

/**
 * Implements hook_extension_EXTENSION_registry_alter().
 */
function stellar_extension_fonts_theme_registry_alter(&$registry) {
  if (omega_theme_get_setting('typekit_id', TRUE) || omega_theme_get_setting('typekit_class', TRUE)) {
    $registry['html']['preprocess functions'][] = 'stellar_extension_fonts_preprocess_html';
  }
}

/**
 * Implements hook_extension_EXTENSION_preproces_html().
 */
function stellar_extension_fonts_preprocess_html(&$variables) {
  // Typekit integration.
  if (omega_extension_enabled('fonts')) {
    $typkit_id = omega_theme_get_setting('typekit_id');
    $typkit_class = omega_theme_get_setting('typekit_class');
    // Include typkit assets.
    if (!empty($typkit_id)) {
      drupal_add_js('http://use.typekit.net/' . $typkit_id . '.js');
      drupal_add_js('try{Typekit.load();}catch(e){}', array('type' => 'inline'));
    }
    if (!empty($typkit_class)) {
      // Set the font using a class on the body.
      $variables['classes_array'][] = $typkit_class;
    }
  }
}
