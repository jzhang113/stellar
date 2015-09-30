<?php

/**
 * Implements hook_preprocess_html().
 */
function tier_preprocess_html(&$variables) {
  // Add the term vocabulary as a body class for term pages.
  if (arg(0) == 'taxonomy' && arg(1) == 'term') {
    $term = taxonomy_term_load(arg(2));
    $variables['classes_array'][] = 'vocabulary-' . strtolower($term->vocabulary_machine_name);
  }

  // Add sidebar info.
  if (!empty($variables['page']['sidebar'])) {
    $variables['classes_array'][] = 'sidebar';
  }
  else {
    $variables['classes_array'][] = 'no_sidebars';
  }
}
