#!/bin/bash

# Coded by Aranya Dutta - 23051490

echo "Day 1 - Question 1: Shell program to add two numbers using command line arguments"
echo "                                       Coded by Aranya Dutta - 23051490"

if [ $# -ne 2 ]; then
  echo "Usage: $0 number1 number2"
  exit 1
fi

# show numbers 

echo "Number 1: $1"
echo "Number 2: $2"

# add and print the sum
sum=$(($1 + $2))

echo "Sum is: $sum"