<?php
/**
 * @file
 * dimpact_transliteration.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dimpact_transliteration_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'transliteration_file_lowercase';
  $strongarm->value = 1;
  $export['transliteration_file_lowercase'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'transliteration_file_punctuation';
  $strongarm->value = array(
    'space' => '1',
    'whitespace' => '1',
    'double_quotes' => '0',
    'quotes' => '0',
    'backtick' => '0',
    'comma' => '0',
    'hyphen' => '2',
    'underscore' => '1',
    'colon' => '0',
    'semicolon' => '0',
    'pipe' => '0',
    'left_curly' => '0',
    'left_square' => '0',
    'right_curly' => '0',
    'right_square' => '0',
    'plus' => '0',
    'equal' => '0',
    'asterisk' => '0',
    'ampersand' => '0',
    'percent' => '0',
    'caret' => '0',
    'dollar' => '0',
    'hash' => '0',
    'at' => '0',
    'exclamation' => '0',
    'tilde' => '0',
    'left_parenthesis' => '0',
    'right_parenthesis' => '0',
    'question_mark' => '0',
    'less_than' => '0',
    'greater_than' => '0',
    'back_slash' => '0',
  );
  $export['transliteration_file_punctuation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'transliteration_file_separator';
  $strongarm->value = '-';
  $export['transliteration_file_separator'] = $strongarm;

  return $export;
}
