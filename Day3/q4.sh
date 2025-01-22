#!/bin/bash

# Coded by Aranya Dutta - 23051490

echo "Day 3 - Question 4: Shell program to perform operations on command line arguments"
echo "                                            Coded by Aranya Dutta - 23051490"
echo "For code you can visit my GitHub:        https://github.com/thisizaro/OS_Lab"
echo "-----------------------------------------------------------------------------"

if [ $# -gt 8 ]; then
  echo "Error: Maximum 8 arguments allowed."
  exit 1
fi

result=$1

for (( i=2; i<=$#; i++ )); do
  if [ $((result % ${!i})) -eq 0 ]; then
    result=$((result / ${!i}))
  elif [ $((result % ${!i})) -ne 0 ] && [ $(( ${!i} % 5 )) -eq 0 ]; then
    result=$((result * ${!i}))
  elif [ $result -gt ${!i} ]; then
    result=$((result - ${!i}))
  else
    result=$((result + ${!i}))
  fi
done

echo "Result: $result"