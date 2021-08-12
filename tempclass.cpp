#include<stdio.h>
#include<iostream>

using namespace std;

template<class T>
class sum
{   
    T x;
    T y;

    public: 
    void setter(T a, T b)
    {   
        x=a;
        y=b;
    }
    T getter();
    

};

template<class T>

T sum <T> :: getter(){
    cout<<"The Sum is"<< x+y;
}

int main()
{
    float x,y;
    cout<<"\n enter number : ";
    cin>>x;
    cin>>y;

    sum <float> s;
    s.setter(x,y);
    s.getter();
}