#! /bin/bash

x=123

let "x += 1" # increase x by 1

echo "x = $x" # will output x as 124
echo

y=${x/1/abc} # replace 1 of x by abc
echo "y = $y"
declare -i y # declare y as an integer
echo "y = $y"

let "y += 1"
echo "y = $y" # increase a integer which is not a number, it will be zero
echo

z=abc22
echo "z = $z"
m=${z/abc/11} #replace abc of z by 11
echo "m = $m"

let "m += 1" # m is formed by numbers, so shell turns it into an integer
echo "m = $m"
echo

n=""
echo "n = $n"
let "n += 1"
echo "n = $n"
echo

echo "p = $p"
let "p += 1"
echo "p = $p"
