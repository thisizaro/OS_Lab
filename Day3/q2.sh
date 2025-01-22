#!/bin/bash

# Coded by Aranya Dutta - 23051490

echo "Day 3 - Question 2: Shell script to verify whether the given string is a palindrome or not"
echo "                                            Coded by Aranya Dutta - 23051490"
echo "For code you can visit my GitHub:        https://github.com/thisizaro/OS_Lab"
echo "-----------------------------------------------------------------------------"

read -p "Enter a string: " str

len=${#str}
reverse=""

for (( i=$(($len - 1)); i>=0; i-- )); do
  reverse="$reverse${str:$i:1}"
done

if [ "$str" = "$reverse" ]; then
  echo "String is palindrome"
else
  echo "String is not palindrome"
fi