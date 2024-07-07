#include <iostream>
#include <algorithm>
#define INF (int)1e7
using namespace std;

inline int ceilDivision(int dividend, int divisor)
{
    return (dividend / divisor) + (dividend % divisor != 0);
}

int smallestDivisor(int arr[], int n, int threshold)
{
    int low = 1, high = *max_element(arr, arr + n), ans = INF;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        bool valueExceeded = false;
        int val = 0;
        for (int i = 0; i < n; i++)
        {
            val += ceilDivision(arr[i], mid);
            if (val > threshold)
            {
                valueExceeded = true;
                low = mid + 1;
                break;
            }
        }
        if (!valueExceeded)
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
    }
    if (ans == INF)
        return -1;
    return ans;
}

int main()
{
    int arr[] = {1, 2, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int threshold;
    cin >> threshold;
    cout << smallestDivisor(arr, n, threshold);

    return 0;
}