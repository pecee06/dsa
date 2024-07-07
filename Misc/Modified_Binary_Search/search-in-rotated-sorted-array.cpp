#include <iostream>
using namespace std;

int search(int key, int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (key == arr[mid])
            return mid;
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            // trimming down the search space
            low++;
            high--;
            continue;
        }
        bool inSortedHalf = arr[low] <= arr[mid];
        if (inSortedHalf)
        {
            if (key >= arr[low] && key < arr[mid])
                high = mid;
            else
                low = mid + 1;
        }
        else
        {
            if (key > arr[mid] && key <= arr[high])
                low = mid + 1;
            else
                high = mid;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {9, 1, 2, 9, 9, 9, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    cin >> key;
    cout << search(key, arr, n);

    return 0;
}