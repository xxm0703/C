#!/bin/bash
a=`find $1 -mindepth 1 -not -path '*/\.*' -type f \( ! -iname "*.out" \)`
for f in $a
do
name="${f%%.*}"
gcc -pedantic-errors -std=c11 -Wall -o $name.out $f
echo "Done compilation of ${f%%*/}"
done
