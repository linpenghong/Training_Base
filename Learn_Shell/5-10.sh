#! /bin/bash

array=(Monday Tuesday Wednesday Thursday Friday Saturday Sunday)

for day in ${array[*]}
do
    echo $day
done
