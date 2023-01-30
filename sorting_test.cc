#include <cstdint>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cstring>
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
    radix_sort_8bit(array, size);
    clock_t end = std::clock();

    free(array);

    return (end - start) / (double)(CLOCKS_PER_SEC / 1000);
}

int main(int argc, char** argv) {
    size_t max_size = 0x1000000;
    int exit_code = 0;
    
    if (argc > 1) {
        if (strcmp(argv[1], "--radix8") == 0) {
            printf("N,TIME\n");

            for (size_t i = 2; i <= max_size; i *= 2) {
                double sort_time = time_radix_sort(i);
                printf("%d,%lf\n", i, sort_time);
            }
        } else if (strcmp(argv[1], "--merge8") == 0) {
            printf("N,TIME\n");

            for (size_t i = 2; i <= max_size; i *= 2) {
                double sort_time = time_merge_sort(i);
                printf("%d,%lf\n", i, sort_time);
            }
        } else {
            exit_code = 1;
        }
    } else {
        exit_code = 1;
    }

    return exit_code;
}
