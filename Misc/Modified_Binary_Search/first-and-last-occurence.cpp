#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

PII firstAndLastOccurence(int arr[], int n, int x)
{
    auto lb = lower_bound(arr, arr + n, x);
    if (lb == arr + n || arr[lb - arr] != x)
        return {-1, -1};
    auto ub = upper_bound(arr, arr + n, x);
    if (ub == arr + n)
        return {lb - arr, n - 1};
    return {lb - arr, ub - (arr + 1)};
}

int main()
{
    int arr[] = {2, 4, 6, 8, 8, 8, 11, 13, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    cin >> x;
    auto p = firstAndLastOccurence(arr, n, x);
    cout << p.first << "," << p.second;

    return 0;
}