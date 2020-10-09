#!/bin/sh

docker build . > build.txt #write building output in build.txt file

file="build.txt"

while read line
do
    curLine=$line #in curLine will be last line of the file
done<$file

firstWord=`echo $curLine | cut -c 1-12` #first 12 symbols

if [ $firstWord = "Successfully" ]
then
    ID=`echo $curLine | cut -b 20-32` #if Successfully built, then last 12 symboles are image ID
else
    echo "something were wrong, can't build successfully"
    exit
fi

echo "write any name, for your repository"
read name

docker run --name $name $ID

docker tag $ID $name:unknownVersion

docker run -it $ID sh #run bash terminal in image

