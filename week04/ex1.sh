#!/bin/bash

gcc ex1.c -w -o ex1

for i in $(seq 1 10)
do
    ./ex1
done
