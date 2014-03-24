<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title>Nodes die updates nodig hebben</title>
  </head>

  <body style="background-color: #FFFFFF">
    <p>De volgende nodes zijn niet geupdate</p>
    
    <?php
        print '<ul>';
        foreach($nodes as $node) {
          if ($node->type) {
              print '<li><a href="/node/' . $node->nid . '">';
                print $node->title;
              print '</li>';
          }
        }
        print '</ul>';
     ?>
  </body>
</html>