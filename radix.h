#ifndef RADIX_H
#define RADIX_H

#include <cstdint>
#include <cstdlib>

static const size_t DEFAULT_QUEUE_CAPACITY = 16;

template <class T>
class MiniQueue {
private:
    size_t  _start;
    size_t  _end;
    size_t  _capacity;
    T*      _buffer;
    bool    _empty;

    void _resize_queue(size_t size);

public:
    MiniQueue<T>(size_t capacity = DEFAULT_QUEUE_CAPACITY);
    ~MiniQueue();

    bool empty();
    void push(T element);
    T pop();
    size_t end();
    size_t start();
};

void radix_sort_8bit(uint8_t*   array, size_t size);
void radix_sort_32bit(uint32_t* array, size_t size);
uint8_t slice_byte(uint32_t word, size_t index);

#endif
