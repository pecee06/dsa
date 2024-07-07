#include <iostream>
#include <climits>
using namespace std;

int maxProductSubarray(int arr[], int n)
{ // O(n^2)
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int prod = 1;
        for (int j = i; j < n; j++)
        {
            prod *= arr[j];
            ans = max(ans, prod);
        }
    }
    return ans;
}

int main()
{
    int arr[] = {2, 3, -2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxProductSubarray(arr, n);

    return 0;
}