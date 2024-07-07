#include <iostream>
using namespace std;

int binarySearchRecursive(int key, int arr[], int from, int to)
{
    if (from > to)
        return -1;
    int mid = (from + to) / 2;
    if (key == arr[mid])
        return mid;
    if (key < arr[mid])
        return binarySearchRecursive(key, arr, from, mid);
    return binarySearchRecursive(key, arr, mid + 1, to);
}

int binarySearch(int key, int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (key == arr[mid])
            return mid;
        if (key < arr[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 2, 4, 10, 15, 15, 16, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    cin >> key;
    cout << binarySearchRecursive(key, arr, 0, n - 1) << endl;
    cout << binarySearch(key, arr, n);

    return 0;
}