#!/bin/bash

# Coded by Aranya Dutta - 23051490

echo "Day 3 - Question 3: Shell script to display home directory, Bash version, host name, and current directory"
echo "                                            Coded by Aranya Dutta - 23051490"
echo "For code you can visit my GitHub:        https://github.com/thisizaro/OS_Lab"
echo "-----------------------------------------------------------------------------"

while :; do
  echo "1. Home directory"
  echo "2. Bash version"
  echo "3. Host name"
  echo "4. Current directory"
  echo "5. Exit"

  read -p "Enter your choice: " choice

  case $choice in
    1) echo "Home directory: $HOME" ;;
    2) echo "Bash version: $BASH_VERSION" ;;
    3) echo "Host name: $(hostname)" ;;
    4) echo "Current directory: $(pwd)" ;;
    5) echo "Exiting..."
       exit 0 ;;
    *) echo "Invalid choice. Try again." ;;
  esac
done