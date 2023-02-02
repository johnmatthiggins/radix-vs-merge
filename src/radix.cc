#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include "radix.h"

static const size_t U8_VALUE_COUNT = 256;
static const size_t BYTES_IN_INT32 = 4;

void radix_sort_32bit(uint32_t* array, size_t size) {
    // Create 256 queues with a minimum capacity of 8 elements.
    std::queue<uint32_t>* queues = new std::queue<uint32_t>[256];
    size_t queue_index;
    size_t array_index;
    
    for (size_t i = 0; i < BYTES_IN_INT32; ++i) {
        queue_index = 0;
        array_index = 0;

        for (size_t j = 0; j < size; ++j) {
            size_t next = (size_t)slice_byte(array[j], i);
            queues[next].push(array[j]);
        }

        while (queue_index < U8_VALUE_COUNT) {
            // if not empty.
            if (!queues[queue_index].empty()) {
                array[array_index] = queues[queue_index].front();
                queues[queue_index].pop();
                array_index++;
            } else {
                queue_index++;
            }
        }
    }

    delete [] queues;
}

void radix_sort_8bit(uint8_t* array, size_t size) {
    // Create 256 queues with a minimum capacity of 8 elements.
    std::queue<uint8_t>* queues = new std::queue<uint8_t>[256];
    size_t queue_index = 0;
    size_t array_index = 0;
    
    for (size_t j = 0; j < size; ++j) {
        queues[array[j]].push(array[j]);
    }

    while (queue_index < U8_VALUE_COUNT) {
        // if not empty.
        if (!queues[queue_index].empty()) {
            array[array_index] = queues[queue_index].front();
            queues[queue_index].pop();
            array_index++;
        } else {
            queue_index++;
        }
    }

    delete [] queues;
}

uint8_t slice_byte(uint32_t word, size_t index) {
    size_t adj_index = index % 4;

    // shift the eight ones into the correct position.
    uint32_t mask = 0xFFUL << (adj_index * 8);
    uint8_t bits = (uint8_t)((mask & word) >> (adj_index * 8));

    return bits;
}

