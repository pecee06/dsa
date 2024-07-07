#include <iostream>
using namespace std;

int missingCount(int arr[], int index)
{
    return arr[index] - (index + 1);
}

int kthMissing(int arr[], int n, int k)
{
    if (!n)
        return k;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (missingCount(arr, mid) < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return k - missingCount(arr, high) + arr[high];
}

int main()
{
    // int arr[] = {2, 3, 4, 7, 11};
    int arr[] = {};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cin >> k;
    cout << kthMissing(arr, n, k);

    return 0;
}