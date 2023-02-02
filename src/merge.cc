#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include "merge.h"

void merge(uint8_t* array_a, uint8_t* array_b,
                  size_t size_a, size_t size_b, uint8_t* merge_buffer) {
    size_t a_i = 0;
    size_t b_i = 0;
    size_t buffer_i = 0;
    size_t buffer_length = size_b + size_a;

    while (buffer_i < buffer_length) {
        if (a_i != size_a) {
            if (b_i != size_b) {
                if (array_a[a_i] < array_b[b_i]) {
                    merge_buffer[buffer_i] = array_a[a_i];
                    a_i++;
                } else {
                    merge_buffer[buffer_i] = array_b[b_i];
                    b_i++;
                }
            } else {
                merge_buffer[buffer_i] = array_a[a_i];
                a_i++;
            }
        } else {
            merge_buffer[buffer_i] = array_b[b_i];
            b_i++;
        }

        buffer_i++;
    }
}

void merge_sort(uint8_t* array, size_t size) {
    uint8_t* buffer = (uint8_t*)malloc(sizeof(uint8_t) * size);

    merge_sort8_recursive(array, size, buffer);

    free(buffer);
}

void merge_sort8_recursive(
        uint8_t* array, size_t size, uint8_t* merge_buffer) {
    uint8_t tmp;

    if (size > 1) {
        if (size == 2) {
            if (array[0] > array[1]) {
                tmp      = array[0];
                array[0] = array[1];
                array[1] = tmp;
            }
        } else {
            size_t half      = size / 2;
            uint8_t* array_a = array;
            uint8_t* array_b = array + half;
            size_t size_a    = half;
            size_t size_b    = size - half;

            merge_sort8_recursive(array_a, size_a, merge_buffer);
            merge_sort8_recursive(array_b, size_b, merge_buffer + half);

            merge(array_a, array_b, size_a, size_b, merge_buffer);

            for (size_t i = 0; i < size; ++i) {
                array[i] = merge_buffer[i];
            }
        }
    }
}

void merge32(uint32_t* array_a, uint32_t* array_b,
                  size_t size_a, size_t size_b, uint32_t* merge_buffer) {
    size_t a_i = 0;
    size_t b_i = 0;
    size_t buffer_i = 0;
    size_t buffer_length = size_b + size_a;

    while (buffer_i < buffer_length) {
        if (a_i != size_a) {
            if (b_i != size_b) {
                if (array_a[a_i] < array_b[b_i]) {
                    merge_buffer[buffer_i] = array_a[a_i];
                    a_i++;
                } else {
                    merge_buffer[buffer_i] = array_b[b_i];
                    b_i++;
                }
            } else {
                merge_buffer[buffer_i] = array_a[a_i];
                a_i++;
            }
        } else {
            merge_buffer[buffer_i] = array_b[b_i];
            b_i++;
        }

        buffer_i++;
    }
}

void merge_sort32(uint32_t* array, size_t size) {
    uint32_t* buffer = (uint32_t*)malloc(sizeof(uint32_t) * size);

    merge_sort32_recursive(array, size, buffer);

    free(buffer);
}

void merge_sort32_recursive(
        uint32_t* array, size_t size, uint32_t* merge_buffer) {
    uint32_t tmp;

    if (size > 1) {
        if (size == 2) {
            if (array[0] > array[1]) {
                tmp      = array[0];
                array[0] = array[1];
                array[1] = tmp;
            }
        } else {
            size_t half      = size / 2;
            uint32_t* array_a = array;
            uint32_t* array_b = array + half;
            size_t size_a    = half;
            size_t size_b    = size - half;

            merge_sort32_recursive(array_a, size_a, merge_buffer);
            merge_sort32_recursive(array_b, size_b, merge_buffer + half);

            merge32(array_a, array_b, size_a, size_b, merge_buffer);

            for (size_t i = 0; i < size; ++i) {
                array[i] = merge_buffer[i];
            }
        }
    }
}
