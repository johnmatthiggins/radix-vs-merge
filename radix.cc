#include <cstdint>
#include <queue>
#include <cstdlib>
#include "radix.h"

static const size_t U8_VALUE_COUNT = 256;

void radix_sort(uint8_t* array, size_t size) {
    std::queue<uint8_t>** buckets = make_buckets();
    
    for (size_t i = 0; i < size; ++i) {
        uint8_t next = array[i];
        buckets[(size_t)next]->push(next);
    }

    size_t bucket_index = 0;
    size_t array_index  = 0;

    while (bucket_index < U8_VALUE_COUNT) {
        // if not empty.
        if (!buckets[bucket_index]->empty()) {
            array[array_index] = buckets[bucket_index]->front();
            buckets[bucket_index]->pop();
            array_index++;
        } else {
            bucket_index++;
        }
    }

    free_buckets(buckets);
}

void free_buckets(std::queue<uint8_t>** buckets) {
    for (size_t i = 0; i < U8_VALUE_COUNT; ++i) {
        delete buckets[i];
    }

    free(buckets);
}

std::queue<uint8_t>** make_buckets() {
    auto buckets =
        (std::queue<uint8_t>**)malloc(sizeof(std::queue<uint8_t>*) * U8_VALUE_COUNT);

    for (size_t i = 0; i < U8_VALUE_COUNT; ++i) {
        auto new_queue = new std::queue<uint8_t>;
        buckets[i] = new_queue;
    }

    return buckets;
}
