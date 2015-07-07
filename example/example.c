#include <stdio.h>
#include "fruit.h"

int main()
{
    Fruit a, b, c, d;

    a = Apple;
    b = Banana;

    printf("a = %s (%d)\n", Fruit_name(a), Fruit_val(a));
    printf("b = %s (%d)\n", Fruit_name(b), Fruit_val(b));

    c = Apple;

    if (c == a) puts("c == a");
    if (c == b) puts("c == b");

    d = 0;

    printf("d = %s (%d)\n", Fruit_name(d), Fruit_val(d));

    return 0;
}
