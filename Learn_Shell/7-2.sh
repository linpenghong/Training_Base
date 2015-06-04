#! /bin/bash

declare -a array # -a is indicating it is an array

array[0]=1
array[1]=2

echo "${array[@]}"
