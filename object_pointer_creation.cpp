//https://stackoverflow.com/questions/4937180/a-base-class-pointer-can-point-to-a-derived-class-object-why-is-the-vice-versa

#include<stdio.h>

class Animal
{
    public:
    void print()
    {
        printf("\nIn Base Print method\n");
    }
};

class Dog:public Animal
{
    public:
    void print()
    {
        printf("\nIn derived print method\n");
    }
};

int main()
{
    Animal *b;
    Dog *d;

    b = new Animal(); //Obviosly Possible
    d = new Dog(); //Obviously Possible
    b = new Dog(); //Dog is definitely an animal. So possible
    d = new Animal(); //Any Animal is not neccesarily a Dog. Hence not possible
    /*
    Fails with:
    virtual_functions.cpp: In function ‘int main()’:
    virtual_functions.cpp:30:7: error: invalid conversion from ‘Animal*’ to ‘Dog*’ [-fpermissive]
    */
}