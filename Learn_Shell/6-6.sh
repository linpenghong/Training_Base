#! /bin/bash

length()
{
    str=$1
    result=0;
    if [ "$str" != "" ]
    then
        result=${#str}
    fi
    
    echo "$result" # write into the standard output
    # the standard output will capatured by "upper shell"
}

len=$(length "abc123")

echo "the string's length is $len"
