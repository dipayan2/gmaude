#!/bin/bash

# Check if the number of arguments is 2
if [ "$#" -ne 1 ]; then
  echo "Usage: $0 <number_of_times>"
  exit 1
fi

# Get the number of times to run the command
n=$1

# Get the command to run
# command=$2

# Validate if n is a positive integer
if ! [[ "$n" =~ ^[0-9]+$ ]]; then
  echo "Error: The first argument must be a positive integer."
  exit 1
fi

# Execute the command n times
for (( i=0; i<n; i++ ))
do
    ../MaudeRuntime/maude.linux64 ../../PQC-in-Maude/bike/bike-test.maude
done
