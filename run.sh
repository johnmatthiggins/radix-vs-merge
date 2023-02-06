#!/usr/bin/env sh
rm csv/*
srun sh -c "./main --radix8 >> csv/radix.csv"
echo 'RADIX 8-BIT FINISHED'
srun sh -c "./main --merge8 >> csv/merge.csv"
echo 'MERGE 8-BIT FINISHED'
srun sh -c "./main --radix32 >> csv/radix32.csv"
echo 'RADIX 32-BIT FINISHED'
srun sh -c "./main --merge32 >> csv/merge32.csv"
echo 'MERGE 32-BIT FINISHED'
