#include<stdio.h>

class AbstractClass
{

    public:
    //virtual void pure_virtual_function() = 0;
    void non_virtual_function()
    {
        printf("\nNon Virtual Function\n");
    }
    virtual void another_pure_virtual_function() = 0;
};

void AbstractClass::another_pure_virtual_function()
{
    printf("\nImplementation of another pure virtual function\n");
}

int main()
{
    //AbstractClass a;
    /*
    abstract_class.cpp: In function ‘int main()’:
    abstract_class.cpp:16:19: error: cannot declare variable ‘a’ to be of abstract type ‘AbstractClass’
     AbstractClass a;
                   ^
    abstract_class.cpp:3:7: note:   because the following virtual functions are pure within ‘AbstractClass’:
    class AbstractClass
       ^
    abstract_class.cpp:7:18: note:  virtual void AbstractClass::pure_virtual_function()
    virtual void pure_virtual_function() = 0;
    */

    //AbstractClass *a; //Acceptable

    //a = new AbstractClass();    //Not accepatable
}