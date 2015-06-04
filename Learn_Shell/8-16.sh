#! /opt/local/bin/bash

str=`egrep "800-[[:digit:]]{3}-[[:digit:]]{4}$" demo3.txt`

echo "$str"
