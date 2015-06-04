#! /opt/local/bin/bash

declare -A array

array=([flower]=rose [fruit]=apple)

echo "the flower is ${array[flower]}"

echo "the fruit is ${array[fruit]}"

echo "the size of the array is ${#array[@]}"
