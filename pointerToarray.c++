#include<iostream>
#include<stdio.h>

using namespace std;
int Assign(int array[]);

int main()
{   int i=0;
    int array[5]={7,1,2,8,3};
    int* pointer = array;

    cout<<"Value : "<<*pointer<<endl;
    // pointer++;
   
    cout<<" Pointer value "<< *++pointer<<endl; 
    *pointer = *pointer+13;
    cout<<endl<<"Value : "<<*pointer<<endl;
    // cout<<endl<<array[0]<<endl
    while (i<5)
    {
        
        cout<<"\n\nValue :"<<array[i]<<endl;
        i++;
    }
    
}

