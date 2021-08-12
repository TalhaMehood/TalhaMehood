#include<iostream>
#include<stdio.h>

using namespace std;
int Assign(int array[]);

int main()
{
    int array[5]={7,1,2,8,3};
    int* pointer = array;

    cout<<"Value : "<<*pointer<<endl;
    // pointer++;
    *pointer = *pointer+3;
    cout<<endl<<"Value : "<<*pointer<<endl;
    // cout<<endl<<array[0]<<endl

}

