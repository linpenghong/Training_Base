#! /bin/bash

echo "Please enter a number:"

read num

if [ "$num" -gt 10 ]
then
    echo "The number is greater than 10."
else
    echo "The number is equal or less than 10."
fi
