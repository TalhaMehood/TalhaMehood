// MUTLIPLE INHERITANCE AND VIRTUAL FUNCTION

#include<stdio.h>
#include<iostream>

using namespace std;

class Aclass
{
    public:
    virtual void funa()
    {
        cout<<"\nFunction A of class A has been called "<<endl;
    }
    void funaa()
    {
        cout<<"\nFunction A of class A has been called "<<endl;
    }
    void aclas()
    {
        cout<<"\n This is a parent class"<<endl;
    }

};

class Bclass
{
    public:
    Bclass()
    {
        cout<<"this b class"<<endl;
    }
    void funb()
    {
        cout<<"\nFunction B of class B has been called "<<endl;
    }
};

class Cclass: public Aclass, public Bclass
{
    public:
    void funa()
    {
        cout<<"\nFunction has been called "<<endl;
    }
    void funaa()
    {
        cout<<"\n Class C has been called "<<endl;
    }
};

class Dclass:private Cclass
{
    cout<<"Function of Class D";
};
int main()
{
    Cclass c;      
    Aclass *obj = &c;
    Dclass dclass;
    obj->funa(); //Multiple inhertance via polymorphism
    obj->funaa(); //Multiple inheritance via polymorphism
    dclass.aclas(); //Multi Level Inheritance and also hybrid inheritance at same time because it inhertis class C which itself made up of multiple inheritance

    return 0;
}