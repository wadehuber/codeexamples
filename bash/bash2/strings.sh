#!/bin/bash

str="This is a string"

echo "String $str"
echo "Length ${#str}"
echo "First 3 characters ${str:0:3}"
echo "Last 3 characters ${str: -3}" 

# Upper / lower case using declare
declare -u upper
declare -l lower
upper=$str
lower=$str

echo
echo "Upper case (declare): $upper"
echo "Lower case (declare): $lower"

# Upper / lower case using parameter expansion
echo "String (uppercase): ${str^^}"
echo "String (uppercase): ${str,,}"

# String as a result of a shell command
echo
date=$(date)
echo "Date: $date"
day_of_week=$(echo $date | cut -d' ' -f1)
echo "Day of the week: $day_of_week"
str3=$(whoami)
echo "String 3: $str3"
str3=$(ls -ltr | tail -1)
echo "String 3: $str3"
str4=$(echo "This is a test" | cut -d' ' -f4)
echo "String 4: $str4"

