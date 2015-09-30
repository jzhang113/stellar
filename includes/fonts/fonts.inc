<?php

/**
 * @file
 * Main extension file for the 'fonts' extension.
 */

/**
 * Implements hook_extension_EXTENSION_registry_alter().
 */
function stellar_extension_fonts_theme_registry_alter(&$registry) {
  if (omega_theme_get_setting('omega_typekit', TRUE) || omega_theme_get_setting('omega_google_fonts', TRUE)) {
    $registry['html']['preprocess functions'][] = 'stellar_extension_fonts_preprocess_html';
  }
}

/**
 * Implements hook_extension_EXTENSION_preproces_html().
 */
function stellar_extension_fonts_preprocess_html(&$variables) {
  // Typekit integration.
  if (omega_extension_enabled('fonts') && omega_theme_get_setting('omega_typekit', TRUE)) {
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

  // Google font integration.
  if (omega_extension_enabled('fonts') && omega_theme_get_setting('omega_google_fonts', TRUE)) {
    $google_font_import = omega_theme_get_setting('google_font_import');
    $google_font_css = omega_theme_get_setting('google_font_css');
    // Include google font assets and css.
    if (!empty($google_font_import) && !empty($google_font_css)) {
      $google_css = 'body { ' . $google_font_css . '}';
      drupal_add_css($google_font_import, array('type' => 'inline'));
      drupal_add_css($google_css, array('type' => 'inline'));
    }
  }
}
