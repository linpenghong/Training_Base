#! /bin/bash

x=6/3

echo "$x" # will print 6/3

declare -i x # declare x as an integer
echo "$x" # will print 6/3

x=6/3
echo "$x" # will print 2

x=hello
echo "$x" # will print 0

declare +i x # cancel x as an integer
x=6/3
echo "$x"

x=$[6/3] # calculate the value of 6 / 3
echo "$x"

x=$((6/3)) # calculate the value of 6 / 3
echo "$x"

declare -r x # declare x as read-only
echo "$x"
