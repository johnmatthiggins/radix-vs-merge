#include <cstdint>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include "merge.h"
#include "radix.h"

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
    merge_sort(array, size);
    clock_t end = std::clock();

    free(array);

    return (end - start) / (double)(CLOCKS_PER_SEC / 1000);
}

double time_radix_sort(size_t size) {
    clock_t start = std::clock();
    uint8_t* array = (uint8_t*)malloc(sizeof(uint8_t) * size);

    // Fills array with random numbers.
    new_array(array, size);
    radix_sort(array, size);
    clock_t end = std::clock();

    free(array);

    return (end - start) / (double)(CLOCKS_PER_SEC / 1000);
}

void test_sort(size_t size) {
    uint8_t* array = (uint8_t*)malloc(sizeof(uint8_t) * size);

    // Fills array with random numbers.
    new_array(array, size);
    print_array(array, size);
    radix_sort(array, size);
    print_array(array, size);

    free(array);
}

int main() {
    size_t max_size = 0x10000000;
    /* printf("N,TIME\n"); */

    /* for (size_t i = 2; i <= max_size; i *= 2) { */
    /*     double sort_time = time_radix_sort(i); */
    /*     printf("%d,%lf\n", i, sort_time); */
    /* } */
    for (size_t i = 0; i < 10; i++) {
        printf("--------------------------------------\n");
        test_sort(10);
        printf("--------------------------------------\n");
    }
}
