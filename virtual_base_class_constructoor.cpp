class Foo
{
    public:
    Foo(int i){}
};
class Bar:virtual Foo
{
    public:
    Bar(){}
};
int main()
{
    Bar b;
}