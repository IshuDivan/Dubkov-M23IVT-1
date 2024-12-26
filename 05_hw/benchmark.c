#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

void benchmark_push(Stack* stack, int num_operations) {
    clock_t start = clock();

    for (int i = 0; i < num_operations; i++) {
        push(stack, i);
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Pushed %d times in %f seconds\n", num_operations, time_spent);
}

void benchmark_pop(Stack* stack, int num_operations) {
    clock_t start = clock();

    for (int i = 0; i < num_operations; i++) {
        pop(stack);
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Pushed %d times in %f seconds\n", num_operations, time_spent);
}

int main() {
    Stack stack;
    initStack(&stack);
    int iterations = 1000000;

    printf("Benchmarking push:\n");
    for (int i = 1000; i <= iterations; i *= 10) {
        benchmark_push(&stack, i);
        
        while (!isEmpty(&stack)) {
            pop(&stack);
        }
    }

    for (int i = 0; i < iterations; i++) {
        push(&stack, i);
    }
    printf("\nBenchmarking pop:\n");

    for (int i = 1000; i <= iterations; i *= 10) {
        benchmark_pop(&stack, i);
        for (int i = 0; i < iterations; i++) {
            push(&stack, i);
        }
    }
    destroyStack(&stack);
    return 0;
}
