#include "bst_iter.h"

#include "../testlib.h"

int manual()
{
    struct tree *tree = init_tree();
    insert(tree, 10);
    insert(tree, 8);
    insert(tree, 15);
    insert(tree, 16);
    insert(tree, 14);
    insert(tree, 9);
    insert(tree, 5);

    struct node *head = tree->head;
    printf("         %d            \n", head->data);
    printf("   %d          %d      \n", head->left->data, head->right->data);
    printf("%d    %d    %d     %d  \n",
            head->left->left->data,
            head->left->right->data,
            head->right->left->data,
            head->right->right->data
    );
   
    struct node *got = search(tree, 15);
    printf("  %d   \n", got->data);
    printf("%d  %d \n", got->left->data, got->right->data);

    in_order(tree);

    free_tree(tree);
    
    return 0;
}

int test()
{
    srand(time(NULL));
    struct tree *tree = init_tree();
    long int ct = 10000000;
    for (int i = 0; i < ct; i++) {
        int r = rand();
        insert(tree, r);
    }

    in_order(tree);
    // Try to use get on the tree to get something after running in_order

    free_tree(tree);
    return 0;
}


int main() {
    double t = test_time(test);
    printf("time: %f\n", t);
    // manual();
    return 0;
}
