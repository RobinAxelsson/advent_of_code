#!/bin/bash
day=$1

if [[ $day == "" ]]; then
    echo "Provide a christmas date"
    exit 1
fi

gcc ./src/2024/"$1".c -o ./output/"$1" && ./output/"$1"