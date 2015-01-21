

<div id="prereq">
  <h1>LET OP!</h1>
  <p>
    Zorg voordat u verder gaat dat de volgende modules op de server aanwezig zijn:
  </p>
  <ul>
    <li>Actieve Apache2 modules
    <ul>
      <li>expires</li>
      <li>headers</li>
      <li>rewrite</li>
    </ul>
    </li>
    <li>Apache vhost config
    <ul>
      <li>.htaccess toestaan</li>
      <li>open_basedir</li>
    </ul></li>
    <li>Actieve PHP modules
    <ul>
      <li>curl</li>
      <li>gd</li>
      <li>json</li>
      <li>ldap</li>
      <li>memcache</li>
      <li>mysql</li>
      <li>pear</li>
      <li>readline</li>
      <li>xsl</li>
    </ul></li>
    <li>Actieve Ruby gems
    <ul>
      <li>chunky_png (versie <= 1.3.x)</li>
      <li>compass (versie <= 0.12.x)</li>
      <li>compass-notify (versie <= 0.0.2)</li>
      <li>compass-rgbspng (versie <= 0.2.1)</li>
      <li>fssm (versie <= 0.2.10)</li>
      <li>oily_png (versie <= 1.1.x)</li>
      <li>suzy (versie <= 1.x)</li>
      <li>sass (versie <= 3.3.x)</li>
      <li>terminal-notifier (versie <= 1.6.x)</li>
    </ul>
    </li>
  </ul>
</div>

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
