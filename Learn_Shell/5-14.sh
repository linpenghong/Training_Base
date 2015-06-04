#! /bin/bash

i=1
while [ "$i" -lt 10 ]
do
    let "square=i*i"
    echo "$i*$i=$square"
    let "i+=1"
done
