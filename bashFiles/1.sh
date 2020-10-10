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
            else
                echo $tmp
            fi
        done
        cd ..
}
        



if [ -e $1 ]
then
    if [ -d $1 ]
    then
        readDir $1
    else
        echo $1
    fi
else
    echo "$1 does not exist"
fi
