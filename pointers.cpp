#include<iostream>
#include<stdio.h>

using namespace std; 

int main()
{
    int value = 25;
    int *pointer = &value;
    int &point = value;

    cout<<"Value = "<<value <<endl;

    cout<<"Printing the 'point' variable: "<<point<<endl;
    point = point -5;
    cout<<"Printing the 'value' variable after changes in point: "<<value<<endl;
    
    cout<<"Printing the '*pointer': "<<*pointer<<endl;
    *pointer = *pointer+ 5;
    cout<<"Printing the 'value' variable after changes in '*pointer':  "<<value<<endl;

    // cout<<"Printing the '&value': " <<&value <<endl;

    cout<<"Printing the 'pointer' variable: " <<pointer <<endl;
    // pointer --;
    // cout<<"Printing the 'value' after making changes in the 'pointer' i.e address of the 'value': " <<value <<endl;

    cout<<"Printing the '&value': " <<&value <<endl;
    cout<<"Printing the  '&pointer': "<< &pointer<<endl;
}