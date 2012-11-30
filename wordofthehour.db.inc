<?php

function wordofthehour_store_definition($word, $definition) {
  $sql = "UPDATE {wordofthehour}
          SET definition = :definition
          WHERE word = :word;";

  $result = db_query($sql, array(
                             ':definition' => $definition,
                             ':word' => $word,
  ));
}

function wordofthehour_get_random_word() {
  $sql = "SELECT word
          FROM {wordofthehour}
          WHERE definition IS NULL
          ORDER BY RAND()
          LIMIT 1;";

  $word = db_query($sql)->fetchField();

  return $word;
}

function wordofthehour_set_word_as_posted($word) {
  $sql = "UPDATE {wordofthehour}
         SET posted = 1
         WHERE word = :word";

  db_query($sql, array(
                   ':word' => $word
  ));
}
