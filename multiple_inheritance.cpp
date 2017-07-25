#include<stdio.h>
class Base1
{
    int a;
    public:
    void base_method()
    {
        printf("Base 1 class method called!\n");
    }

};

class Base2
{
    int a;
    public:
    void base_method(char a)
    {
        printf("Base 2 class method called!\n");
    }

};

class Derived:public Base1, public Base2
{
    public:
    void derived_method()
    {
        printf("Derived  method\n");
    }
    void derived_method(char a)
    {
        printf("Parameterized derived method\n");
    }
};

int main()
{
    Derived d;
    d.base_method();
    /*
    error: request for member ‘base_method’ is ambiguous
     d.base_method();
       ^
multiple_inheritance.cpp:17:10: note: candidates are: void Base2::base_method()
     void base_method()
          ^
multiple_inheritance.cpp:6:10: note:                 void Base1::base_method()
     void base_method()
    */
    d.derived_method();
}