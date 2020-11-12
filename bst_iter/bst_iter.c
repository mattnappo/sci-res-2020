#include "bst_iter.h"

struct node *init_node(DTYPE data)
{
    struct node *node = malloc(sizeof(struct node));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return node;
}

struct tree *init_tree()
{
    struct tree *tree = malloc(sizeof(struct tree));
    tree->head = NULL;
    tree->nodes = 1;
    return tree;
}

static void free_tree_(struct node *node)
{
    if (node != NULL) {
        free_tree_(node->left);
        free_tree_(node->right);
        free(node);
    }
}

void free_tree(struct tree *tree)
{
    free_tree_(tree->head);
    free(tree);
}

void print_node(struct node *node) { printf("Node{%d}\n", node->data); }

void insert(struct tree *tree, DTYPE data)
{
    // If there is no head
    if (tree->head == NULL) {
        tree->head = init_node(data);
        return;
    }

    // Traverse to a leaf
    struct node *temp = tree->head;
    struct node *trail = NULL;
    while (temp != NULL) {
        trail = temp;
        if (data < temp->data) {
            temp = temp->left;
        }
        else if (data >= temp->data) {
            temp = temp->right;
        }
    }

    // Insert
    if (data < trail->data) {
        trail->left = init_node(data);
    } else {
        trail->right = init_node(data);
    }

    ++tree->nodes;

    // printf("inserted %d\n", data);
}

struct node *search(struct tree *tree, DTYPE target)
{
    struct node *temp = tree->head;
    while (temp != NULL) {
        if (target == temp->data) {
            return temp;
        }
        else if (target < temp->data) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }

    return NULL;
}

void in_order(struct tree *tree)
{
    struct node *temp = tree->head;
    struct stack *stack = init_stack(tree->nodes);

    while (temp != NULL || is_empty(stack) == 0) {
        while (temp != NULL) {
            push(stack, temp);
            temp = temp->left;
        }

        temp = peek(stack);
        pop(stack);

        // printf("%d ", temp->data); // Silent

        temp = temp->right;
    }

    free_stack(stack);
}
