#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include "radix.h"

static const size_t U8_VALUE_COUNT = 256;
static const size_t BYTES_IN_INT32 = 4;

void radix_sort_32bit(uint32_t* array, size_t size) {
    mini_queue* queues = create_queues(8);
    size_t queue_index = 0;
    size_t array_index = 0;
    
    for (size_t i = 0; i < sizeof(uint32_t); ++i) {
        for (size_t j = 0; j < size; ++j) {
            size_t next = (size_t)slice_byte(array[j], i);
            push(queues[next], array[j]);
        }

        while (queue_index < U8_VALUE_COUNT) {
            // if not empty.
            if (!queues[queue_index].empty) {
                array[array_index] = pop(queues[queue_index]);
                array_index++;
            } else {
                queue_index++;
            }
        }
    }

    for (size_t i = 0; i < 256; ++i) {
        free(queues[i]._buffer);
    }

    free(queues);
}

mini_queue* create_queues(size_t capacity) {
    mini_queue* queues =
        (mini_queue*)calloc(256, sizeof(mini_queue));
    mini_queue queue;

    for (size_t i = 0; i < 256; ++i) {
        mini_queue queue = queue_init(capacity);
        queues[i] = queue;
    }

    return queues;
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

mini_queue queue_init(size_t size) {
    uint32_t* buffer = (uint32_t*)malloc(sizeof(uint32_t) * size);

    mini_queue queue = mini_queue {
        .start    = 0,
        .end      = 0,
        .capacity = size,
        ._buffer  = buffer,
        .empty    = true,
    };

    return queue;
}

void push(mini_queue& queue, uint32_t element) {
    size_t new_end;
    size_t new_start;

    if (queue.empty) {
        new_end = (queue.end + 1) % queue.capacity;
        queue._buffer[queue.start] = element;
        queue.empty                = false;
        queue.end = new_end;
    } else {
        // if it's not empty and the start and end match, that means
        // it is full.
        if (queue.start == queue.end) {
            // Multiply by 2 because we want to avoid doing this often.
            resize_queue(queue, queue.capacity << 1);
        }

        new_end = (queue.end + 1) % queue.capacity;
        queue._buffer[queue.end] = element;
        queue.end = new_end;
    }
}

uint32_t pop(mini_queue& queue) {
    // set the new end...
    size_t new_start        = (queue.start + 1) % queue.capacity;

    // Please don't pop when it's empty. This will result in
    // undefined behavior.
    uint32_t popped_element = queue._buffer[queue.start];
    queue.start             = new_start;

    if (new_start == queue.end) {
        queue.empty = true;
    }

    return popped_element;
}

void resize_queue(mini_queue& queue, size_t size) {
    size_t i_queue       = queue.start;
    size_t i_buffer      = 0;
    uint32_t* new_buffer = (uint32_t*)malloc(sizeof(uint32_t) * size);

    do {
        new_buffer[i_buffer] = queue._buffer[i_queue];

        // Increment but make sure we never go past capacity.
        i_queue = (i_queue + 1) % queue.capacity;
        i_buffer++;
    } while (i_queue != queue.end);

    // Realign start and end.
    queue.start   = 0;
    queue.end     = i_buffer;

    free(queue._buffer);
    queue._buffer  = new_buffer;
    queue.capacity = size;
}
