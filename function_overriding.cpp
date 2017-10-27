#include<stdio.h>
class Animal
{
    public:
    void run()
    {
        printf("\n Animal runs \n");
        return;
    }
};
class Dog:public Animal
{
    public:
    void run()
    {
        printf("\n Dog runs \n");
    }
};

int main()
{
    Dog d;
    d.run();
    //Dog runs
}