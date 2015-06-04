#! /opt/local/bin/bash

echo -e "Toy_Story\tHK\t239\t3972" > demo5.txt
echo -e "The_Hill\tKL\t301\t4102" >> demo5.txt
echo -e "Star_Wars\tHK\t63\t2972" >> demo5.txt
echo -e "A_Few_Good_Men\tKL\t445\t5851" >> demo5.txt

result=`sort demo5.txt`
echo "$result" > sorted_default.txt

cat sorted_default.txt
