#!/bin/bash

str="This is a string"

echo "String $str"
echo "Length ${#str}"
echo "First 3 characters: ${str:0:3}"
echo "Last 3 characters: ${str: -3}"

# Upper / lowercase using declare
declare -u uStr   # uppercase string
declare -l lStr   # lowercase string

uStr=$str
lStr=$str

echo
echo "Uppercase (declare): $uStr"
echo "Lowercase (declare): $lStr"

# Upper / lowercase using parameter expansion
echo "String (uppercase): ${str^^}"
echo "String (lowercase): ${str,,}"

# String as result of shell command
echo
date=$(date)
echo "Date: $date"
day_of_week=$(echo $date | cut -d' ' -f1)
echo "Day of the week: $day_of_week"
str3=$(whoami)
echo "String 3: $str3"
str4=$(ls -lstr | tail -1)
echo "String 4: $str4"
str5=$(echo "This is a test for $str3" | cut -d' ' -f1-2,6)
echo "String 5: $str5"
