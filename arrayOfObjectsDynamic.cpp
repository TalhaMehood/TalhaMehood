#include<iostream>
#include<stdio.h>

using namespace std;

class student{
    int sid;
    int marks;

    public:
    static int count;
    void enterMarks(int x, int y)
    {
        sid=x;
        marks=y;
        count++;
    }
    void displayMarks()
    {
        cout<<"Marks of the Student "<<sid+1<<" = "<<marks<<endl;
    }
};

int student:: count;

int main()
{   int marks,x=0;
    cout<<"Enter the number of students : ";
    cin>> x;
    student s[x];
    for(int i=0;i<x;i++)
    {
        cout<<"Enter Marks for Student no "<<i+1 <<" : ";
        cin>>marks;
        s[i].enterMarks(i,marks);
    }
    for(int i=0;i<x;i++)
    {
        s[i].displayMarks();
    }
    cout<<"\n total number of Objects created = "<<student::count;
}