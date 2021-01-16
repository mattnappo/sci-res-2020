#include "list_iter.h"

#include "../testlib.h"

char *genrandstr() {

    static char charset[] = "abcdefABCDEF0123456789.#$?!";
    char *rstr;
    rstr = malloc(SIZE+1);
    int l = (int) (sizeof(charset)-1);
    int key;
    for (int n=0;n<SIZE;n++) {
        key = rand() % l;
        rstr[n] = charset[key];
    }
    rstr[SIZE] = '\0';
    return rstr;
}

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

int test()
{
    srand(time(NULL));

    char *init = genrandstr();
    struct list *list = new_list(init);
   
    //long int ct = 10000000; // 10 mil
    long int ct = 10;
    for (int i = 0; i < ct; i++)
        insert(list, genrandstr());

    for (int i = 0; i < ct; i++)
        printf("{G} %s\n", get(list, i));

    // print_list(list);
    
    return 0;
}

int main()
{
    double t = test_time(test);
    printf("list iter time: %f\n", t);
    return 0;
}

