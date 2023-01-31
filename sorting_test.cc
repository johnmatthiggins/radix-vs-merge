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
        printf("%x ", array[i]);
    }
    printf("]\n");
}

void sort_checker8(uint8_t* array, size_t size) {
    for (size_t i = 1; i < size; ++i) {
        if (array[i - 1] > array[i]) {
            printf("THIS ARRAY IS NOT SORTED...\n");
            printf("%x is greater than %x...\n", array[i - 1], array[i]);
            break;
        }
    }
}

void sort_checker32(uint32_t* array, size_t size) {
    for (size_t i = 1; i < size; ++i) {
        if (array[i - 1] > array[i]) {
            printf("THIS ARRAY IS NOT SORTED...\n");
            printf("%x is greater than %x...\n", array[i - 1], array[i]);
            break;
        }
    }
}

void print_array_32bit(uint32_t* array, size_t size) {
    printf("[ ");
    for (size_t i = 0; i < size; ++i) {
        printf("%#08x ", array[i]);
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

void new_array_32bit(uint32_t* array, size_t size) {
    srand(time(NULL));
    unsigned int next = rand();

    for (size_t i = 0; i < size; ++i) {
        array[i] = next;
        next = (uint32_t)rand();
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

double time_merge32_sort(size_t size) {
    clock_t start = std::clock();
    uint32_t* array = (uint32_t*)malloc(sizeof(uint32_t) * size);

    // Fills array with random numbers.
    new_array_32bit(array, size);
    merge_sort32(array, size);
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
    sort_checker8(array, size);
    clock_t end = std::clock();

    free(array);

    return (end - start) / (double)(CLOCKS_PER_SEC / 1000);
}

double time_radix32_sort(size_t size) {
    clock_t start = std::clock();
    uint32_t* array = (uint32_t*)malloc(sizeof(uint32_t) * size);

    // Fills array with random numbers.
    new_array_32bit(array, size);
    /* print_array_32bit(array, size); */
    radix_sort_32bit(array, size);
    /* print_array_32bit(array, size); */
    /* sort_checker32(array, size); */
    clock_t end = std::clock();

    free(array);

    return (end - start) / (double)(CLOCKS_PER_SEC / 1000);
}

int main(int argc, char** argv) {
    size_t max_size = 134217728;
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
        } else if (strcmp(argv[1], "--radix32") == 0) {
            printf("N,TIME\n");

            for (size_t i = 2; i <= max_size; i *= 2) {
                double sort_time = time_radix32_sort(i);
                printf("%d,%lf\n", i, sort_time);
            }
        } else if (strcmp(argv[1], "--merge32") == 0) {
            printf("N,TIME\n");

            for (size_t i = 2; i <= max_size; i *= 2) {
                double sort_time = time_merge32_sort(i);
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
