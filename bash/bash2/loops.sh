#!/bin/bash

# Examples of loops

ii=1
max=$1

# if no parameter was given, 10 is default
max=${max:=10}

# If parameter is passed, use that as max

echo
echo "While loop:"
while [[ $ii -le $max ]]
do
    echo $ii
    ii=$((ii+1))
done

echo
echo "For loop:"
for ii in {1..5}
do
    echo $ii
done    

echo "For loop (files):"
for script in *.sh
do
    echo $script
done

echo
echo "C-style for loop:"
for ((ii=1;ii<=$max;ii++))
do
    echo $ii
done

echo
echo "Until loop:"
ii=1
until [[ $ii -gt $max ]]
do
    echo $ii
    ii=$((ii+1))
done

echo
echo "Break out of loop:"
ii=1
while [[ $ii -le 1000 ]]
do
    if [ $ii -gt $max ] 
    then
        echo "Breaking ..."
        break
    fi
    echo $ii
    ii=$((ii+1))
done

echo
echo "Loop over results of a command"
scripts=($(find . -name "*.sh"))
for scriptfile in ${scripts[@]}
do
  echo "  $scriptfile"
done

