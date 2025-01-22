#!/bin/bash

# Coded by Aranya Dutta - 23051490

echo "Day 2 - Question 3: Shell program to display the prime numbers between 1 and hundred"
echo "                                            Coded by Aranya Dutta - 23051490"
echo "For code you can visit my GitHub:        https://github.com/thisizaro/OS_Lab"
echo "-----------------------------------------------------------------------------"


# Step 1: Capture the outputs of `ps -ef` and `ps -ux` commands
ps_ef_output=$(ps -ef)    # Full details about all processes
ps_ux_output=$(ps -ux)    # User-oriented details about all processes

# Step 2: Save the output of both commands into a file named q4_data.txt
output_file="q4_data.txt"
echo "Output of 'ps -ef':" > "$output_file"
echo "$ps_ef_output" >> "$output_file"
echo "" >> "$output_file"
echo "Output of 'ps -ux':" >> "$output_file"
echo "$ps_ux_output" >> "$output_file"

# Notify the user that data has been saved
echo "The outputs of 'ps -ef' and 'ps -ux' have been saved in $output_file."

# Step 3: Filter processes with PPID=2 from `ps -ef` output
# The third column in `ps -ef` is the PPID (Parent Process ID)
process_ids=""
while IFS= read -r line; do
    # Use awk to extract lines where the PPID column ($3) is 2
    ppid=$(echo "$line" | awk '{print $3}')
    if [ "$ppid" -eq 2 ] 2>/dev/null; then
        # Extract the PID (Process ID, column $2)
        pid=$(echo "$line" | awk '{print $2}')
        process_ids="$process_ids $pid"
    fi
done <<< "$(echo "$ps_ef_output" | tail -n +2)"  # Skip the header row

# Step 4: Display details of matching processes using `ps -ux` output
# Use a loop to match PIDs in `ps -ux` output and display their details
echo "Details of processes with Parent Process ID (PPID) = 2:"
echo "$ps_ux_output" | head -n 1  # Print the header row
for pid in $process_ids; do
    echo "$ps_ux_output" | grep " $pid "
done
