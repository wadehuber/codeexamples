#!/bin/bash

# Declaring an array
declare -a arr1

arr2[0]="Hello"
arr2[1]="World"
arr2[2]="bash"
arr2[3]="arrays"
arr2[4]="Arizona"

arr3=(1 2 3 4 5 6)

arr4=([0]=10 [1]=20 [2]=30 [3]=40 [4]=50)

arr5=([1]=10 [3]=20 [6]=30 [9]=40 [12]=50)

for ii in {0..4}
do
    arr1[$ii]=$((ii*100))
    arr6[$ii]=$ii
done

for ii in {0..4}
do
    echo "$ii: ${arr1[$ii]} ${arr2[$ii]} ${arr3[$ii]} " \
         "${arr4[$ii]} ${arr5[$ii]} ${arr6[$ii]}"
done

echo
echo "Subscripts for arr5: ${!arr5[@]}"
echo "Values for arr5: ${arr5[@]}"

for ii in ${!arr5[@]}
do
    echo "arr5[$ii]=${arr5[$ii]}"
done

# Add values to the end of the array
echo
echo "arr3=${arr3[@]}"
arr3+=(10)
echo "arr3=${arr3[@]}"
arr3+=(100 200 300)
echo "arr3=${arr3[@]}"
