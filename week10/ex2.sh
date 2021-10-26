#!/bin/bash

mkdir week01
touch week01/file.txt
echo "Lorem Ipsum" > week01/file.txt

mkdir week10
link week01/file.txt week10/_ex2.txt

inode=$( ls -i week01/file.txt | tr ' ' '\n' | head -n 1 )
echo "find" > ex2.txt
find . -inum $inode >> ex2.txt

echo "find -exec rm" >> ex2.txt
find . -inum $inode -exec rm -v {} \; >> ex2.txt