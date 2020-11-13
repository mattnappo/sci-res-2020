#include "../include.h"
#include "../stack.h"

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
    int nodes; // The number of nodes
};

struct tree *init_tree();
struct node *init_node(DTYPE data);
void free_tree_(struct node *node);
void free_tree(struct tree *tree);
void print_node(struct node *node);
void print_tree(struct tree *tree);
void insert(struct tree *tree, DTYPE data);
struct node *search(struct tree *tree, DTYPE target);
void delete(struct tree *tree, DTYPE data);
struct node *minimum(struct tree *tree);
struct node *maximum(struct tree *tree);
void in_order(struct tree *tree);
int64_t sum(struct tree *tree);

#endif
