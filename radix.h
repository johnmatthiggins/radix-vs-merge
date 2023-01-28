#ifndef RADIX_H
#define RADIX_H

#include <cstdint>
#include <queue>
#include <cstdlib>

void radix_sort(uint8_t* array, size_t size);
void free_buckets(std::queue<uint8_t>** buckets);
std::queue<uint8_t>** make_buckets();

#endif
