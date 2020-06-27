#!/bin/bash

# Create a new directory with a README file inside

if [ $# -eq 0 ]
then
    echo "No directory name specified"
    exit 1
else
    mkdir $1
    cd $1
    cat > README.md << EOF
# $1
This directory & README.md was created automatically.
Use it wisely.
EOF
fi
