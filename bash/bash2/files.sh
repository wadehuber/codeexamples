#!/bin/bash


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

filetocheck=${cfiles[0]}
wordtocheck=printf
echo "Does $wordtocheck appear in $filetocheck?"
if grep -q $wordtocheck $filetocheck
then
  echo "$wordtocheck appears in $filetocheck"
else
  echo "$wordtocheck does not appear in $filetocheck"
fi
