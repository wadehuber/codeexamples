#!/bin/bash

echo "Bases"
echo "       binary: $((2#11111111))"
echo "        octal: $((0377))"
echo "      decimal: $((255))"
echo "  hexidecimal: $((0xff))"

echo
echo "Operations"
echo "  10 / 2 = $((10 / 2))"
echo "  10 / 3 = $((10 / 3))"
echo "  17 % 5 = $((17 % 5))"

echo
num=10
echo "num=$num"
num+=3
echo "num+=3 : num=$num"

echo
num=10
echo "num=$num"
((num+=3))
echo "((num+=3)) : num=$num"


