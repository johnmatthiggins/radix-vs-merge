#include <cstdint>
#include <queue>
#include <cstdlib>
#include "radix.h"

static const size_t U8_VALUE_COUNT = 256;

void radix_sort_8bit(uint8_t* array, size_t size) {
    size_t* counts = (size_t*)calloc(U8_VALUE_COUNT, sizeof(size_t));
    size_t count_index = 0;
    size_t array_index = 0;
    
    for (size_t i = 0; i < size; ++i) {
        uint8_t next = array[i];
        counts[(size_t)next] += 1;
    }

    while (count_index < U8_VALUE_COUNT) {
        // if not empty.
        if (counts[count_index] != 0) {
            array[array_index] = count_index;
            counts[count_index]--;
            array_index++;
        } else {
            count_index++;
        }
    }

    free(counts);
}
