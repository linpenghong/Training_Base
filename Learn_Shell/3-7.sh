#! /bin/bash

# parameters of a function are also local variables
func()
{
    local v2=200 # using local command to define a local variable
}

func
echo "$v2"
