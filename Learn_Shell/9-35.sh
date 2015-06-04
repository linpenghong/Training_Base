#! /opt/local/bin/bash

result=`cut -d : -f 1,6 /etc/passwd`
# cut --> get columns out
# -d --> field seperator
# -f --> the columns chosen
echo "$result"

result=`cut -d : -f 1-3 /etc/passwd`
echo "$result"

result=`cut -d : -f 3- /etc/passwd`
echo "$result"

result=`cut -d : -f 1,2,4-5 /etc/passwd`
echo "$result"
