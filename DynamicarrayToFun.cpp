#include<iostream>
#include<stdio.h>

using namespace std; 
//Creating a dynamic array and then passing it to a function 
int fun(int array[],int len)
{
    cout<<"Please press 00 when you want to quit entering the numbers"<<endl;
    int x;
    x=len;

    for(int i=0;i<len;i++)
    {
        cout<<"Index no. "<<i+1<<" : ";
        cin>>array[i];

        if (array[i] == 00)
        {  
            x=i;
            cout<<endl<<"You wished to quit at index: "<< x-1 <<endl;
            break;
        }
        
    }

    for(int i=0;i<x;i++)
    {   
        cout<<"Value at index "<<i<<" : "<<array[i]<<endl;
    }
    
};

int main()
{
    int len,x;

    cout<<"Enter size of the array :";
    cin>>len;

    int *array = new int (len);
   
    fun(array,len);
}