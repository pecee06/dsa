#include <iostream>
using namespace std;

int inversions(int arr[], int n)
{
    // O(n^2)
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                count++;
        }
    }
    return count;
}

int main()
{
    int arr[] = {5, 3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << inversions(arr, n);

    return 0;
}