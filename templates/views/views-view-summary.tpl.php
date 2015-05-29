<?php
/**
 * @file views-view-summary.tpl.php
 * Default simple view template to display a list of summary lines
 *
 * @ingroup views_templates
 */
global $base_path;
$panel_base_path = $base_path . $view->style_options['base_path'];
?>

<div class="item-list">
  <ul class="views-summary">
  <?php foreach ($rows as $id => $row): ?>
    <li>

      <?php if ($row_classes[$id] == 'active'): ?>
        <a href="<?php print $panel_base_path; ?>" class="has-filter" title="Remove Filter">
          <span class="label">Remove Filter</span>
          <span <?php print !empty($row_classes[$id]) ? ' class="'. $row_classes[$id] .'"' : ''; ?>><?php print $row->link; ?></span>
          <?php if (!empty($options['count'])): ?>
            <span class="summary-count"><?php print $row->count?></span>
          <?php endif; ?>
        </a>

      <?php else:; ?>
    		<a href="<?php print $row->url; ?>"<?php print !empty($row_classes[$id]) ? ' class="'. $row_classes[$id] .'"' : ''; ?>><?php print $row->link; ?>
    		<?php if (!empty($options['count'])): ?>
          <span class="summary-count"><?php print $row->count?></span>
        <?php endif; ?>
    		</a>
      <?php endif; ?>

    </li>
  <?php endforeach; ?>
  </ul>
</div>
