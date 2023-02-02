#ifndef RADIX_H
#define RADIX_H

#include <cstdint>
#include <cstdlib>

void radix_sort_8bit(uint8_t*   array, size_t size);
void radix_sort_32bit(uint32_t* array, size_t size);
uint8_t slice_byte(uint32_t word, size_t index);

#endif
