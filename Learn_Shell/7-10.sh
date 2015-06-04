#! /opt/local/bin/bash

declare -A array

array=([a]=a [b]=b)

echo "the old elements are ${array[@]}"

array[c]=c

echo "the new elements are ${array[@]}"
