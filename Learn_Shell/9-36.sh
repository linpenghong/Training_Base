#! /opt/local/bin/bash

# cut -c --> get the characters out of a line

result=`cut -c 1-3,5 /etc/passwd`

echo "$result"
