#!/bin/bash

sudo chmod 777 lofsdisk

touch lofsdisk/file1.txt
touch lofsdisk/file2.txt
echo "Danil" > lofsdisk/file1.txt
echo "Andreev" > lofsdisk/file2.txt

gcc ex2.c -o ex2.out

#cp /bin/bash lofsdisk/bin/bash
#cp /bin/cat lofsdisk/bin/cat
#cp /bin/echo lofsdisk/bin/echo
#cp /bin/ls lofsdisk/bin/ls

mkdir -p lofsdisk/bin
mkdir -p lofsdisk/lib/x86_64-linux-gnu
mkdir -p lofsdisk/lib64

cp /bin/bash lofsdisk/bin/bash
cp /lib/x86_64-linux-gnu/libc.so.6 lofsdisk/lib/x86_64-linux-gnu/libc.so.6
cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64/ld-linux-x86-64.so.2
cp ex2.out lofsdisk/ex2.out


#sudo ldd /bin/bash | grep "=> /" | awk '{print $3}' | xargs -I "/lib_dir" mkdir -p lofsdisk/lib_dir
#sudo ldd /bin/cat | grep "=> /" | awk '{print $3}' | xargs -I "/lib_dir" mkdir -p lofsdisk/lib_dir
#sudo ldd /bin/echo | grep "=> /" | awk '{print $3}' | xargs -I "/lib_dir" mkdir -p lofsdisk/lib_dir
#sudo ldd /bin/ls | grep "=> /" | awk '{print $3}' | xargs -I "/lib_dir" mkdir -p lofsdisk/lib_dir
#sudo ldd ex2.out | grep "=> /" | awk '{print $3}' | xargs -I "/lib_dir" mkdir -p lofsdisk/lib_dir

#sudo ldd /bin/bash | grep "=> /" | awk '{print $3}' | xargs -I "/lib_dir" cp -v /lib_dir lofsdisk/lib_dir
#sudo ldd /bin/cat | grep "=> /" | awk '{print $3}' | xargs -I "/lib_dir" cp -v /lib_dir lofsdisk/lib_dir
#sudo ldd /bin/echo | grep "=> /" | awk '{print $3}' | xargs -I "/lib_dir" cp -v /lib_dir lofsdisk/lib_dir
#sudo ldd /bin/ls | grep "=> /" | awk '{print $3}' | xargs -I "/lib_dir" cp -v /lib_dir lofsdisk/lib_dir
#sudo ldd ex2.out | grep "=> /" | awk '{print $3}' | xargs -I "/lib_dir" cp -v /lib_dir lofsdisk/lib_dir


sudo chroot lofsdisk ./ex2.out > ex2.txt
./ex2.out >> ex2.txt
