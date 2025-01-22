#!/bin/bash

# Coded by Aranya Dutta - 23051490

echo "Day 1 - Question 2: Shell program to convert distance into meter, cm, and km"
echo "                                       Coded by Aranya Dutta - 23051490"

read -p "Enter distance in cm: " distance

# Calculate distances
meter=$((distance / 100))
km=$((meter / 1000))
meter=$((meter % 1000))
cm=$((distance % 100))

# Display results
echo "Distance in cm: $distance"
echo "Distance in meter: $meter"
echo "Distance in km: $km"
echo "Final Result: $km km $meter m $cm cm"