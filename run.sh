#!/usr/bin/env sh
rm radix.csv merge.csv
./main --radix >> radix.csv
./main --merge >> merge.csv
