#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;
typedef vector<PII> VP;

bool comparator(const PII &p1, const PII &p2)
{
    int duration1 = p1.second - p1.first;
    int duration2 = p2.second - p2.first;
    if (duration1 == duration2)
        return p1.first < p2.first;
    return duration1 > duration2;
}

int minRemovalsRequired(VP &intervals)
{
    sort(intervals.begin(), intervals.end(), comparator);
    int count = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i].first < intervals[i - 1].second)
            count++;
    }
    return count;
}

int main()
{
    VP intervals = {
        {0, 5},
        {3, 4},
        {1, 2},
        {5, 9},
        {5, 7},
        {7, 9},
    };
    cout << minRemovalsRequired(intervals);

    return 0;
}