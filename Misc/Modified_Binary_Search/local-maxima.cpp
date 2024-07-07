#include <iostream>
#include <vector>
using namespace std;

bool isPeakElem(vector<int> &v, int index, int upperLimit)
{
    if (!upperLimit)
        return true;
    if (!index)
        return v[index] > v[index + 1];
    if (index == upperLimit)
        return v[index] > v[index - 1];
    return v[index] > v[index + 1] && v[index] > v[index - 1];
}

bool slope(vector<int> &v, int index, int upperLimit)
{
    // 0 -> -ve slope, 1 -> +ve slope
    if (!index)
        return v[index] < v[index + 1];
    if (index == upperLimit)
        return v[index] > v[index - 1];
    return v[index] < v[index + 1] && v[index] > v[index - 1];
}

int peak(vector<int> &v)
{
    int low = 0, high = v.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isPeakElem(v, mid, high))
            return mid;
        if (slope(v, mid, high))
        {
            // in +ve slope
            low = mid + 1;
        }
        else
        {
            // in -ve slope
            high = mid;
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> m = {
        {1, 2, 3, 4, 5, 6, 7, 8, 5, 1},
        {1, 2, 1, 3, 5, 6, 4},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {2, 2, 2},
        {},
        {10}};

    for (auto v : m)
    {
        int p = peak(v);
        if (p == -1)
            cout << "NA\n";
        else
            cout << v[p] << endl;
    }

    return 0;
}