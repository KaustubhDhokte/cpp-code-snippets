#include<stdio.h>

class Base
{
    public:
    void print_method()
    {
        printf("\nBase print method");
    }
};

class Derived:public Base
{
    public:
    void print_method()
    {
        printf("\nDerived print method\n");
    }
};

int main()
{
    Derived d;
    d.print_method();
}