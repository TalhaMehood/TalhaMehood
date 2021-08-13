#include <iostream>
#include <stdio.h>

using namespace std;

void bubbleSort(int array[], int arraySize)
{
    for (int i = 0; i <= arraySize; i++)
    {
        for (int j = 0; j <= arraySize - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void printArray(int array[], int size)
{

    for (int i = 1; i <= size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    int arraySize;

    cout << "Enter the Size of Array : " << endl;
    cin >> arraySize;

    int *array = new int(arraySize);

    for (int i = 0; i < arraySize; i++)
    {
        cin >> array[i];
    }

    bubbleSort(array, arraySize);
    cout << "Sorted array: "<<endl;
    printArray(array, arraySize);
    return 0;
}