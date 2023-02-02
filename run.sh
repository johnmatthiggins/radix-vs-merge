#!/usr/bin/env sh
rm csv/*
./main --radix8 >> csv/radix.csv
echo 'RADIX 8-BIT FINISHED'
./main --merge8 >> csv/merge.csv
echo 'MERGE 8-BIT FINISHED'
./main --radix32 >> csv/radix32.csv
echo 'RADIX 32-BIT FINISHED'
./main --merge32 >> csv/merge32.csv
echo 'MERGE 32-BIT FINISHED'
