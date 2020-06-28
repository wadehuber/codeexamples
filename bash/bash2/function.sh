#!/bin/bash

#functions

my_func () {
    echo "This is a function"
    return
}

log_message () {
    echo "$(date): $1"
    return
}

max () {
    echo "Finding max of $1 and $2: "
    if [ $1 -ge $2 ]
    then   
        echo "  $1 is the max"
    else   
        echo "  $2 is the max"
    fi   
return
}

my_func

log_message "This is a test"

max 3 4
max 4 3
max 4 4

log_message "Goodbye"
