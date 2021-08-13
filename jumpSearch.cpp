#include <iostream>
#include <stdio.h>

using namespace std;
void jumpSearch(int array[], int arraySize, int findNumber, int front, int last)
{
    if (findNumber == array[front] || findNumber == array[last])
      {
        cout << "Found";
        return;  
      }  
    else if (findNumber > array[front] && findNumber < array[last])
    {
        front++;
        last--;
        jumpSearch(array, arraySize, findNumber, front, last);
        return;

    }
    else if (findNumber>array[last])
    {
        front = front + 3;
        last = last + 3;
        jumpSearch(array, arraySize, findNumber, front, last);
        
    }
    else if ((front-last)== 1 && findNumber > array[front] || findNumber < array[last])
    {
       cout<<"Value Not Found ";
       return;
    }
}
void printArray(int array[],int arraySize)
{
    for(int i=0;i<arraySize;i++)
    {
        cout<<" "<<array[i];
    }
}
int main()
{
    int array[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 120};

    int arraySize = sizeof(array) / sizeof(array[0]);
    int front = 0, last =3, findNumber=0;
    cout << "Enter number to find : ";
    cin >> findNumber;
    jumpSearch(array, arraySize, findNumber, front, last);
    printArray(array,arraySize);
}