
<form action="<?php print $action; ?>" method="post" id="install-select-profile-form" accept-charset="UTF-8">

  <?php if ($errors): ?>
  <ul class="messages-list error">
    <?php foreach ($errors as $error): ?>
      <li><?php print $error; ?></li>
    <?php endforeach; ?>
  </ul>
  <?php endif; ?>

  <div class="form-item form-type-textfield">
    <label for="name">Naam van website</label>
    <input type="text" id="name" name="name" class="form-text" value="<?php print $values['name']; ?>" size="64" />
  </div>

  <div class="form-item form-type-textfield">
    <label for="name">E-mailadres</label>
    <input type="text" id="mail" name="mail" class="form-text" value="<?php print $values['mail']; ?>" size="64" />
  </div>

  <div class="form-item form-type-textfield">
    <label for="domain">Domeinnaam</label>
    <input type="text" id="domain" name="domain" class="form-text" value="<?php print $values['domain']; ?>" size="64" />
  </div>

  <div class="form-item form-type-textfield">
    <label for="password">Beheerwachtwoord</label>
    <input type="text" id="password" name="password" class="form-text" value="<?php print $values['password']; ?>" size="64" />
  </div>

  <div class="form-item form-type-textfield">
    <label for="password">Herhaal wachtwoord</label>
    <input type="text" id="password2" name="password2" class="form-text" value="<?php print $values['password2']; ?>" size="64" />
  </div>

  <div class="form-item form-type-submit">
    <input type="submit" id="submit" class="form-submit" value="Instellingen opslaan" />
  </div>

</form>
