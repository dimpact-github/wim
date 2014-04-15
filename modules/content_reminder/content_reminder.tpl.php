<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title>Nodes die updates nodig hebben</title>
  </head>

  <body style="background-color: #FFFFFF">
    <?php 
      print '<p>';
        print variable_get('content_reminder_' . $mailtype . '_text', 0);
      print '</p>';
        print '<ul>';
        foreach($nodes as $node) {
          if ($node->type) {
              print '<li>' . '<strong>' . $node->type . '</strong>: ' . '<a href="/node/' . $node->nid . '">';
                print $node->title;
              print '</a> ' . ($node->status == 1 ? 'Published' : 'Unpublished') . '</li>';
          }
        }
        print '</ul>';
     ?>
  </body>
</html>