#include<stdio.h>
int main()
{
    static int i=10;
    printf("%d\n", i++);
    printf("%d\n", i++);
    printf("%d\n", i);
    i++;
    printf("%d\n", i);
    printf("%d\n", ++i);
}