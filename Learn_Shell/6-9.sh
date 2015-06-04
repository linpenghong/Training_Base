#! /bin/bash

func()
{
    echo "the function has $# parameters."
}

func a b c d e f g h hello
func 12 3 "hello world"
func
