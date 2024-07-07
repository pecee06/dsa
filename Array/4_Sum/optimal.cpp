#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

typedef array<int, 4> Quad;

vector<Quad> fourSum(int arr[], int n)
{ // O(n^3)
    vector<Quad> ans;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (i && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j != i + 1 && arr[j] == arr[j - 1])
                continue;
            int k = j + 1, l = n - 1;
            while (k < l)
            {
                int sum = arr[i] + arr[j] + arr[k] + arr[l];
                if (sum < 0)
                    k++;
                else if (sum > 0)
                    l--;
                else
                {
                    ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;
                    while (k < l && arr[k] == arr[k - 1])
                        k++;
                    while (l > k && arr[l] == arr[l + 1])
                        l--;
                }
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