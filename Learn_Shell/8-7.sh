#! /bin/bash

str=`ls /etc | egrep "^sss+"`

# grep --> Basic Regular Expression, BRE
# egrep --> Extended Regular Expression, ERE

echo "$str"
