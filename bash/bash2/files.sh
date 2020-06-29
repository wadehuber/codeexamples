#!/bin/bash

echo "Files in the current directory"
allfiles=(*)
cfiles=(*.c)

echo "allfiles[0] = $allfiles"
echo "{allfiles[0]} = ${allfiles[0]}"
echo "{allfiles[1]} = ${allfiles[1]}"
echo "{allfiles[@]} = ${allfiles[@]}"

echo
echo "List of C files:"
for cfile in ${cfiles[@]}
do
    echo "  $cfile"
done
echo "Number of C files = ${#cfiles[@]}"

echo
filetocheck=${cfiles[0]}
word=printf
echo "Does $word appear in $filetocheck?"
if grep -q $word $filetocheck
then
    echo "$word appears in $filetocheck"
else
    echo "$word does not appear in $filetocheck"
fi

word=println
echo "Does $word appear in $filetocheck?"
if grep -q $word $filetocheck
then
    echo "$word appears in $filetocheck"
else
    echo "$word does not appear in $filetocheck"
fi

