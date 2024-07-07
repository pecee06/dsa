#include <iostream>
#include <array>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

typedef array<int, 4> Quad;

set<Quad> fourSum(int arr[], int n)
{ // T = O(n^3); S = O(n)
    set<Quad> ans;
    unordered_set<int> hash;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            hash.clear();
            for (int k = j + 1; k < n; k++)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (hash.count(-sum))
                {
                    Quad q = {arr[i], arr[j], arr[k], -sum};
                    sort(q.begin(), q.end());
                    ans.insert(q);
                }
                hash.insert(arr[k]);
            }
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, -1, -2, 2, 0, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    auto quads = fourSum(arr, n);
    for (auto it : quads)
        cout << it[0] << "," << it[1] << "," << it[2] << "," << it[3] << endl;

    return 0;
}