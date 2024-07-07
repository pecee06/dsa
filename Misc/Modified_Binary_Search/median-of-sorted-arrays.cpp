#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef pair<vector<int>, vector<int>> PVV;

float median(PVV &p)
{
    // ensure 1st vector is always the smaller one
    if (p.first.size() > p.second.size())
        swap(p.first, p.second);
    int n = p.first.size() + p.second.size();
    int sizeOfFirstSubarray = (n + 1) / 2;
    int low = 0, high = p.first.size();
    while (low <= high)
    {
        int mid1 = (low + high) / 2;           // no of elements getting picked from 1st array in left half
        int mid2 = sizeOfFirstSubarray - mid1; // no of elements getting picked from 2nd array in left half

        int l1, l2, r1, r2;
        l1 = l2 = INT_MIN;
        r1 = r2 = INT_MAX;
        if (mid1 < p.first.size())
            r1 = p.first[mid1];
        if (mid2 < p.second.size())
            r2 = p.second[mid2];
        if (mid1 >= 1)
            l1 = p.first[mid1 - 1];
        if (mid2 >= 1)
            l2 = p.second[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2)
                return max(l1, l2);
            return (float)(max(l1, l2) + min(r1, r2)) / 2.0;
        }
        if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return -1;
}

int main()
{
    vector<PVV> testCases = {
        {{7, 12, 14, 15},
         {1, 2, 3, 4, 9, 11}},
        {{4, 5, 8, 8, 10, 11}, {2, 3, 7}}};
    for (auto it : testCases)
        cout << median(it) << " ";

    return 0;
}