#include "./dyn_array.h"

#include <stdio.h>

typedef struct Stack {
    size_t *contents;
    size_t count;
    size_t capacity;
} Stack;

void dump_stack(const Stack *stack)
{
    printf("---------------------\n");
    for (size_t i = 0; i < stack->count; ++i) {
        printf("%zu -> %zu\n", i, stack->contents[i]);
    }
}

int main(void)
{
    Stack stack = {0};
    array_append(&stack, 24);
    array_append(&stack, 25);
    array_append(&stack, 26);
    array_append(&stack, 27);
    dump_stack(&stack);

    array_delete(&stack);
    return 0;
}
