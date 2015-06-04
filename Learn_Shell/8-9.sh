#! /opt/local/bin/bash

str=`ls /etc | egrep "(ssh|ssl|^yum)"`

echo "$str"
