#ifndef STACK_H
#define STACK_H

struct stack
{
    int maxsize;
    int top;
    int *items;
};

struct stack *init_stack(int capacity);
int size(struct stack *pt);
void free_stack(struct stack *pt);
int is_empty(struct stack *pt);
int is_full(struct stack *pt);
void push(struct stack *pt, int x);
int peek(struct stack *pt);
int pop(struct stack *pt);

#endif
