#!/bin/bash

# The first parameter should e a name, the second a number
if [ $# -lt 2 ]
then
    echo "Not enough parameters"
    exit 1
fi


# echo "Example shell script\t2020\nWelcome!"
echo -e "Example shell script\t2020\nWelcome!"

# Command line parameters
echo $0
echo $1
echo $2

# run command
echo
echo "List of files:"
ls

# run a command inside a string
echo
echo "Timestamp: `date`"

# run another script
echo
echo "Greeting: `./hello.sh`"

ii=1
count=$2
if [ $count -ge 10 ]
then
    echo "Updating count"
    count=10
fi

while [ $ii -le $count ]
do
    echo "$count : $ii : $1"
    ii=$((ii+1))
done
