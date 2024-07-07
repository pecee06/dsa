#include <iostream>
using namespace std;

bool continuous(int arr[], int index, int upperLimit)
{
    if (!upperLimit)
        return true;
    if (!index)
        return arr[index] <= arr[index + 1];
    if (index == upperLimit)
        return arr[index] >= arr[index - 1];
    return arr[index] >= arr[index - 1] && arr[index] <= arr[index + 1];
}

int timesRotated(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (!continuous(arr, mid, high))
            return mid + 1;
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            // trimming down the search space
            low++;
            high--;
            continue;
        }
        bool inSortedHalf = arr[low] <= arr[mid];
        if (inSortedHalf)
            low = mid + 1;
        else
            high = mid;
    }
    return 0;
}

int main()
{
    // int arr[] = {4, 5, 6, 7, 0, 1, 2};
    // int arr[] = {6};
    // int arr[] = {7, 8, 1, 2, 3, 4, 5};
    int arr[] = {1, 3, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << timesRotated(arr, n);

    return 0;
}