# -*- coding: utf-8 -*-
"""
Created on Wed May 29 16:22:12 2019

@author: asus
"""

# suggested by mdaoust
# from https://stackoverflow.com/questions/42821330/restore-original-text-from-keras-s-imdb-dataset

import keras
from keras.datasets import imdb

NUM_WORDS = 10000 # only use top 5000 words
INDEX_FROM = 3   # word index offset

(train_x, train_y), (test_x, test_y) = keras.datasets.imdb.load_data(
        num_words=NUM_WORDS, index_from=INDEX_FROM)

word_to_id = imdb.get_word_index()
word_to_id = {k:(v+INDEX_FROM) for k,v in word_to_id.items()}
word_to_id["<PAD>"] = 0
word_to_id["<START>"] = 1
word_to_id["<UNK>"] = 2
id_to_word = {value:key for key, value in word_to_id.items()}

review_id = 25
print(' '.join(id_to_word[num] for num in train_x[review_id] ))
