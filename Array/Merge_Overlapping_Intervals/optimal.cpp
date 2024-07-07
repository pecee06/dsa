#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<pair<int, int>> VectorOfPairs;

VectorOfPairs mergeIntervals(VectorOfPairs &v)
{ // O(n logn)
    VectorOfPairs ans;
    sort(v.begin(), v.end());
    auto currentInterval = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].first <= currentInterval.second)
            currentInterval.second = max(currentInterval.second, v[i].second);
        else
        {
            ans.push_back(currentInterval);
            currentInterval = {v[i].first, v[i].second};
        }
    }
    ans.push_back(currentInterval);
    return ans;
}

int main()
{
    VectorOfPairs v = {
        {1, 3},
        {2, 6},
        {8, 9},
        {9, 11},
        {8, 10},
        {2, 4},
        {15, 18},
        {16, 17},
    };
    auto intervals = mergeIntervals(v);
    for (auto it : intervals)
        cout << it.first << "," << it.second << endl;

    return 0;
}