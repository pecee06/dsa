#include <iostream>
using namespace std;

int countSubarrays(int arr[], int n, int XOR)
{ // O(n^2)
    int count = 0, x;
    for (int i = 0; i < n; i++)
    {
        x = 0;
        for (int j = i; j < n; j++)
        {
            x = x ^ arr[j];
            if (x == XOR)
                count++;
        }
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