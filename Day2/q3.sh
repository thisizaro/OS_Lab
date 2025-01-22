#!/bin/bash

# Coded by Aranya Dutta - 23051490

echo "Day 2 - Question 3: Shell program to display the prime numbers between 1 and hundred"
echo "                                            Coded by Aranya Dutta - 23051490"
echo "For code you can visit my GitHub:        https://github.com/thisizaro/OS_Lab"
echo "-----------------------------------------------------------------------------"

for ((i=2; i<=100; i++)); do
  is_prime=1

  for ((j=2; j<i; j++)); do
    if [ $((i % j)) -eq 0 ]; then
      is_prime=0
      break
    fi
  done

  if [ $is_prime -eq 1 ]; then
    echo -n "$i "
  fi
done

echo ""