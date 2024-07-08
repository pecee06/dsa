#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> PII;
typedef vector<PII> VP;

VP insertInterval(VP &intervals, PII &interval)
{
    VP mergedIntervals;
    int i = 0, n = intervals.size();
    // 1st part
    while (i < n && intervals[i].second < interval.first)
        mergedIntervals.push_back(intervals[i++]);
    // 2nd part (to be merged)
    while (i < n && intervals[i].first <= interval.second)
    {
        interval.first = min(interval.first, intervals[i].first);
        interval.second = max(interval.second, intervals[i].second);
        i++;
    }
    mergedIntervals.push_back(interval);
    // 3rd part
    while (i < n)
        mergedIntervals.push_back(intervals[i++]);
    return mergedIntervals;
}

int main()
{
    VP intervals = {
        {1, 2},
        {3, 4},
        {5, 7},
        {8, 10},
        {12, 16}};

    PII interval = {5, 8};
    intervals = insertInterval(intervals, interval);
    for (auto it : intervals)
        cout << it.first << "," << it.second << endl;

    return 0;
}
