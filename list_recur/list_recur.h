#include "../include.h"

#ifndef LIST_H
#define LIST_H

#define SIZE 32
// #define GUARD (i) (if (i < list->length) {  }

struct node {
    struct node *next;
    long value;
};

struct list {
    struct node *head;
    int length; // Just for convenience
};

struct list* new_list     (long root_val);
void         free_list    (struct list *list);
void         print_list   (struct list *list);
void         insert       (struct list *list, long data);
long         get          (struct list *list, int index);
struct node *search       (struct list *list, long target);
void         delete_index (struct list *list, int index);
void         delete_value (struct list *list, long target);

#endif
