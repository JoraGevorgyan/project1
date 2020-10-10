#!/bin/bash

if [ -e $1 ]
then 
    if [ -d $1 ]
    then echo "$1 is a directory"
    else echo "$1 is a regular file"
    fi
else
    echo "ther is not a directory or regular file"
fi
