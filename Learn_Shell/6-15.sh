#! /bin/bash

func()
{
    echo "Number of elements is $#."
    while [ $# -gt 0 ]
    do
        echo "$1"
        shift
    done
}

a=(a b c "c d" e)
func "${a[@]}"
# ${a[@]} --> every element of this array
