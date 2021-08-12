#include<iostream>
#include<stdio.h>

using namespace std; 

int main()
{
    string name = "Talha";

    cout<< name<<endl;  
    // now I can do the same using references

    // I will declare another variable with reference operator

    string &ref = name;

    //ref has the value of name 
    
    cout<<ref<<endl;

    //this operator can also be used to to get the address of the variable like 

    cout<<&name<<endl<<&ref; // both variable pointing at the same address 

    //value of the original variable can be changed by the reference variable
    ref = "ALi";
    cout<<endl<<ref<<endl<<name;

}