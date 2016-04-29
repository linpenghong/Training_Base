#! /bin/bash

fruit=apple
count=5

echo "We have $count $fruit(s)"

# Finding Length of String
var=1234567890
echo ${#var}

# Identifying the Current Shell
echo $SHELL

# Checking Whether I am a Super User
if [ $UID -ne 0 ]
then
    echo "Not Root User"
else
    echo "Root User"
fi
