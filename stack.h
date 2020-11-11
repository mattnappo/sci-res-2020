// This stack holds binary tree nodes
#ifndef STACK_H
#define STACK_H

#include "bst_iter/bst_iter.h" // Get the definition of a node

struct stack
{
    int maxsize;
    int top;
    struct node **items;
};

struct stack *init_stack(int capacity);
int size(struct stack *pt);
void free_stack(struct stack *pt);
int is_empty(struct stack *pt);
int is_full(struct stack *pt);
void push(struct stack *pt, struct node *n);
struct node *peek(struct stack *pt);
struct node *pop(struct stack *pt);

#endif
