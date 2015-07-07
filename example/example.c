#include <stdio.h>
#include "fruit.h"

int main()
{
    Fruit a, b, c;

    a = Apple;
    b = Banana;

    printf("a = %s\n", Fruit_name(a));
    printf("b = %s\n", Fruit_name(b));

    c = 0;

    printf("c = %s\n", Fruit_name(c));

    return 0;
}
