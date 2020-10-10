#!bin/sh
if [ -e $1 ]
then
    cntr=0
    while read;
    do
        cntr=`expr $cntr + 1`
    done < $1
    echo "$1 has $cntr line(s)"
else
    echo "$1 does not exist"
fi
