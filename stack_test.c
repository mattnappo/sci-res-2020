#include "stack.h"

int main(void)
{
    struct stack *sp = init_stack(100);

    struct node *n1 = init_node(10);
    struct node *n2 = init_node(20);
    struct node *n3 = init_node(30);
    struct node *n4 = init_node(40);

    push(sp, n1);
    push(sp, n2);
    push(sp, n3);
    push(sp, n4);

    print_node(pop(sp));

    free_stack(sp);

    return 0;
}
