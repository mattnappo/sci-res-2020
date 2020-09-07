#include "../include.h"

#ifndef BST_H
#define BST_H

#define STR_SIZE 128
#define DTYPE uint32_t // Breaking, but the idea is here

struct node {
    struct node *left;
    struct node *right;
    // struct data *data;
    DTYPE data;
};

struct tree {
    struct node *head;
};

struct tree *init_tree();
struct node *init_node(DTYPE data);
void free_tree(struct tree *tree);
void print_tree(struct tree *tree);
void insert(struct tree *tree, DTYPE data);
struct node *search(struct tree *tree, DTYPE target);
void delete(struct tree *tree, DTYPE data);

struct node *minimum(struct tree *tree);
struct node *maximum(struct tree *tree);

// Extras
int64_t sum(struct tree *tree);

#endif
