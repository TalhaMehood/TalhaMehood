#include<iostream>
#include<stdio.h>

using namespace std;

template<class any1, class any2> 

any1 comp (any1 x,any2 y)
{
    return (x>y?x:y);
}

int main()
{
    int x,y;
    
    cout<<"Enter two numbers";
    cin>>x; cin>>y; 
    cout<<comp(x,y);
}