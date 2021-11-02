#!/bin/bash

dd if=/dev/zero of=lofs.img bs=1M count=50
sudo losetup loop99 lofs.img
mkfs.ext4 ./lofs.img

mkdir lofsdisk

sudo mount -o loop /dev/loop99 ./lofsdisk/
