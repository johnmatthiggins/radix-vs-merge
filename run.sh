#!/usr/bin/env sh
rm radix.csv merge.csv
./main --radix8 >> radix.csv
./main --merge8 >> merge.csv
