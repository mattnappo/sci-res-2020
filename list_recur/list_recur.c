#include "list_recur.h"

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
        //free(old_head->value);
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

static void insert_(struct node *node, long data)
{
    if (node->next == NULL) { // base case
        struct node *new = malloc(sizeof(struct node));
        new->value = data;
        new->next = NULL;
        node->next = new;
        return;
    }
    insert_(node->next, data);
}

void insert(struct list *list, long data)
{
    insert_(list->head, data);
    list->length++;
}

static long get_(struct node *node, int index)
{
    if (index == 0) {
        return node->value;
    }
    return get_(node->next, index-1);
}

long get(struct list *list, int index)
{
    if (index >= list->length) {
        printf("index %d out of bounds\n", index);
        exit(1);
    }
    return get_(list->head, index);
}

static struct node *search_(struct node *node, long target)
{
    if (node == NULL) { // not in list
        printf("'%ld' not in list\n", target);
        return NULL;
    }
    if (target == node->value) // base case
        return node;
    return search_(node->next, target);
}

struct node *search(struct list *list, long target)
{
    return search_(list->head, target);
}

