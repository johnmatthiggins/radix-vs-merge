#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include "radix.h"

static const size_t U8_VALUE_COUNT = 256;
static const size_t BYTES_IN_INT32 = 4;

void radix_sort_32bit(uint32_t* array, size_t size) {
    // Create 256 queues with a minimum capacity of 8 elements.
    mini_queue* queues = new mini_queue[256];
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
            if (!queues[queue_index].empty) {
                array[array_index] = queues[queue_index].pop();
                array_index++;
            } else {
                queue_index++;
            }
        }
    }

    delete [] queues;
}

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

uint8_t slice_byte(uint32_t word, size_t index) {
    size_t adj_index = index % 4;

    // shift the eight ones into the correct position.
    uint32_t mask = 0xFFUL << (adj_index * 8);
    uint8_t bits = (uint8_t)((mask & word) >> (adj_index * 8));

    return bits;
}

mini_queue::mini_queue(size_t capacity) {
    uint32_t* buffer = (uint32_t*)malloc(sizeof(uint32_t) * capacity);

    this->_start    = 0;
    this->_end      = 0;
    this->_capacity = capacity;
    this->_buffer   = buffer;
    this->empty     = true;
}

mini_queue::~mini_queue() {
    free(this->_buffer);
}

void mini_queue::push(uint32_t element) {
    size_t new_end;
    size_t new_start;

    if (this->empty) {
        new_end = (this->_end + 1) % this->_capacity;
        this->_buffer[this->_start] = element;
        this->empty                = false;
        this->_end = new_end;
    } else {
        // if it's not empty and the start and end match, that means
        // it is full.
        if (this->_start == this->_end) {
            // Multiply by 2 because we want to avoid doing this often.
            this->_resize_queue(this->_capacity << 1);
        }

        new_end = (this->_end + 1) % this->_capacity;
        this->_buffer[this->_end] = element;
        this->_end = new_end;
    }
}

uint32_t mini_queue::pop() {
    // set the new end...
    size_t new_start        = (this->_start + 1) % this->_capacity;

    // Please don't pop when it's empty. This will result in
    // undefined behavior.
    uint32_t popped_element = this->_buffer[this->_start];
    this->_start             = new_start;

    if (new_start == this->_end) {
        this->empty = true;
    }

    return popped_element;
}

void mini_queue::_resize_queue(size_t size) {
    size_t i_queue       = this->_start;
    size_t i_buffer      = 0;
    uint32_t* new_buffer = (uint32_t*)malloc(sizeof(uint32_t) * size);

    do {
        new_buffer[i_buffer] = this->_buffer[i_queue];

        // Increment but make sure we never go past capacity.
        i_queue = (i_queue + 1) % this->_capacity;
        i_buffer++;
    } while (i_queue != this->_end);

    // Realign start and end.
    this->_start   = 0;
    this->_end     = i_buffer;

    free(this->_buffer);

    this->_buffer   = new_buffer;
    this->_capacity = size;
}
