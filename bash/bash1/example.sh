#!/bin/bash

# Parameter 1 is a name, parameter 2 is a number

echo "Example\t\tshell\t\tscript"
echo -e "Example\t\tshell\t\tscript"

# run command
echo
echo "Your files: "
ls

# run a command inside a string
echo "Date: `date`"

# run a different shell script
./hello.sh $1


ii=1
while [ $ii -le $2 ] 
do
  echo $ii
  ii=$((ii+1))
done
