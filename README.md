# Sorting Algorithm Comparison and Analysis

## Goals

In this experiment, I will be examining the real world scaling of
radix sort and merge sort. Both algorithms will be implemented in C++
and used on both sets of 8-bit integers and 32-bit integers. These sets of integers
will range from sizes of 2^1 to 2^30.

## Implementation Details

### Optimizations

Both radix sort and merge sort have been optimized a little bit. First, in
order to eliminate extra calls to dynamic memory allocation, I have given
merge sort a single buffer in which it will store elements before performing
a merge.
