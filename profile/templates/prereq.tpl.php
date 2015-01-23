
<div id="prereq">
<h1>LET OP!</h1>
<p>
  Zorg voordat u verder gaat dat de volgende modules op de server geinstalleerd zijn:
</p>
<ul>
  <li><strong>Actieve Apache2 modules</strong>
    <ul>
      <li>expires</li>
      <li>headers</li>
      <li>rewrite</li>
    </ul>
  </li>
  <li><strong>Apache vhost config</strong>
    <ul>
      <li>.htaccess toestaan</li>
      <li>open_basedir</li>
    </ul></li>
    <li><strong>Actieve PHP modules</strong>
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
      <li><strong>Actieve Ruby gems</strong>
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

<h1>De onderstaande instructies/commando's zijn <strong>voorbeelden</strong> voor een Ubuntu 14.04 (trusty64) server.</h1>
<pre>
apt-get --yes install apache2 libapache2-mod-php5 mysql-server php5-mysql php-pear php5-curl php5-gd php5-json php5-readline php5-xsl ruby-dev apache2-bin g++ make

a2enmod expires headers rewrite

gem install --version "< 1.4" chunky_png --no-ri --no-rdoc
gem install --version "< 0.13" compass --no-ri --no-rdoc
gem install --version "< 2" susy --no-ri --no-rdoc
gem install compass-notify compass-rgbapng oily_png terminal-notifier --no-ri --no-rdoc
</pre>

  </div>

<form action="<?php print $action; ?>?step=settingsfile" method="post" id="install-select-profile-form" accept-charset="UTF-8">

  <div class="form-item form-type-submit">
    <input type="submit" id="submit" class="form-submit" value="Ga door" />
  </div>

</form>
