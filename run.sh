#!/usr/bin/env sh
rm radix.csv merge.csv merge32.csv radix32.csv
./main --radix8 >> radix.csv
echo 'RADIX 8-BIT FINISHED'
./main --merge8 >> merge.csv
echo 'MERGE 8-BIT FINISHED'
./main --radix32 >> radix32.csv
echo 'RADIX 32-BIT FINISHED'
./main --merge32 >> merge32.csv
echo 'MERGE 32-BIT FINISHED'
