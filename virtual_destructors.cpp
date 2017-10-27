#include<stdio.h>

class Animal
{
    public:
    virtual ~ Animal()
    {
        printf("Destructor Animal\n");
    }
    void run()
    {
        printf("Animal::run\n");
    }
};

class Dog:public Animal
{
    public:
    ~ Dog()
    {
        printf("Destructor Dog\n");
    }
    void run()
    {
        printf("Dog::run\n");
    }
};

int main()
{
    Animal *a;
    a = new Dog();
    a->run();

    delete a;
    /*
    Both destructors are executed: Dog first then Animal: If destructor made virtual
    */

    /*
    Destructor of only Animal is called if ~Animal is not virtual
    */
}