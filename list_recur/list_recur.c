#include "list_recur.h"

struct list *new_list(char root_val[])
{
    // Make the head
    struct node *head = malloc(sizeof(struct node));
    strncpy(head->value, root_val, SIZE);
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
        printf("[%d] %s\n", counter, current->value);
        current = current->next;
        counter++;
    } 
}

static void insert_(struct node *node, char data[])
{
    if (node->next == NULL) { // base case
        struct node *new = malloc(sizeof(struct node));
        strncpy(new->value, data, SIZE);
        new->next = NULL;
        node->next = new;
        return;
    }
    insert_(node->next, data);
}

void insert(struct list *list, char data[])
{
    insert_(list->head, data);
    list->length++;
}

static char *get_(struct node *node, int index)
{
    if (index == 0) {
        return node->value;
    }
    return get_(node->next, index-1);
}

char *get(struct list *list, int index)
{
    if (index >= list->length) {
        printf("index %d out of bounds\n", index);
        return NULL;
    }
    return get_(list->head, index);
}

static struct node *search_(struct node *node, char target[])
{
    if (node == NULL) { // not in list
        printf("'%s' not in list\n", target);
        return NULL;
    }
    if (strncmp(target, node->value, SIZE) == 0) // base case
        return node;
    return search_(node->next, target);
}

struct node *search(struct list *list, char target[])
{
    return search_(list->head, target);
}

void delete_index(struct list *list, int index)
{
    if (index >= list->length || index <= 0) {
        printf("index %d out of bounds\n", index);
        return;
    }

    // The node right before the target node
    struct node *behind = list->head;
    for (int i = 0; i < index - 1; i++) {
        behind = behind->next;
    }
   
    struct node *to_next = behind->next->next;
    free(behind->next);
    printf("to_next: %p\n", to_next);
    behind->next = to_next;
}

