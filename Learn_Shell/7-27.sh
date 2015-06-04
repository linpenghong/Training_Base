#! /opt/local/bin/bash

linux=("Debian" "RedHat" "Ubuntu" "Suse" "Fedora" "UTS" "CentOS")
shell=("bash" "csh" "ksh" "rsh" "sh" "rc" "tcsh")

linuxshell=("${linux[@]}" "${shell[@]}")

echo "the new array is ${linuxshell[@]}"

echo "the length of new array is ${#linuxshell[@]}"
