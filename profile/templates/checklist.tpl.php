
<p>
  Niet alle controles werden met success doorlopen.
  Los de genoemde punten op en herlaad de pagina.
</p>

<ol class="task-list">
  <?php foreach ($steps as $step => $name): ?>
    <?php if ($step == $current): ?>
      <li class="active"><?php print $name; ?> <span class="element-invisible">(active)</span></li>
    <?php endif; ?>
    <?php if (array_search($step, array_keys($steps)) < array_search($current, array_keys($steps))): ?>
      <li class="done"><?php print $name; ?></span></li>
    <?php endif; ?>
    <?php if (array_search($step, array_keys($steps)) > array_search($current, array_keys($steps))): ?>
      <li><?php print $name; ?></li>
    <?php endif; ?>
  <?php endforeach; ?>
</ol>