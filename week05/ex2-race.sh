#!/bin/bash

echo 0 >> ex2-race-output.txt

for i in $(seq 1 $1)
do
   prev_num=$(tail -n 1 ex2-race-output.txt)
   next_num=$(($prev_num + 1))
   
   echo $next_num >> ex2-race-output.txt
done
