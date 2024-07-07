#include <iostream>
#include <unordered_map>
using namespace std;

void majorElements(int arr[], int n)
{
    // T = O(n); S = O(n)
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;
    for (auto it : freq)
    {
        if (it.second > n / 3)
            cout << it.first << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 1, 1, 3, 3, 2, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    majorElements(arr, n);

    return 0;
}