#! /opt/local/bin/bash

words=`cat demo2.txt | wc -w`
# wc -w --> count the number of words
echo "there are $words words in file demo2.txt"

chars=`cat demo2.txt | wc -m`
# wc -m --> count the number of bytes
echo "there are $chars characters in file demo2.txt"
