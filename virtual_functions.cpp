#include<stdio.h>

class Animal
{
    public:
    Animal()
    {
        printf("Animal constructor \n");
    }
    virtual void run()
    {
        printf("Animal::run \n");
    }
    void eat()
    {
        printf("Animal::eat\n");
    }
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
    Dog()
    {
        printf("Dog constructor \n");
    }
};

class Labrador:public Dog
{
    public:
    void run()
    {
        printf("Labrador::run \n");
    }
    void eat()
    {
        printf("Labrador::eat\n");
    }
    Labrador()
    {
        printf("Labrador constructor \n");
    }
};

int main()
{
    Animal *a, *a2;
    Dog *d;
    Labrador *l;

    a = new Dog(); // Constructor Runs: Animal and Dog
    a->run(); //Calls Animal::Run if not declared virtual, otherwise calls Dog::Run

    a2 = new Animal();
    a2->run(); 

    a = new Labrador(); // Constructor Runs: Animal and Dog and Labrador sequentially
    a->run(); // Calls labrador::run if Animal::run is virtual

    d = new Labrador(); // Constructor Runs: Animal and Dog and Labrador sequentially
    d->run(); // Calls labrador::run even if Dog::run is not declared as virtual. Surprise.

    a = new Dog(); // Constructor Runs: Animal and Dog sequentially
    a->eat();

}