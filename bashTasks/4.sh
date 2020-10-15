#!/bin/bash

if [ -z $1 ]
then
    echo -e "Program faild, 'couse there's no an argument.\nTry again and run with an argument"
    exit
fi

if [ -e $1 ]
then
    if [ -d $1 ]
    then
        echo -e "$1 is a directory.\nTry again and give a file name"
        exit
    fi
    cntr=0
    while read;
    do
        cntr=`expr $cntr + 1`
    done < $1
    echo "$1 has $cntr line(s)"
else
    echo "$1 does not exist"
fi
