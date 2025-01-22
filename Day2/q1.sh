#!/bin/bash

# Coded by Aranya Dutta - 23051490

echo "Day 2 - Question 1: Shell program to find whether a given year is a leap year or not"
echo "                                            Coded by Aranya Dutta - 23051490"
echo "For code you can visit my GitHub:        https://github.com/thisizaro/OS_Lab"
echo "-----------------------------------------------------------------------------"

read -p "Input (year): " year

if (( ($year % 4 == 0 && $year % 100 != 0) || $year % 400 == 0 )); then
  echo "$year is a leap year"
else
  echo "$year is not a leap year"
fi