#include <iostream>
#include <algorithm>
using namespace std;

int missingNumber(int arr[], int n)
{   // O(n)
    // Sol only works if array is sorted
    for (int i = 0; i < n - 1; i++)
        if (arr[i] != i + 1)
            return i + 1;
    return 0;
}

int main()
{
    int arr[] = {1, 2, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << missingNumber(arr, size + 1);

    return 0;
}