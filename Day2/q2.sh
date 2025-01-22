#!/bin/bash

# Coded by Aranya Dutta - 23051490

echo "Day 2 - Question 2: Shell program to find greatest among three numbers"
echo "                                            Coded by Aranya Dutta - 23051490"
echo "For code you can visit my GitHub:        https://github.com/thisizaro/OS_Lab"
echo "-----------------------------------------------------------------------------"

if [ $# -ne 3 ]; then
  echo "Usage: $0 number1 number2 number3"
  exit 1
fi

greatest=$1

if [ $2 -gt $greatest ]; then
  greatest=$2
fi

if [ $3 -gt $greatest ]; then
  greatest=$3
fi

echo "$greatest is greatest"