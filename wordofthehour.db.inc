<?php

function wordofthehour_store_definition($word, $definition) {
  $sql = "UPDATE {wordofthehour}
          SET definition = '%s'
          WHERE word = '%s';";
  
  $result = db_query($sql, $definition, $word);
}

function wordofthehour_get_random_word() {
  $sql = "SELECT word
          FROM {wordofthehour}
          WHERE definition IS NULL
          ORDER BY RAND()
          LIMIT 1;";

  $word = db_result(db_query($sql));

  return $word;
}

function wordofthehour_set_word_as_posted($word) {
  $sql = "UPDATE {wordofthehour}
         SET posted = 1
         WHERE word = '%s'";

  db_query($sql, $word);
}
