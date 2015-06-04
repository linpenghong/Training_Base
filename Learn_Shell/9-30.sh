#! /opt/local/bin/bash

nl -b a 9-1.sh > textwithlineno.txt
# -b --> style of display
# a : add line number to all lines
# t : add line number to all non-empty lines
# n : do not add line number

cat textwithlineno.txt
