#!/bin/bash

# Coded by Aranya Dutta - 23051490

echo "Day 3 - Question 1: Shell script to reverse a given integer"
echo "                                            Coded by Aranya Dutta - 23051490"
echo "For code you can visit my GitHub:        https://github.com/thisizaro/OS_Lab"
echo "-----------------------------------------------------------------------------"

read -p "Enter a number: " num

reverse=0
temp=$num

while [ $temp -gt 0 ]; do
  remainder=$((temp % 10))
  reverse=$((reverse * 10 + remainder))
  temp=$((temp / 10))
done

echo "Reverse number: $reverse"