
static const size_t U8_VALUE_COUNT = 256;

void radix_sort(uint8_t* array_a, uint8_t* array_b,
           size_t size_a, size_t size_b) {
    std::queue** buckets =
        (std::queue**)malloc(sizeof(std::queue*) * U8_VALUE_COUNT);
}

void merge_sort(uint8_t* array, size_t size) {
}

void free_buckets(std::queue** buckets) {
    for (size_t i = 0; i <= U8_MAX; ++i) {
        free(buckets[i]);
    }

    free(buckets);
}

std::queue** make_buckets() {
    std::queue** buckets =
        (std::queue**)malloc(sizeof(std::queue*) * U8_VALUE_COUNT);

    for (size_t i = 0; i <= U8_MAX; ++i) {
        std::queue* new_queue = new std::queue();
        buckets[i] = new_queue;
    }

    return buckets;
}
