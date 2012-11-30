<?php

/**
 * @file Word Of The Hour Block File
 * This file is responsible for displaying Drupal blocks for the
 * Word Of The Hour module.
 */

/**
 * Lists the Word Of The Hour Drupal blocks.
 *
 * @return Array
 *   The list of Word Of The Hour Drupal blocks.
 */
function wordofthehour_block_info() {
  $blocks['wordofthehour'] = t('Word Of The Hour Block');
  return $blocks;
}

/**
 * Renders the correct block view.
 *
 * @param string $delta
 *   A Drupal block name.
 *
 * @return string
 *   The block (corresponding to $delta) rendered as HTML.
 */
function wordofthehour_block_view($delta) {
  $block = array();

  switch ($delta) {
    case 'quick_contribution':
      drupal_add_css(drupal_get_path('module', 'wordofthehour') . '/css/wordofthehour.css');

      $block['subject'] = NULL;
      $block['content'] = ngpvanquickforms_block_quick_contribution();
      break;
  }
  return $block;

}

function wordofthehour_block_word() {
  $word = wordofthehour_get_word();
  return $word;
}

