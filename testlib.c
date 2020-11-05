#include "testlib.h"

double test_time(int (*func)(void))
{
    clock_t t;
    t = clock();
    assert((*func)() == 0);
    t = clock() - t;

    return (double) t;
}
