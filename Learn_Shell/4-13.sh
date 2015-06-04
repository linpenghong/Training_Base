#! /bin/bash

test -d dir1 # test dir1 is a dir or not
echo $?

test -f file1 # test file1 is a regular file
echo $?

test -s file2 # test file2 is a not-empty file
echo $?

test -b file1 # test file1 is a block file
echo $?
