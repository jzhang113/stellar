<?php

/**
 * @file
 * Contains the theme settings form elements for the fonts extension.
 */

/**
 * Implements hook_extension_EXTENSION_theme_settings_form_alter().
 */
function stellar_extension_fonts_settings_form($element, &$form, $form_state) {
  $element['omega_typekit']['typekit_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Typkit ID'),
    '#description' => t('Enter your typkeit ID.'),
    '#default_value' => omega_theme_get_setting('typekit_id', FALSE),
  );
  $element['omega_typekit']['typekit_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Typkit Body Class'),
    '#description' => t('Enter the class name for the typekit font. This class will be implemented on the body tag. Use this configuration if your theme only supports one custom font.'),
    '#default_value' => omega_theme_get_setting('typekit_class', FALSE),
  );

  return $element;
}
