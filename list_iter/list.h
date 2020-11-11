#include "../include.h"

#ifndef LIST_H
#define LIST_H

#define SIZE 32
// #define GUARD (i) (if (i < list->length) {  }

struct node {
    struct node *next;
    char value[SIZE];
};

struct list {
    struct node *head;
    uint32_t length; // Just for convenience
};

struct list *new_list(char root_val[]);
void free_list(struct list *list);
void print_list(struct list *list);
void insert(struct list *list, char data[]);
char *get(struct list *list, uint32_t index);
uint32_t search(struct list *list, char target[]);
void delete_index(struct list *list, uint32_t index);
void delete_value(struct list *list, char target[]);

#endif
