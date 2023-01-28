#include <cstdint>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include "merge.h"

void print_array(uint8_t* array, size_t size) {
    printf("[ ");
    for (size_t i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("]\n");
}

void new_array(uint8_t* array, size_t size) {
    srand(time(NULL));
    unsigned int next = rand() % 256;

    for (size_t i = 0; i < size; ++i) {
        array[i] = next;
        next = rand() % 256;
    }
}

double time_merge_sort(size_t size) {
    clock_t start = std::clock();
    uint8_t* array = (uint8_t*)malloc(sizeof(uint8_t) * size);

    // Fills array with random numbers.
    new_array(array, size);
    merge_sort(array, sizeof(array));
    clock_t end = std::clock();

    free(array);

    return (end - start) / (double)(CLOCKS_PER_SEC / 1000);
}

int main() {
    size_t size = 100000000;
    double sort_time = time_merge_sort(size);

    printf("Time to sort %d elements: %lf\n", size, sort_time);
}
