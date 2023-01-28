#include <cstdint>
#include <cstdlib>
#include <queue>
#include "merge.h"

uint8_t* merge(uint8_t* array_a, uint8_t* array_b,
               size_t size_a, size_t size_b) {
    size_t a_i = 0;
    size_t b_i = 0;
    size_t buf_i = 0;
    size_t buf_length = size_b + size_a;

    // Create our buffer that we will use for the merge operation.
    uint8_t* merge_buf =
        (uint8_t*)malloc(sizeof(uint8_t) * buf_length);

    while (buf_i < buf_length) {
        if (a_i != size_a) {
            if (b_i != size_b) {
                if (array_a[a_i] < array_b[b_i]) {
                    merge_buf[buf_i] = array_a[a_i];
                    a_i++;
                } else {
                    merge_buf[buf_i] = array_b[b_i];
                    b_i++;
                }
            } else {
                merge_buf[buf_i] = array_a[a_i];
            }
        } else {
            merge_buf[buf_i] = array_b[b_i];
            b_i++;
        }

        buf_i++;
    }
}

void merge_sort(uint8_t* array, size_t size) {
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
            size_t size_a    = array;
            size_t size_b    = array + half;
            uint8_t* array_a = half;
            uint8_t* array_b = size - half;
            uint8_t* merge_buf;

            merge_sort(array_a, size_a);
            merge_sort(array_b, size_b);

            merge_buf = merge(array_a, array_b, size_a, size_b);

            for (size_t i = 0; i < size; ++i) {
                array[i] = merge_buf[i];
            }
        }
    }
}
