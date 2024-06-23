#!/bin/bash

# Directory to check
directory="."

# Minimum value to compare
min_value=8

# Loop through all files in the directory
for file in "$directory"/*; do
    # Get the filename without the path
    filename=$(basename "$file")
    
    # Check if the first two characters are numbers
    if [[ $filename =~ ^[0-9]{2} ]]; then
        # Extract the first two characters
        num=${filename:0:2}

        # Explicitly convert the number to an integer
        num=$((10#$num))

        # Check if the number is greater than the given value
        if (( num > min_value )); then
            # Increment the number by 1
            new_num=$((num + 1))

            #Convert the number to a string with leading zeros
            new_num=$(printf "%02d" $new_num)
            
            # Create the new filename
            new_filename="${new_num}${filename:2}"
            
            # Print the changed filename
            echo "$filename -> $new_filename"

						mv $filename $new_filename
        fi
    fi
done
