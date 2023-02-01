#ifndef RADIX_H
#define RADIX_H

#include <cstdint>
#include <cstdlib>

/* typedef struct { */
/*     size_t    start; */
/*     size_t    end; */
/*     size_t    capacity; */
/*     uint32_t* _buffer; */
/*     bool      empty; */
/* } mini_queue; */

static const size_t DEFAULT_QUEUE_CAPACITY = 16;

class mini_queue {
private:
    size_t _start;
    size_t _end;
    size_t _capacity;
    uint32_t* _buffer;

    void _resize_queue(size_t size);

public:
    bool empty;

    mini_queue(size_t capacity = DEFAULT_QUEUE_CAPACITY);
    ~mini_queue();

    void push(uint32_t element);
    uint32_t pop();
    size_t end();
    size_t start();
};

void radix_sort_8bit(uint8_t*   array, size_t size);
void radix_sort_32bit(uint32_t* array, size_t size);
uint8_t slice_byte(uint32_t word, size_t index);

#endif
