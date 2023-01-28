#ifndef MERGE_H
#define MERGE_H

#include <cstdint>

uint8_t* merge(uint8_t* array_a, uint8_t* array_b,
               size_t size_a, size_t size_b);

void merge_sort(uint8_t* array, size_t size);

#endif
