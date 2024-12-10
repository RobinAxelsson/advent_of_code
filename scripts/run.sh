#!/bin/bash
day=$1


if [[ $day == "" ]]; then
    echo "Provide a christmas date"
    exit 1
fi

# -g is with debug information
gcc -g ./src/2024/"$day".main.c ./src/2024/"$day".lib.c -o ./output/"$day" && ./output/"$day" $2 $3
