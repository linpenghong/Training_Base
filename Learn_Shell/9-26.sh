#! /opt/local/bin/bash

result=`sort -n -k 3,3 demo5.txt`
# -n --> handle it numerically
# -k --> key

echo "$result"
