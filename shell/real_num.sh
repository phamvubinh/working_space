#floating mathermatic
a=10.5 b=2.6
c=`echo $a + $b | bc`
d=`echo $a - $b | bc`
e=`echo $a / $b | bc`
f=`echo $a % $b | bc`
g=`echo $a \* $b | bc`
echo $c $d $e $f $g
