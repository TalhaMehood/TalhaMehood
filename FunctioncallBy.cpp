#include<iostream> 
#include<stdio.h>

using namespace std;

int  passByVal(int  add)
{
    add= 7;
    cout<<endl<<"Passing the name by Value: ";
    return add; 
};

int passByRef(int  &add)
{   
    add=9;
    cout<<endl<<"Passing the name by Reference: ";
    return add;
};

int main()
{
    int  val = 5;
    //WHEN THE VARIABLE PASSED BY VALUE THE VALUE IN THE MAIN DID NOT CHANGED
    cout<<endl<<add<<endl;

    int  &add = val; 
    //WHEN THE VARIABLE PASSED BY REFERENCE THE VALUE IN THE MAIN ALSO CHANGED
    cout<<passByRef(add);
    cout<<endl<<add<<endl;
}