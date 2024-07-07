#include <iostream>
#define INF (int)1e7
using namespace std;

int minimum(int arr[], int n)
{
    int ans = INF;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        ans = min(ans, arr[mid]);
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
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans, arr[mid]);
            high = mid;
        }
    }
    return ans;
}

int main()
{
    // int arr[] = {4, 5, 6, 7, 0, 1, 2};
    // int arr[] = {6};
    int arr[] = {7, 8, 1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minimum(arr, n);

    return 0;
}