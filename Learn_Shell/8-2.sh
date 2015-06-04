#! /opt/local/bin/bash

str=`ls /etc | grep "^po"`

# ^ indicates the begin of a line
# ^po indicates the line beginning with po

echo "$str"
