#include<iostream>
#include<stdio.h>

using namespace std;

class Employee{
    int salary;
    int b;
    static int c;
    int d;
    

    public:
    Employee(){
        d = 0;
    }
    void set(int x,int y)
    {
        salary=x; b=y;
        c++;
        d++;

    }
    void get()
    {
        cout<<"\nSalary for the Employee is  "<<salary <<" "<<b;
        cout<<"\n(Static variable) ID Of Employee : "<<c;
        cout<<"\nValue for Simple variable "<<d;

    }
};
int Employee::c = 0;  //default value is 0
int main(){

    int x=500,y=5;
    Employee Talha,Hamza,Asharib,Awais;

    cout<<"///////////////////////////\n";
    Talha.set(x,y);
    cout<<endl;
    Talha.get();

    Hamza.set(x,y);
    cout<<endl;
    Hamza.get();

    Asharib.set(x,y);
    cout<<endl;
    Asharib.get();

    Awais.set(x,y);
    cout<<endl;
    Awais.get();
    return 0;

}