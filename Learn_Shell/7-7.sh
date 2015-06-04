#! /opt/local/bin/bash

students=(John Rose Tom Tim)

echo "the old students are: ${students[*]}"

students[0]=Susan
students[3]=Jack

echo "the new students are: ${students[*]}"

declare -A grades
grades=([John]=90 [rose]=87 [tim]=78 [tom]=85 [jack]=76)

echo "the size of grades is: ${#grades[@]}"
echo "the old grades are: ${grades[@]}"

grades[tim]=84

echo "the new grades are: ${grades[@]}"
