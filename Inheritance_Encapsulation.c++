#include <iostream>
#include <stdio.h>

using namespace std;

class first
{
private:
    int number;
public:
    void fun(int x)
    {
        number = x;
        for (; number <= 10; number++)
        {
            cout << " \n Class Looped at " << number << "\n";
        }
    }
};
class baseClass
{
    protected:

        int value=99;

    public:
       
        baseClass()
        {  
            cout<<"\n CONSTRUCTOR OF BASE CLASS HAS BEEN CALLED... \n ";
        }
        baseClass(int x)
        {
            cout << " Setting Value Through Parameterized Constructor: ";
            value = x;
        }
        void get()
        {
            cout << " \n Base Class: Updated Value is "<< value;
        }
};

class childClass : baseClass
{
public:
    childClass()
    {
        cout<<" \n CONSTRUCTOR OF CHILD CLASS HAS BEEN CALLED... \n";
    }
    void setValue(int x)
    {
        cout << "Setting Value Via Drived class ";
        value = x;
        cout << value;
    }
    void get()
    {
        cout << "\n Child Class: Updated Value is "<<value;
        baseClass::get();
    }
};


int main()
{
    //  first f = first();
    //creating object of base class and running the default constructor
    // baseClass b1 = baseClass();

    //creating object of base class and ruinnng the parameterized constuctor
    //  baseClass b2 = baseClass(7);
    childClass c1 = childClass();
    childClass c2 = childClass();


     c1.setValue(10);

    c1.get();
    c2.get();
    // int x;

    //  cout<<"Starting here \n Enter your input less than 10: ";
    //  cin>> x;
    //  cout<<"\n Your input value: "<<x;
    //  f.fun(x);
    return 0;
}
