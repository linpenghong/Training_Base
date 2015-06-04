#! /opt/local/bin/bash

array=(Mon Tue Wed Thu Fri Sat Sun)

len="${#array[@]}"

for ((i=0;i<$len;i++))
do
    echo "${array[$i]}"
done
