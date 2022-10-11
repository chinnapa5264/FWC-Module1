#!/bin/bash
dir=$1
echo $dir
cp docs/arm.pdf /sdcard/Download/$1.pdf
termux-open /sdcard/Download/$1.pdf
