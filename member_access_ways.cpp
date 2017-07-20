#include<stdio.h>

using namespace std;

class Base 
{
    int a;
    public:
    void setA(int a)
    {
        this->a = a;
    }
    int getA()
    {
        return a;
    }
};

class Base2 
{
    int a;
    public:
    void setA(int a)
    {
        Base2::a = a;
    }
    int getA()
    {
        return a;
    }
};

class Base3 
{
    int a;
    public:
    void setA(int a)
    {
        a = a;
    }
    int getA()
    {
        return a;
    }
};

int main()
{
    Base b;
    b.setA(5);
    printf("B returned: %d\n", b.getA());
    // B returned: 5

    Base2 b2;
    b2.setA(5);
    printf("B returned: %d\n", b2.getA());
    // B returned: 5

    Base3 b3;
    b3.setA(5);
    printf("B returned: %d\n", b3.getA());
    //B returned: 1707544800 (garbage)

}