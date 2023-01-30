#ifndef RADIX_H
#define RADIX_H

#include <cstdint>
#include <cstdlib>

typedef struct {
    size_t    start;
    size_t    end;
    size_t    capacity;
    uint32_t* _buffer;
    bool      empty;
} mini_queue;

void radix_sort_8bit(uint8_t*   array, size_t size);
void radix_sort_32bit(uint32_t* array, size_t size);
mini_queue* create_queues(size_t capacity);
uint8_t slice_byte(uint32_t word, size_t index);
mini_queue queue_init(size_t size);
void push(mini_queue queue, uint32_t element);
uint32_t pop(mini_queue queue);
void resize_queue(mini_queue queue, size_t size);

#endif
