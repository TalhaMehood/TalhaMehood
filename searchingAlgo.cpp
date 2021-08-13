#include<iostream>
#include<stdio.h>

using namespace std;
  

string search(int array[], int sizeArray, int x)
{
    // 1st comparison
    if (array[sizeArray - 1] == x)
        return "Found";
  
    int backup = array[sizeArray - 1];
    array[sizeArray - 1] = x;
  
    // no termination condition and thus
    // no comparison
    for (int i = 0;; i++) {
        // this would be executed at-most n times
        // and therefore at-most n comparisons
        if (array[i] == x) {
            // replace array[n-1] with its actual element
            // as in original 'array[]'
            array[sizeArray - 1] = backup;
  
            // if 'x' is found before the '(n-1)th'
            // index, then it is present in the arrayay
            // final comparison
            if (i < sizeArray - 1)
                return "Found";
  
            // else not present in the arrayay
            return "Not Found";
        }
    }
}
  
int main()
{
    int array[] = { 4, 6, 1, 5, 8 };
    int sizeArray = sizeof(array) / sizeof(array[0]);
    int x = 1;
    cout << search(array, sizeArray, x);
    return 0;
}