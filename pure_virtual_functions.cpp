#include<stdio.h>

class Animal
{
    private:
    virtual void private_function() = 0;
    /*
    pure_virtual_functions.cpp: In function ‘int main()’:
    pure_virtual_functions.cpp:55:9: error: cannot declare variable ‘d’ to be of abstract type ‘Dog’
    Dog d;
         ^
    pure_virtual_functions.cpp:19:7: note:   because the following virtual functions are pure within ‘Dog’:
    class Dog:public Animal
       ^
    pure_virtual_functions.cpp:6:18: note:  virtual void Animal::private_function()
    virtual void private_function() = 0;
    */

    public:
    Animal()
    {
        printf("Animal constructor \n");
    }
    virtual void run()
    {
        printf("Animal::run \n");
    }
    virtual void eat() = 0;
};

class Dog:public Animal
{
    public:
    void run()
    {
        printf("Dog::run \n");
    }
    void eat()
    {
        printf("Dog::eat\n");
    }

    /*
    Seems that if pure virtual function is not implemented then it is inherited and derived class
    becomes abstract one.
    */

    /*
    pure_virtual_functions.cpp:17:7: note:   because the following virtual functions are pure within ‘Dog’:
    class Dog:public Animal

    pure_virtual_functions.cpp:14:18: note:         virtual void Animal::eat()
    virtual void eat() = 0;

    pure_virtual_functions.cpp:52:18: error: invalid new-expression of abstract class type ‘Dog’
    a2 = new Dog();
    */

    Dog()
    {
        printf("Dog constructor \n");
    }
};

int main()
{
    Dog d;
    //Animal a;
    /*
    Above declaration fails with:
    pure_virtual_functions.cpp: In function ‘int main()’:
    pure_virtual_functions.cpp:37:12: error: cannot declare variable ‘a’ to be of abstract type ‘Animal’
    Animal a;
            ^
    pure_virtual_functions.cpp:3:7: note:   because the following virtual functions are pure within ‘Animal’:
    class Animal
       ^
    pure_virtual_functions.cpp:14:18: note:         virtual void Animal::eat()
    */
    Animal *a2; //mere declaration works ok
    //a2 = new Animal(); //Fails with above error
    
    //a2 = new Dog();
}