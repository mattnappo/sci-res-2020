#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack *init_stack(int capacity)
{
	struct stack *pt = malloc(sizeof(struct stack));

	pt->maxsize = capacity;
	pt->top = -1;
	pt->items = malloc(sizeof(int) * capacity);

	return pt;
}

int size(struct stack *pt)
{
	return pt->top + 1;
}

void free_stack(struct stack *pt)
{
	free(pt->items);
	free(pt);
}

int is_empty(struct stack *pt)
{
	return pt->top == -1;
}

int is_full(struct stack *pt)
{
	return pt->top == pt->maxsize - 1;
}

void push(struct stack *pt, int x)
{
	if (is_full(pt))
	{
		printf("stack overflow\n");
		exit(1);
	}
	pt->items[++pt->top] = x;
}

int peek(struct stack *pt)
{
	if (!is_empty(pt)) {
		return pt->items[pt->top];
	} else {
		exit(1);
	}
}

int pop(struct stack *pt)
{
	if (is_empty(pt))
	{
		printf("stack underflow\n");
		exit(1);
	}
	return pt->items[pt->top--];
}
