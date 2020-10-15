#!/bin/bash

readDir () {
        echo $1 "->"
        cd $1
        Files=()
        ls > .files.txt
        while read file
        do
            Files+="$file "
        done<".files.txt"
        rm .files.txt
        for tmp in ${Files[@]}
        do
            if [ -d $tmp ]
            then
                readDir $tmp
                echo
            else
                echo -n "$tmp "
            fi
        done
        cd ..
}
        


if [ -z $1 ]
then
    echo -e "There's no given argument.\nTry again and run programm with an argument"
    exit
fi

if [ -e $1 ]
then
    if [ -d $1 ]
    then
        readDir $1
        echo
    else
        echo $1
    fi
else
    echo "$1 does not exist"
fi
