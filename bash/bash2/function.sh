#!/bin/bash

# Functions

my_func () {
    echo "This is a function"
    return
}

log_message () {
    echo "$(date | cut -d' ' -f2-4,6): $1"
    return
}

max () {
    echo "Finding max of $1 and $2"
    if [ $1 -ge $2 ]
    then
        echo "  $1 is the max"
    else
        echo "  $2 is the max"
    fi
    return
}

log_message "START"
my_func
max 3 4
max 4 3
max 4 4
my_func
log_message "END"
