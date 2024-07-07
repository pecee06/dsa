// Lower bound is the min index of a sorted array such that arr[lower_bound] >= x (x can be any value)
// Upper bound on the other hand is the min index of a sorted array such that arr[upper_bound] > x

#include <iostream>
using namespace std;

int lowerBound(int arr[], int n, int x)
{
    int low = 0, high = n - 1, index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < x)
            low = mid + 1;
        else
        {
            index = mid;
            high = mid - 1;
        }
    }
    return index;
}

int main()
{
    // int arr[] = {3, 5, 8, 15, 19};
    int arr[] = {3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    cin >> x;
    cout << lowerBound(arr, n, x);

    return 0;
}