#! /bin/bash

result=1

fact()
{
    local n=$1
    if [ $n -eq 0 ]
    then
        result=1
    else
        let "m=n-1"
        fact $m
        let "result=$n * $?" # $? is the result of the last command
        echo $result
    fi

    return $result
}

fact "$1"

echo "Factorial of $1 is $?"
