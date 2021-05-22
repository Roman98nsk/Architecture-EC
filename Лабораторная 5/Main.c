#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#include "myReadkey.h"

int main ()
{
    enum keys k;
    rk_readkey (&k);
    printf ("KEY - %d\n", k);

    return 0;
}
