#! /bin/bash

func()
{
    echo "global variable v1 is $v1"
    local v1=2
    echo "local variable v1 is $v1"
}

v1=1
func
echo "global variable v1 is $v1"
