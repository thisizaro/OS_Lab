#!/bin/bash

# Coded by Aranya Dutta - 23051490

echo "Day 1 - Question 3: Shell script to extract data from the date command"
echo "                                       Coded by Aranya Dutta - 23051490"

date_str=$(date +%d/%b/%Y/%H.%M)

echo "Original Date: $(date)"
echo "Formatted Date: $date_str"