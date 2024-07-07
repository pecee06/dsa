#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<pair<int, int>> VectorOfPairs;
#define garbage (int)(-1e5)

vector<int> mergeIntervals(VectorOfPairs &v)
{
    vector<int> intervals;
    set<int> s;
    for (auto it : v)
    {
        for (int i = it.first; i <= it.second; i++)
            s.insert(i);
    }
    int lastDeleted = garbage;
    for (auto it = s.begin(); it != s.end(); it = s.erase(it))
    {
        if (*it - lastDeleted != 1)
        {
            if (lastDeleted != garbage)
                intervals.push_back(lastDeleted);
            intervals.push_back(*it);
        }
        lastDeleted = *it;
    }
    intervals.push_back(lastDeleted);
    return intervals;
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
    for (int i = 0; i < intervals.size(); i++)
    {
        if (i % 2)
            cout << intervals[i] << endl;
        else
            cout << intervals[i] << ",";
    }

    return 0;
}