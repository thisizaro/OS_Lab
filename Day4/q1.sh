#!/bin/bash

# Coded by Aranya Dutta - 23051490

echo "Day 4 - Question 1: Shell script to concatenate two files line by line"
echo "                                            Coded by Aranya Dutta - 23051490"
echo "For code you can visit my GitHub:        https://github.com/thisizaro/OS_Lab"
echo "-----------------------------------------------------------------------------"



if [ "$#" -ne 3 ]; then
    echo "Usage: $0 file1 file2 outputfile"
    exit 1
fi

file1=$1
file2=$2
outputfile=$3

paste -d'\n' "$file1" "$file2" > "$outputfile"