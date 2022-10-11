#!/bin/bash
ip="192.168.141.157"
uname="ubuntu"
path="/home/$uname/arm"
cd $1/GCC_Project
make
cd ../../
scp $1/GCC_Project/output/bin/$1.bin $uname@$ip:$path
