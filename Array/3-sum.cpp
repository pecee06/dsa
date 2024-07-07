#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct Node
{
    int first, second, third;
} Triplet;

vector<Triplet> threeSum(int arr[], int n)
{ // O(n^2)
    vector<Triplet> ans;
    sort(arr, arr + n);
    int mid, right, sum;
    for (int left = 0; left < n; left++)
    {
        if (left && arr[left] == arr[left - 1])
            continue;
        mid = left + 1;
        right = n - 1;
        while (mid < right)
        {
            sum = arr[left] + arr[mid] + arr[right];
            if (sum < 0)
                mid++;
            else if (sum > 0)
                right--;
            else
            {
                ans.push_back({arr[left], arr[mid], arr[right]});
                mid++;
                right--;
                while (mid < right && arr[mid] == arr[mid - 1])
                    mid++;
                while (right > mid && arr[right] == arr[right + 1])
                    right--;
            }
        }
    }
    return ans;
}

int main()
{
    int arr[] = {2, 2, 0, -1, 1, 0, 0, -1, 2, -2, -2, -1, -2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    auto triplets = threeSum(arr, n);
    for (auto it : triplets)
        cout << it.first << "," << it.second << "," << it.third << endl;

    return 0;
}