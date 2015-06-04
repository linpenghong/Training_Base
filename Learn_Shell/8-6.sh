#! /opt/local/bin/bash

str=`ls /etc | grep "^rc"`
echo "$str"

str=`ls /etc | grep "^rc[0-9]"`
echo "$str"
