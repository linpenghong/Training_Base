#! /opt/local/bin/bash

a=(1 2 3 4 5)

echo "the result is ${a[@]/3/100}"

echo "the old array is ${a[@]}"

a=(${a[@]/3/100})

echo "the new array is ${a[@]}"
