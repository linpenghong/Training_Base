#! /bin/bash

no1=4
no2=5

let result=no1+no2
echo $result

let no1++
echo $no1

let no1--
echo $no1

let no1+=6
echo $no1

let no1-=6
echo $no1

# Using [] Operator as Aternative

result=$[ no1 + no2 ]
echo $result

result=$[ $no1 + 5 ] # Using $ Inside [] is OK
echo $result

result=$[ no1 + 5]
echo $result
