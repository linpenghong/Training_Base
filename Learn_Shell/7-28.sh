#! /bin/bash

content=(`cat "demo.txt"`)

for s in "${content[@]}"
do
    echo "$s"
done
