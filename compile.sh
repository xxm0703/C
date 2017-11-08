#!/bin/bash
a=`find $1 -mindepth 1 -not -path '*/\.*' -type f \( -iname "*.c" \)`
for f in $a
do
name="${f%%.*}"
gcc -pedantic-errors -std=c11 -Wall -o $name.out $f -lm
echo "Done compilation of ${name}"
done
