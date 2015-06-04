#! /opt/local/bin/bash

linux=("Debian" "RedHat" "Ubuntu" "Suse" "Fedora" "UTS" "CentOS")

array=(${linux[@]:2:4})

length="${#array[@]}"

echo "the length of new array is $length"

for ((i=0;i<length;i++))
do
    echo "${array[$i]}"
done
