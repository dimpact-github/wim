<script type="text/javascript">
var $ = jQuery;
$(function() {
  var from = 0;
  var exec = function() {
    $.get('install.php?step=database&from=' + from, function(data) {
      var progress = data.match(/^([0-9]+),(\-?[0-9]+)$/);
      if (progress) {
        $('.filled').css('width', progress[1] + '%');
        from = parseInt(progress[2]);
        if (from > 0) {
          setTimeout(exec, 100);
        }
        else {
          document.location = 'install.php?step=config';
        }
      }
      else {
        alert('Error while importing database');
      }
    });
  };
  exec();
});
</script>

<div class="progress">
  Bezig met importeren van de database.
  <div class="bar">
    <div class="filled"></div>
  </div>
</div>
