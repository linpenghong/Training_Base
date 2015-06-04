#! /opt/local/bin/bash

str=`ls /etc | grep -P "^rc\d"`

echo "$str"
