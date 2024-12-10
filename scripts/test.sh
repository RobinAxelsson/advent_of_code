#!/bin/bash
day=$1


if [[ $day == "" ]]; then
    echo "Provide a christmas date"
    exit 1
fi

# -g is with debug information
gcc -g ./src/testlib.c ./src/2024/"$day".lib.c ./src/2024/"$day".tests.c -o ./output/"$day".tests && ./output/"$day".tests