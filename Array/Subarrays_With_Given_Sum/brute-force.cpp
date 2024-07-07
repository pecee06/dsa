#include <iostream>
using namespace std;

int countSubarrays(int arr[], int n, int k)
{ // O(n^2)
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
                count++;
        }
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