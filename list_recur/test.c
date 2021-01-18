#include "list_recur.h"

#include "../testlib.h"

/*
int manual()
{
    struct list *list = new_list("zero");

    insert(list, "one");
    insert(list, "two");
    insert(list, "three");
    insert(list, "four");
    insert(list, "five");
    print_list(list);

    // Test search
    //assert(search(list, "two") == 2);
    //assert(search(list, "five") == 5);

    // Test get
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
*/

int test()
{
    srand(time(NULL));

    struct list *list = new_list(rand());
   
    //long int ct = 10000000; // 10 mil
    long int ct = 10000;
    for (int i = 0; i < ct; i++) {
        insert(list, rand());
    }

    for (int i = 0; i < ct; i++) {
        get(list, i);
        //printf("{G} %ld\n", g);
    }

    // print_list(list);

    free_list(list);
    
    return 0;
}

int main()
{
    double t = test_time(test);
    printf("list recur time: %f\n", t);
    return 0;
}
