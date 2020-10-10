#!/bin/sh

readDir () {
    if [ -d $1 ]
    then
        echo "$1 ->"
        Files=()
        cd $1
        ls > .files.txt
        while read file
        do
            Files+=$file
        done<".files.txt"
        rm .files.txt
        for tmp in "${Files[@]}"
        do
            if [ -d $tmp ]
            then
                readDir $tmp
            else
                echo $tmp
            fi
        done
        cd ..
    else
        echo $1
    fi
}
        



if [ -e $1 ]
then
    readDir $1
else
    echo "$1 does not exist"
fi
