#!/bin/bash

read -p "Enter start: " start
read -p "Enter end: " end

echo "Prime numbers between $start and $end are:"

for (( num=start; num<=end; num++ ))
do
    if (( num < 2 )); then
        continue
    fi

    isPrime=1   # assume prime

    for (( i=2; i*i<=num; i++ ))
    do
        if (( num % i == 0 )); then
            isPrime=0
            break
        fi
    done

    if (( isPrime == 1 )); then
        echo "$num"
    fi
done
