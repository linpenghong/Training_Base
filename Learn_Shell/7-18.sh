#! /opt/local/bin/bash

array=(Mon Tue Wed Thu Fri Sat Sun)

for e in "${array[@]}"
do
    echo "$e"
done
