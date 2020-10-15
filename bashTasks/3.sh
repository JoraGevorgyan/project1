#!/bin/sh
echo "type any number, and I'll print it in reverse order"
read num
res=0
while [ $num != 0 ]
do
    res=`expr $res \* 10 + $num % 10`
    num=`expr $num / 10`
done
unset num
echo $res
