#!/bin/bash
day=$1


if [[ $day == "" ]]; then
    echo "Provide a christmas date"
    exit 1
fi

# -g is with debug information
gcc -g ./src/2024/"$day".c -o ./output/"$day" && ./output/"$day"