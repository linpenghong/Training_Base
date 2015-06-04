#! /bin/bash

func()
{
    echo "all parameters are $*"
    echo "all parameters are $@"
    echo "the script's name is $0"
    echo "the first parameter is $1"
    echo "the second parameter is $2"
}

func hello world
