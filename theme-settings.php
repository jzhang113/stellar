<?php

/**
 * @file
 * Theme settings file for the stellar theme.
 */

require_once dirname(__FILE__) . '/template.php';

/**
 * Implements hook_form_FORM_alter().
 */
function stellar_form_system_theme_settings_alter(&$form, $form_state) {
  // Unset omega_layout options.
  $unset_layouts = array('simple', 'off-canvas', 'divine', 'hero');
  foreach ($unset_layouts as $layout) {
    unset($form['omega']['layouts']['settings']['omega_layout']['#options'][$layout]);
    unset($form['omega']['layouts']['settings']['omega_layout'][$layout]);
  }

  // Add an option to use the theme's default page template file.
  $form['omega']['layouts']['settings']['omega_layout']['#options']['default'] = 'Page Template';
  $form['omega']['layouts']['settings']['omega_layout']['default'] = array(
      '#description' => t('Use the theme default page.tpl.php file.'),
    );
  // Set the default option.
  $form['omega']['layouts']['settings']['omega_layout']['#default_value'] = omega_theme_get_setting('omega_layout', FALSE);

  // Add configuration for rendering the sidebar region.
  $form['omega']['layouts']['settings']['omega_sidebar'] = array(
    '#type' => 'radios',
    '#options' => array('first' => 'First', 'second' => 'Second'),
    '#title' => t('Sidebar position'),
    '#description' => t('Select whether the sidebar region is rendered in the first or second position.'),
    '#default_value' => omega_theme_get_setting('omega_sidebar', FALSE),
  );
  $form['omega']['layouts']['settings']['omega_sticky_navigation'] = array(
    '#type' => 'checkbox',
    '#default_value' => omega_theme_get_setting('omega_sticky_navigation', 0),
    '#title' => t('Enable Sticky Navigation'),
    '#return_value' => 1,
  );
}
