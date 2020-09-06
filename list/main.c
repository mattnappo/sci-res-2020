/// Write all of these data structures and write a testing
/// framework to test all of them on all sets of inputs
/// and measure the time it took to run them. Then graph and
/// compare for common methods link store, get, search, etc.

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

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

int test()
{
    struct list *list = new_list("zero");

    insert(list, "one");
    insert(list, "two");
    insert(list, "three");
    insert(list, "four");
    insert(list, "five");
    print_list(list);

    // Test search
    assert(search(list, "two") == 2);
    assert(search(list, "five") == 5);

    // Test getj
    assert(strcmp(get(list, 3), "three") == 0);
    assert(strcmp(get(list, 5), "five") == 0);
    
    // Test delete
    delete_index(list, 5);
    delete_index(list, 3);
    assert(strcmp(get(list, 0), "zero") == 0);
    assert(strcmp(get(list, 1), "one")  == 0);
    assert(strcmp(get(list, 2), "two")  == 0);
    assert(strcmp(get(list, 3), "four") == 0);

    free_list(list);

    return 0;
}

int main() { return test(); }
