#! /bin/bash

log=Run_Train_Log.txt

total=1023

#echo Total Running Distance `echo $total + `awk '{sum += $2;}; END {print sum}' $log` | bc`KM
total=$(echo $total + `awk '{sum += $2;}; END {print sum}' $log` | bc)
echo Total Running Distance : ${total} KM
echo

echo Last 5 Training Log:
tail -n 5 $log
echo

avg=0
function avgPace()
{
    distance=$(tail -n $1 $log | awk '{sum += $2;}; END {print sum}')
    h=$(tail -n $1 $log | awk '{sum += $3;}; END {print sum}')
    m=$(tail -n $1 $log | awk '{sum += $4;}; END {print sum}')
    s=$(tail -n $1 $log | awk '{sum += $5;}; END {print sum}')
    t=$[ h * 3600 + m * 60 + s ]
    t=$(echo 'scale=2;' $t / 60 | bc)
    avg=$(echo 'scale=2;' $t / $distance | bc)
}

avgPace +1
echo -e "Average Pace, Life Time :" ${avg} MIN/KM
avgPace 5
echo -e "Average Pace, Last 5    :" ${avg} MIN/KM
avgPace 1
echo -e "Average Pace, Lastest   :" ${avg} MIN/KM
