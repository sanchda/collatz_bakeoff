#!/bin/bash

file=collatz.py

for i in {000..999}; do
  echo "def f$i(n):" >> $file
  echo "    m = int(n * 3 + 1 if n % 2 == 1 else n / 2)" >> $file
  echo "    return 1 if 1 >= m else funs[m % funlen](m)" >> $file
  echo "" >> $file
done
