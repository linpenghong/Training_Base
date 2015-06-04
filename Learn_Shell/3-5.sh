#! /bin/bash

func()
{
    echo "$v1"
    v1=200
}

v1=100 # it is a global variable
func

echo "$v1"
