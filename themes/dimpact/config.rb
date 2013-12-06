# Require any additional compass plugins here.
require "susy"
require "rgbapng"

if environment == :development
  require "compass-notify"
end

# Set this to the root of your project when deployed:
http_path = "../"
css_dir = "css"
sass_dir = "scss"
images_dir = "img"
javascripts_dir = "scripts"
fonts_dir = "fonts"

# You can select your preferred output style here (can be overridden via the command line):
# output_style = :expanded or :nested or :compact or :compressed
output_style = (environment == :development) ? :compact : :compressed
project_type = :stand_alone

# To enable relative paths to assets via compass helper functions. Uncomment:
#relative_assets = true

# To disable debugging comments that display the original location of your selectors. Uncomment:
line_comments = (environment == :development) ? :true : :false

# If you prefer the indented syntax, you might want to regenerate this
# project again passing --syntax sass, or you can uncomment this:

preferred_syntax = :scss

# and then run:
# sass-convert -R --from scss --to sass sass scss && rm -rf sass && mv scss sass

module Sass::Script::Functions
  def get_env_color(var_name, default_value)
    assert_type var_name, :String
    assert_type default_value, :Color

    safe_var_name = "DOMAIN_SCSS_" + var_name.value

    if (ENV[safe_var_name])
      rgb = ENV[safe_var_name].scan(/^#?(..?)(..?)(..?)$/).first.map {|a| a.ljust(2, a).to_i(16)}
      Sass::Script::Color.new(rgb)
    else
      default_value
    end
  end
  declare :get_env_color, :args => [:string, :color]
end
