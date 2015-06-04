#! /opt/local/bin/bash

cut -f 1 students.txt > students.tmp
cut -f 2 phones.txt > phones.tmp

paste students.tmp phones.tmp > contactinfo.txt

cat contactinfo.txt
