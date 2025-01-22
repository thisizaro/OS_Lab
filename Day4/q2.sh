#!/bin/bash

# Coded by Aranya Dutta - 23051490

echo "Day 4 - Question 2: Shell script to store files in directories and show the size of the files."
echo "                                            Coded by Aranya Dutta - 23051490"
echo "For code you can visit my GitHub:        https://github.com/thisizaro/OS_Lab"
echo "-----------------------------------------------------------------------------"

if [ "$#" -ne 4 ]; then
    echo "Usage: $0 filename1 filename2 filename3 filename4"
    exit 1
fi

# Store the filenames from the command line arguments in an array files.
for i in {1..4}; do
    files[$i-1]="${!i}"
done

# Function to take user input and write to a file with the given name
write_to_file() {
    file=$1
    echo "Enter text for $file:"
    read text
    echo "$text" > "$file"
}

# Take user input for each file in the array and write to it
for file in "${files[@]}"; do
    write_to_file "$file"
done

# Wait for user input before moving the files to new directories
echo "Press Enter to move the files to their respective directories..."
read

# Create directories dir1 and dir2
mkdir -p dir1 dir2

# Move the first 2 files to dir1 and the next 2 files to dir2
mv "${files[@]:0:2}" dir1
mv "${files[@]:2:2}" dir2

# Print the size of all four files in bytes with their names in the dir1 and dir2
echo "Sizes of files in dir1 and dir2:"
for dir in dir1 dir2; do
    for file in "$dir"/*; do
        if [ -f "$file" ]; then
            size=$(stat -c%s "$file")
            echo "Size of $file: $size bytes"
        fi
    done
done
