#include <iostream>
#include <unordered_map>
using namespace std;

int countSubarrays(int arr[], int n, int k)
{ // T = O(n); S = O(n)
    unordered_map<int, int> prefixSum;
    prefixSum[0] = 1;
    int sum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        count += prefixSum[sum - k];
        prefixSum[sum]++;
    }
    return count;
}

int main()
{
    int arr[] = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cin >> k;
    cout << countSubarrays(arr, n, k);
    return 0;
}