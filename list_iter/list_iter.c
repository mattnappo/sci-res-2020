/// Write all of these data structures and write a testing
/// framework to test all of them on all sets of inputs
/// and measure the time it took to run them. Then graph and
/// compare for common methods link store, get, search, etc.
#include "list_iter.h"

struct list *new_list(long root_val)
{
    // Make the head
    struct node *head = malloc(sizeof(struct node));
    head->value = root_val;
    head->next = NULL;

    // Make the list
    struct list *list = malloc(sizeof(struct list));
    list->head = head;
    list->length = 1;

    return list;
}

void free_list(struct list *list)
{
    struct node *old_head;
    // Shift over by 1 each time
    while (list->head != NULL) {
        old_head = list->head;
        list->head = list->head->next;
        free(old_head);
    }
    free(list);
}

void print_list(struct list *list)
{
    struct node *current = list->head;
    int counter = 0;
    while (current != NULL) {
        printf("[%d] %ld\n", counter, current->value);
        current = current->next;
        counter++;
    } 
}

void insert(struct list *list, long data)
{
    // Move to the tail (current = tail)
    struct node *current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }

    struct node *new = malloc(sizeof(struct node));
    new->value = data;
    new->next = NULL;

    current->next = new;
    list->length++;
}

long get(struct list *list, int index)
{
    if (index >= list->length) {
        printf("index %d out of bounds\n", index);
        exit(1);
    }

    struct node *current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->value;
}

int search(struct list *list, long target)
{
    int index = 0;
    struct node *current = list->head;
    while (current != NULL) {
        if (target == current->value) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}

