#include <iostream>
#include <stdio.h>

using namespace std;

void binarySearch(int array[], int arraySize, int mid, int searchKey, int high, int low)
{
    if (array[mid] == searchKey)
    {
        cout << "Value Found : " << array[mid];
        return;
    }

    else if (array[mid] > searchKey)
    {
        high = mid;
        mid = ((high + low) / 2);
        if (high - low == 1)
        {
            cout << "\nValue not found";
            return;
        }
        binarySearch(array, arraySize, mid, searchKey, high, low);
    }
    else if (array[mid] < searchKey)
    {
        low = mid;
        mid = ((high + low) / 2);
        if (high - low == 1)
        {
            cout << "\nValue not found";
            return;
        }
        binarySearch(array, arraySize, mid, searchKey, high, low);
    }
}
int main()
{
    int arraySize, searchKey, navMenu;
    bool flag = false;
    cout << "No. of values in Array : ";
    cin >> arraySize;

    int *array = new int(arraySize);
    cout << "Enter Values: " << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cin >> array[i];
    }
    cout << "1. SEQUENTIAL SEARCH\n2. BINARY SEARCH "<<endl;
    cin >> navMenu;

    cout << "Enter the Number to Find : ";
    cin >> searchKey;
    if (navMenu == 1)
    {

        ///////////////////SEQUENTIAL SEING//////////////////////////////

        for (int i = 0; i < arraySize; i++)

            {
                if (searchKey == array[i])
                {
                    cout << "Key present : " << searchKey;
                    flag = true;
                    break;
                }
            }
        if (flag == false)
        {
            cout << "No data Present " << endl;
        }
    }
    else if (navMenu == 2)
    {
        ////////////////////BINARY SEARCH//////////////////////////////////////
        int low = 0, high;
        high = --arraySize;
        int mid = ((arraySize - 1) / 2);
        binarySearch(array, arraySize, mid, searchKey, high, low);
    }
}