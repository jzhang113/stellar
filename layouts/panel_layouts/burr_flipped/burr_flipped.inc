<?php
// Plugin definition
$plugin = array(
  'title' => t('Burr Flipped'),
  'icon' => 'burr-flipped.png',
  'category' => t('Panopoly'),
  'theme' => 'burr_flipped',
  'css' => '../panels-grids.css',
  'regions' => array(
    'sidebar' => t('Sidebar'),
    'contentmain' => t('Content'),
  ),
);
