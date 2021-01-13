#include "list_iter.h"

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
