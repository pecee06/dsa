#include <iostream>
#include <climits>
using namespace std;

int maxProductSubarray(int arr[], int n)
{ // O(n)
    int maxPrefixProd = INT_MIN, maxSuffixProd = INT_MIN;
    int m1 = 1, m2 = 1;
    for (int i = 0; i < n; i++)
    {
        m1 *= arr[i];
        m2 *= arr[n - 1 - i];
        maxPrefixProd = max(maxPrefixProd, m1);
        maxSuffixProd = max(maxSuffixProd, m2);
        if (!m1)
            m1 = 1;
        if (!m2)
            m2 = 1;
    }
    return max(maxPrefixProd, maxSuffixProd);
}

int main()
{
    int arr[] = {2, 3, -2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxProductSubarray(arr, n);

    return 0;
}