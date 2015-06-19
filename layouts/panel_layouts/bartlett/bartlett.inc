<?php
// Plugin definition
$plugin = array(
  'title' => t('Bartlett'),
  'icon' => 'bartlett.png',
  'category' => t('Panopoly'),
  'theme' => 'bartlett',
  'css' => '../panels-grids.css',
  'regions' => array(
    'sidebar' => t('Sidebar'),
    'contentheader' => t('Content Header'),
    'contentcolumn1' => t('Content Column 1'),
    'contentcolumn2' => t('Content Column 2'),
  ),
);
