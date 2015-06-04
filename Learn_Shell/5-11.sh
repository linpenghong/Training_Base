#! /bin/bash

i=1

until [ "$i" -gt 9 ]
do
    let "square=i*i"
    echo "$i*$i=$square"
    let "i+=1"
done
