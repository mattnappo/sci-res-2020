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
        else if (data > temp->data) {
            temp = temp->right;
        }
    }

    // Insert
    if (data < trail->data) {
        trail->left = init_node(data);
    } else {
        trail->right = init_node(data);
    }

}

static struct node *search_(struct node *node, DTYPE target)
{
    if (node->data == target) {
        return node;
    }

    else if (target < node->data) {
        if (node->left != NULL) {
            return search_(node->left, target);
        } else {
            printf("%d not in tree\n", target);
            return NULL;
        }
    }

    else if (target > node->data) {
        if (node->right != NULL) {
            return search_(node->right, target);
        } else {
            printf("%d not in tree\n", target);
            return NULL;
        }
    }

    return NULL; // Unreachable
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

    while (temp != NULL) {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->left;
        }

    }
}
