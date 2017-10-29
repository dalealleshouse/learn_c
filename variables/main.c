#include <stdio.h>

int main()
{
    /* Variables stored on the stack */
    int apples = 5;
    int oranges = apples;

    apples = 4;

    printf("applies = %d, oranges = %d\n", apples, oranges);

    return 0;
}
