<?php
/*
 * Callback for RIS Batch.
 */
function _ris_ibabs_import_batch_run(&$context) {
  if (!isset($context['sandbox']['files'])) {
    $context['sandbox']['files'] = file_scan_directory(variable_get('ris_ibabs_dir', ''), '/\.xml/i');
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['count'] = count($context['sandbox']['files']);
  }

  // Setup the file to run.
  $next = key($context['sandbox']['files']);
  $file = $context['sandbox']['files'][$next];

  $meetings = _ris_ibabs_read_file($file);
  foreach ($meetings as $meeting) {
    ris_map_node($meeting);
  }

  // This file has run. Delete it from the queue.
  $context['message'] = t('Now processing !current / !count', array('!current' => $context['sandbox']['progress'], '!count' => $context['sandbox']['count']));
  unset($context['sandbox']['files'][$next]);
  $context['sandbox']['progress']++;

  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['results']['count'] = $context['sandbox']['progress'];
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['count'];
  }
}

function _ris_ibabs_read_file($file) {
  $meetings = array();

  $dom = new DOMDocument();
  $dom->load($file->uri);
  $xpath = new DOMXPath($dom);

  $meetingNodes = $xpath->query('//vergaderingen_bestuurlijk');
  foreach ($meetingNodes as $meetingNode) {
    $meeting_id = $meetingNode->getAttribute('id');

    $date = $xpath->query('./datum', $meetingNode)->item(0)->nodeValue;
    $time = str_replace('.', ':', $xpath->query('./tijdstip', $meetingNode)->item(0)->nodeValue) . ':00';

    date_default_timezone_set('GMT');
    $timestamp = strtotime(str_replace('00:00:00', $time, $date));

    // Set basic data for the meeting.
    $meetings[$meeting_id] = array(
      'meeting_id' => $meeting_id,
      'subject' => $xpath->query('./klasse', $meetingNode)->item(0)->nodeValue,
      'timestamp' => $timestamp,
      'location' => $xpath->query('./lokatie', $meetingNode)->item(0)->nodeValue,
      'agendaitems' => array(),
    );

    $itemNodes = $xpath->query('.//agendapunt', $meetingNode);
    $nrs = array();
    foreach ($itemNodes as $itemNode) {
      $ordernr = $itemNode->getAttribute('orderNr');
      $item_id = $xpath->query('./registratiekenmerk', $itemNode)->item(0)->nodeValue;
      $nrs[$ordernr] = $item_id;

      // Set basis data for the agenda item.
      $meetings[$meeting_id]['agendaitems'][$item_id] = array(
        'item_id' => $item_id,
        'parent' => NULL,
        'subject' => $xpath->query('./onderwerp', $itemNode)->item(0)->nodeValue,
        'attachments' => array(),
      );

      $attachmentNodes = $xpath->query('.//bijlage', $itemNode);
      foreach ($attachmentNodes as $attachmentNode) {
        $meetings[$meeting_id]['agendaitems'][$item_id]['attachments'][] = array(
          'file_name' => $xpath->query('./onderwerp', $attachmentNode)->item(0)->nodeValue,
          'file_uri' => $xpath->query('./document', $attachmentNode)->item(0)->nodeValue,
        );
      }

      // Retrieve the parents node for the agendaitem.
      $ordernr_parts = explode('.', $ordernr);
      if (count($ordernr_parts) > 1) {
        unset($ordernr_parts[count($ordernr_parts)-1]);
        $parent_ordernr = implode('.', $ordernr_parts);
        if (isset($nrs[$parent_ordernr])) {
          $meetings[$meeting_id]['agendaitems'][$item_id]['parent'] = $nrs[$parent_ordernr];
        }
      }
    }
  }

  return $meetings;
}