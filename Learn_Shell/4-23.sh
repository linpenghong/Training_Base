#! /bin/sh

echo "Please enter a score:"

read score

if [ -z "$score" ]
then
    # if score is empty, then re-enter the score
    read score
else
    if [ "$score" -lt 0 -o "$score" -gt 100 ]
    then
        read score
    else
        if [ "$score" -ge 90 ]
        then
            echo "The grade is A."
        elif [ "$score" -ge 80 ]
        then
            echo "The grade is B."
        elif [ "$score" -ge 70 ]
        then
            echo "The grade is C."
        elif [ "$score" -ge 60 ]
        then
            echo "The grade is D." 
        else
            echo "The grade is E."
        fi
    fi
fi
