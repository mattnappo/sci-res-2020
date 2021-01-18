#include "list_iter.h"

#include "../testlib.h"


int manual()
{
    struct list *list = new_list(0);

    for (int i = 0; i < 1000; i++) {
        for (int k = 0; k < 100; k++) {
            insert(list, rand());
        }
        // printf("i: %d\n", i*100);
    }
    
    free_list(list);

    return 0;
}

int test()
{
    srand(time(NULL));

    struct list *list = new_list(rand());
   
    long int ct = 10000000; // 10 mil
    //long int ct = 10000;
    for (int i = 0; i < ct; i++)
        insert(list, rand());

    for (int i = 0; i < ct; i++) {
        //printf("{G} %ld\n", get(list, i));
        get(list, i);
    }

    //print_list(list);

    free_list(list);
    
    return 0;
}

int main()
{
    double t = test_time(manual);
    printf("list iter time: %f\n", t);
    //manual();
    return 0;
}

