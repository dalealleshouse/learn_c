#include <stdio.h>

void apples_set(int value);
int apples_get();

static int data;

void oranges_set(int value)
{
    data = value;
}

int oranges_get()
{
    return data;
}

int main()
{
    apples_set(5);
    oranges_set(10);
    printf("apples=%d, oranges=%d\n", apples_get(), oranges_get());
    return 0;
}
