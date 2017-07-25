#include<stdio.h>
class Base
{
    public:
    void method_A()
    {
        printf("Method A called!\n");
    }
    /*
    int method_A()
    {
        printf("method A with int return type\n");
    }

    error: ‘int Base::method_A()’ cannot be overloaded
    int method_A()
         ^
    function_overloading.cpp:5:10: error: with ‘void Base::method_A()’
    void method_A()

    Method overloading has nothing to do with return type
    */
    void method_A(char b)
    {
        printf("Parameterized method A called\n");
    }
};

int main()
{
    Base b;
    b.method_A();
    b.method_A('b');
}