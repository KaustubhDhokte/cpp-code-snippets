#include<stdio.h>

class Animal
{
    public:
    virtual Animal()
    {
        //virtual_constructors.cpp:6:20: error: constructors cannot be declared virtual        
    }
};

class Dog
{
    public:
    Dog()
    {

    }
};

/*
There is no point in virtual constructor - you declare exactly what type is created, and it is well known in compile time. The compiler do not need [and actually cannot, since the dynamic dispatch is based on information which is created only after the object was created].
So there are no virtual constructors.
*/