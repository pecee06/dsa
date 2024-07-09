#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

bool comparator(const PII &p1, const PII &p2)
{
    float q1 = p1.first / (float)p1.second;
    float q2 = p2.first / (float)p2.second;
    if (q1 == q2)
        return p1.first > p2.first;
    return q1 > q2;
}

float maxPossibleBusiness(vector<PII> items, int sackCapacity)
{
    sort(items.begin(), items.end(), comparator);
    float ans = 0;
    int i, n = items.size();
    for (i = 0; i < n; i++)
    {
        if (sackCapacity - items[i].second < 0)
            break;
        sackCapacity -= items[i].second;
        ans += items[i].first;
    }
    if (i < n)
        ans += (sackCapacity / (float)items[i].second) * items[i].first;
    return ans;
}

int main()
{
    vector<PII> items = {
        {100, 20},
        {60, 10},
        {100, 50},
        {200, 50}};
    // first -> value, second -> weight
    int sackCapacity;
    cin >> sackCapacity;
    cout << maxPossibleBusiness(items, sackCapacity);

    return 0;
}