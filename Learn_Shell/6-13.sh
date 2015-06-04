
#! /bin/bash

func()
{
    echo "$1"
}

var=name
name=John

func $var

func ${!var}

name=Alice

func $var
func ${!var}
