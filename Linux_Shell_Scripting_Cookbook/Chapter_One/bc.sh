#! /bin/bash

echo "4 * 0.56" | bc

no=54
result=`echo "$no * 1.5" | bc`
echo $result

# scale=2 -> set the number of decimal places to 2
echo "scale=2; 3/8" | bc

# base convention with bc
# ibase -> base of input
# obase -> base of output
no=100
echo "obase=2;$no" | bc

# Calulcating Square and Square Root
echo "sqrt(100)" | bc
echo "10^10" | bc
