#! /bin/bash

func()
{
    v2=200 # v2 still is a global variable
}

func
echo "$v2"
