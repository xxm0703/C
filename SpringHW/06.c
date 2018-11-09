#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    stack_t st = init();
    push(&st, 8);
    push(&st, 17);
    push(&st, 9);
    printf("%d\n", pop(&st));
    printf("%d\n", pop(&st));
    push(&st, 41);
    printf("%d\n", pop(&st));
    return 0;
}

int pop(stack_t *stack) {
    int tmp = stack->array[--stack->capacity];
    stack->array = realloc(stack->array, stack->capacity * sizeof(int));
    return tmp;
}

void push(stack_t *stack, int value) {
    stack->array = realloc(stack->array, (++stack->capacity) * sizeof(int));
    stack->array[stack->capacity - 1] = value;
}

stack_t init() {
    stack_t tmp = {NULL, 0};
    return tmp;
}
