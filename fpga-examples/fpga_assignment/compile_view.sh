#!/bin/bash
dir=$1
echo $dir
cd docs/
texfot pdflatex fpga.tex
cd ..
cp docs/fpga.pdf /sdcard/Download/$1.pdf
termux-open /sdcard/Download/$1.pdf
