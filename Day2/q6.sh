#!/bin/bash

# Coded by Aranya Dutta - 23051490

echo "Day 2 - Question 6: Shell script to move files and directories from XYZ directory"
echo "                                            Coded by Aranya Dutta - 23051490"
echo "For code you can visit my GitHub:        https://github.com/thisizaro/OS_Lab"
echo "-----------------------------------------------------------------------------"

# Create subdirectories if they don't exist
mkdir -p MyFile MyDir

# Move files to MyFile
for file in XYZ/*; do
  if [ -f "$file" ]; then
    mv "$file" MyFile/
  fi
done
# Print full location of moved files
echo "Files have been moved to MyFile directory"
for file in MyFile/*; do
  echo "Moved file: $(realpath "$file")"
done


# Move directories to MyDir
for dir in XYZ/*/; do
  if [ -d "$dir" ]; then
    mv "$dir" MyDir/
  fi
done

# Print full location of moved directories
echo "Directories have been moved to MyDir directory"
for dir in MyDir/*; do
  echo "Moved directory: $(realpath "$dir")"
done