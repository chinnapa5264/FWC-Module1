#!/bin/bash
dir=$1
echo $dir
cd docs/
texfot pdflatex arm.tex
cd ..
cp docs/arm.pdf /sdcard/Download/$1.pdf
termux-open /sdcard/Download/$1.pdf
