#include <iostream>
#include <unordered_map>
using namespace std;

int countSubarrays(int arr[], int n, int XOR)
{
    // T = O(n); S = O(n)
    unordered_map<int, int> prefixXor;
    prefixXor[0] = 1;
    int count = 0, x = 0;
    for (int i = 0; i < n; i++)
    {
        x = x ^ arr[i];
        count += prefixXor[x ^ XOR];
        prefixXor[x]++;
    }
    return count;
}

int main()
{
    int arr[] = {4, 2, 2, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int XOR;
    cin >> XOR;
    cout << countSubarrays(arr, n, XOR);

    return 0;
}