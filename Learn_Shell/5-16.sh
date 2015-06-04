#! /bin/bash

for ((i=1;i<=9;i++))
do
    for ((j=1;j<=9;j++))
    do
        let "product=i*j"
        printf "$i*$j=$product"
        if [ "$product" -gt 9 ]
        then
            printf " "
        else
            printf "  "
        fi
    done
    echo
done
  
