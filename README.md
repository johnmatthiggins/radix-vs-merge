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

Radix sort has been optimized by changing the queue that was being used. I first
tried to implement radix sort with C++'s `std::queue` class but the performance was dreadful.
To fix this problem, I implemented a class called `MiniQueue` that contains a minimal queue
that sticks to using just a single buffer to store elements along with `start` and `end` values
to determine where to `pop()` and where to `push()`.
