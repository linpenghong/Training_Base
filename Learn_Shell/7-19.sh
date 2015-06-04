#! /opt/local/bin/bash

# slice : ${array[@]:start:length}

linux=("Debian" "RedHat" "Ubuntu" "Suse" "Fedora" "UTS" "CentOS")

echo ${linux[@]:2:4}
