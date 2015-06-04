#! /opt/local/bin/bash

if [ $1 -gt 4 ]
then
    echo "column no. could not be greater than 4."
    exit
fi

result=`sort -r -k $1 demo5.txt`
# -r --> reverse
# -k --> key column

echo "$result"
