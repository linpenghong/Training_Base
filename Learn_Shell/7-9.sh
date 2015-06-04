#! /opt/local/bin/bash

array=(1 2)

echo "${array[@]}"

array[2]=3
array[3]=4

echo "${array[@]}"
