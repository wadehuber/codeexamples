#!/bin/bash

# No space around = in an assignment
greeting="Hello"
person="World"

if [ $# -ne 0 ]
then
    person=$1
fi

if [ $person = "Wade" ]
then
    echo "$greeting, professor"
else
    echo "$greeting, $person"
fi
