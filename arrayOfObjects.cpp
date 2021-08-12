//Memory allocation and array of object
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
{   int marks;
    student s[4];
    for(int i=0;i<4;i++)
    {
        cout<<"Enter Marks for Student no "<<i+1 <<" : ";
        cin>>marks;
        s[i].enterMarks(i,marks);
    }
    for(int i=0;i<4;i++)
    {
        s[i].displayMarks();
    }
    cout<<"\n total number of Objects created = "<<student::count;
}