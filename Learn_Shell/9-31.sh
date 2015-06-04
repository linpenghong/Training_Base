#! /opt/local/bin/bash

echo -n "Please input a name: "
read name

while [ $name != "e" ]
do
    quantity=`grep -c "$name" demo2.txt`
    echo "$quantity records contain $name."
    echo -n "Please input a name:"
    read name
done
