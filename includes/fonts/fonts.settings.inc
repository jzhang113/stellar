<?php

/**
 * @file
 * Contains the theme settings form elements for the fonts extension.
 */

/**
 * Implements hook_extension_EXTENSION_theme_settings_form_alter().
 */
function stellar_extension_fonts_settings_form($element, &$form, $form_state) {
  $element['omega_typekit'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Typkit fonts'),
    '#description' => t('Typekit fonts'),
    '#default_value' => omega_theme_get_setting('omega_typekit', TRUE),
  );

  $element['typekit'] = array(
    '#type' => 'fieldset',
    '#title' => t('Typekit'),
    '#states' => array(
      'visible' => array(
        'input[name="omega_typekit"]' => array('checked' => TRUE),
      ),
    ),
  );

  $element['typekit']['typekit_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Typkit ID'),
    '#description' => t('Enter your typkeit ID.'),
    '#default_value' => omega_theme_get_setting('typekit_id', FALSE),
  );

  $element['typekit']['typekit_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Typkit Body Class'),
    '#description' => t('Enter the class name for the typekit font. This class will be implemented on the body tag. Use this configuration if your theme only supports one custom font.'),
    '#default_value' => omega_theme_get_setting('typekit_class', FALSE),
  );

  $element['omega_google_fonts'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Google fonts'),
    '#description' => t('Google fonts'),
    '#default_value' => omega_theme_get_setting('omega_google_fonts', TRUE),
  );

  $element['google_fonts'] = array(
    '#type' => 'fieldset',
    '#title' => t('Google Fonts'),
    '#states' => array(
      'visible' => array(
        'input[name="omega_google_fonts"]' => array('checked' => TRUE),
      ),
    ),
  );

  $element['google_fonts']['google_font_import'] = array(
    '#type' => 'textfield',
    '#title' => t('@import Code'),
    '#description' => t('Enter the @import code, Step 3 from Google Fonts Quick Use under the @import tab. For example: <strong>@import url(https://fonts.googleapis.com/css?family=Open+Sans:600italic,800italic,400,600);</strong>'),
    '#default_value' => omega_theme_get_setting('google_font_import', FALSE),
  );

  $element['google_fonts']['google_font_css'] = array(
    '#type' => 'textfield',
    '#title' => t('CSS font-family Code'),
    '#description' => t('Enter CSS code, Step 4 from Google Fonts Quick Use. For example: <strong>font-family: "Open Sans", sans-serif;</strong>'),
    '#default_value' => omega_theme_get_setting('google_font_css', FALSE),
  );

  return $element;
}
