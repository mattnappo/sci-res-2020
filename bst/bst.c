#include "bst.h"

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
    return malloc(sizeof(struct tree));
}

void free_tree(struct tree *tree)
{
    // TODO: Finish this
    free(tree);
}

void print_tree(struct tree *tree);

static void insert_(struct node *node, DTYPE data)
{
    // If the value is less, branch to the left
    if (data < node->data) {
        if (node->left != NULL) {
            insert_(node->left, data);
        } else {
            node->left = init_node(data);
        }
    }

    // If the value is greater, branch to the right
    else if (data >= node->data) { // Make this >= for dups
        if (node->right != NULL) {
            insert_(node->right, data);
        } else {
            node->right = init_node(data);
        }
    }
}

void insert(struct tree *tree, DTYPE data)
{
    // If there is no head
    if (tree->head == NULL) {
        tree->head = init_node(data);
        return;
    }
    insert_(tree->head, data);
}

static struct node *get_(struct node *node, DTYPE target)
{
    if (node->data == target) {
        return node;
    }

    else if (target < node->data) {
        if (node->left != NULL) {
            return get_(node->left, target);
        } else {
            printf("%d not in tree\n", target);
            return NULL;
        }
    }

    else if (target > node->data) {
        if (node->right != NULL) {
            return get_(node->right, target);
        } else {
            printf("%d not in tree\n", target);
            return NULL;
        }
    }

    printf("REACHED THIS?!?!\n\n");
    return NULL; // Unreachable
}

struct node *get(struct tree *tree, DTYPE target)
{
    if (tree->head == NULL) {
        return NULL;
    }

    return get_(tree->head, target);
}

void delete(struct tree *tree, DTYPE data);

static int balanced_(struct node *node)
{
    if (node->left != NULL) {
        if (node->left->data < node->data) {
            return balanced_(node->left);// good
        } else {
            return 1; // bad
        }
    }

    if (node->right != NULL) {
        if (node->right->data > node->data) {
            return balanced_(node->right);
        } else {
            return 1;
        }
    }

    printf("REACHED THIS (in balanced)\n\n");
    return 0; // Unreachable
}


int balanced(struct tree *tree)
{
    if (tree->head == NULL) {
        return 1;
    }

    return balanced_(tree->head);
}

