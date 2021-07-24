#! /usr/bin/bash

echo "Starting script . . ."

echo "Command line parameters:"
for var in "$@"
do
  echo "  $var"
done

echo "Environment variables:"
echo "  SHELL=$SHELL"
echo "  USER=$USER"
echo "  TERM=$TERM"
echo "  CSC220=$CSC220"
echo "  SECRET=$SECRET"

echo "End of script."