#!/bin/bash

STOP=5

echo "Running a for loop"
for ((ii=1;ii<$STOP;ii++))
do
  echo $ii
done

echo

echo "Files in the current directory"
allfiles=(*)
cfiles=(*.c)

echo $allfiles[0]
echo ${allfiles[0]}
echo ${allfiles[1]}
echo

echo "List of C files"
for cfile in ${cfiles[@]}
do
  echo "  $cfile"
done
echo "Number of C files = ${#cfiles[@]}"
echo

echo "Loop over results of a command"
cppfiles=($(find . -name "*.cpp"))
for filename in ${cppfiles[@])}
do
  echo "  $filename"
done

filetocheck=${cfiles[0]}
wordtocheck=printf
echo "Does $wordtocheck appear in $filetocheck?"
if grep -q $wordtocheck $filetocheck
then
  echo "$wordtocheck appears in $filetocheck"
else
  echo "$wordtocheck does not appear in $filetocheck"
fi
