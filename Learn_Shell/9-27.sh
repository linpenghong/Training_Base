#! /opt/local/bin/bash

result=`sort -t : -k 3n,3 /etc/passwd`
# -t : --> let field seperator be :

echo "$result"
