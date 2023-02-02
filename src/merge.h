#ifndef MERGE_H
#define MERGE_H

#include <cstdlib>
#include <cstdint>

uint8_t* merge(uint8_t* array_a, uint8_t* array_b,
               size_t size_a, size_t size_b);

void merge_sort(uint8_t* array, size_t size);
void merge_sort32(uint32_t* array, size_t size);
void merge32(
        uint32_t* array_a, uint32_t* array_b,
        size_t size_a, size_t size_b, uint32_t* merge_buffer);
void merge_sort32_recursive(
        uint32_t* array, size_t size, uint32_t* merge_buffer);

#endif
