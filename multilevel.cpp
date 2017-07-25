#include<stdio.h>

class GrandParent
{
    public:
    void print_method()
    {
        printf("GrandParent::print_method()\n");
    }
};

class Parent1:public GrandParent
{
    
};

class Parent2:public GrandParent
{
    
};

class Child:public Parent1, public Parent2
{

};

int main()
{
    Child c;
    c.print_method();
    /*
    multilevel.cpp: In function ‘int main()’:
    multilevel.cpp:30:7: error: request for member ‘print_method’ is ambiguous
     c.print_method();
       ^
    multilevel.cpp:6:10: note: candidates are: void GrandParent::print_method()
    void print_method()
          ^
    multilevel.cpp:6:10: note:                 void GrandParent::print_method()
    */
}