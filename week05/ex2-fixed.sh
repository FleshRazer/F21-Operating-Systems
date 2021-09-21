#!/bin/bash

touch ex2-fixed-output.txt

if ln ex2-fixed-output.txt ex2-fixed-output.lock
   then
        echo 0 >> ex2-fixed-output.txt
        rm ex2-fixed-output.lock
   fi

i=1

while [ $i -le $1 ]
do
   if ln ex2-fixed-output.txt ex2-fixed-output.lock
   then
       prev_num=$(tail -n 1 ex2-fixed-output.txt)
       next_num=$(($prev_num + 1))
       echo $next_num >> ex2-fixed-output.txt
       
       rm ex2-fixed-output.lock
       i=$(($i + 1))
   fi
done
