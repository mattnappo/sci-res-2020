#include "stack.h"

int main(void)
{
    struct stack *sp = init_stack(10);

    struct node *n1 = init_node(1000);

    push(sp, n1);
    push(sp, init_node(20));
    push(sp, init_node(30));
    push(sp, init_node(40));

    struct node *popped = pop(sp);
    free(popped);

    free_stack(sp);

    return 0;
}
