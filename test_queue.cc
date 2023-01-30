#include <cstdio>
#include "radix.h"

void show_queue(mini_queue* queue) {
    printf("--------------------------------\n");
    printf("CAPACITY: %d\n", queue->capacity);
    printf("START: %d\n", queue->start);
    printf("END: %d\n", queue->end);
    printf("EMPTY: %d\n", queue->empty);
    printf("--------------------------------\n");
}

/* int main() { */
/*     auto queue = queue_init(10); */
/*     show_queue(&queue); */

/*     push(queue, 1); */
/*     push(queue, 2); */
/*     push(queue, 3); */
/*     push(queue, 4); */

/*     show_queue(&queue); */

/*     printf("HEAD = %d\n", pop(queue)); */
/*     show_queue(&queue); */

/*     push(queue, 5); */
/*     push(queue, 6); */
/*     push(queue, 7); */
/*     push(queue, 8); */
/*     push(queue, 9); */
/*     push(queue, 10); */
/*     show_queue(&queue); */
/*     push(queue, 11); */
/*     show_queue(&queue); */
/*     push(queue, 12); */

/*     show_queue(&queue); */
/*     printf("HEAD = %d\n", pop(queue)); */
/*     show_queue(&queue); */
/* } */
