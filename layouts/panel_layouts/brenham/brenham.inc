<?php
// Plugin definition
$plugin = array(
  'title' => t('Brenham'),
  'icon' => 'brenham.png',
  'category' => t('Panopoly'),
  'theme' => 'brenham',
  'css' => '../panels-grids.css',
  'regions' => array(
    'header' => t('Header'),
    'sidebar' => t('Content Sidebar'),
    'contentmain' => t('Content'),
  ),
);
