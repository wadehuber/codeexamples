#!/bin/bash

# Create a new directory with a README file inside

if [ $# -eq 0 ]
then
  echo "No directory name specified."
else
  mkdir $1
  cd $1
  cat > README.TXT << EOL
This directory was created automatically.
Use it wisely!
EOL

fi
