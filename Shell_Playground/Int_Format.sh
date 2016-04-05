for i in 0 {8..11} {98..101}
do
    echo $i
    echo `printf "%0*d\n" 3 $i`
    echo Sigma_`printf "%0*d\n" 3 $i`.txt
done
