#! /bin/bash

sum()
{
    let "z = $1 + $2" # paramaters are sent in by the same way of a shell script
    return "$z"
}

sum 22 4
echo "$?"
