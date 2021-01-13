/// Write all of these data structures and write a testing
/// framework to test all of them on all sets of inputs
/// and measure the time it took to run them. Then graph and
/// compare for common methods link store, get, search, etc.
#include "list_iter.h"

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

void insert(struct list *list, char data[])
{
    // Move to the tail (current = tail)
    struct node *current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }

    struct node *new = malloc(sizeof(struct node));
    strncpy(new->value, data, SIZE);
    new->next = NULL;

    current->next = new;
    list->length++;
}

char *get(struct list *list, uint32_t index)
{
    if (index >= list->length) {
        printf("index %d out of bounds\n", index);
        return NULL;
    }

    struct node *current = list->head;
    for (uint32_t i = 0; i < index; i++) {
        current = current->next;
    }

    return current->value;
}

uint32_t search(struct list *list, char target[])
{
    uint32_t index = 0;
    struct node *current = list->head;
    while (current != NULL) {
        if (strncmp(target, current->value, SIZE) == 0) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}

void delete_index(struct list *list, uint32_t index)
{
    if (index >= list->length || index <= 0) {
        printf("index %d out of bounds\n", index);
        return;
    }

    // The node right before the target node
    struct node *behind = list->head;
    for (uint32_t i = 0; i < index - 1; i++) {
        behind = behind->next;
    }
   
    struct node *to_next = behind->next->next;
    free(behind->next);
    printf("to_next: %p\n", to_next);
    behind->next = to_next;
}

void delete_value(struct list *list, char target[])
{
    uint32_t index = search(list, target);
    delete_index(list, index);
}
