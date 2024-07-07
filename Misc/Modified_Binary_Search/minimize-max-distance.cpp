#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Interval
{
    int start;
    int length;
    int elements;
};

class Compare
{
public:
    bool operator()(const Interval &a, const Interval &b) const
    {
        // Define comparison based on elements for max-heap
        return (double)a.length / (a.elements + 1) < (double)b.length / (b.elements + 1);
    }
};

double minimiseMaxDistance(vector<int> &arr, int k)
{
    // Write your code here.
    priority_queue<Interval, vector<Interval>, Compare> maxHeap;
    int n = arr.size();
    for (int i = 1; i < n; i++)
        maxHeap.push({i - 1, arr[i] - arr[i - 1], 0});
    for (int i = 0; i < k; i++)
    {
        auto interval = maxHeap.top();
        maxHeap.pop();
        maxHeap.push({interval.start, interval.length, interval.elements + 1});
    }
    double ans = 0.0;
    while (!maxHeap.empty())
    {
        auto interval = maxHeap.top();
        maxHeap.pop();
        ans = max(ans, (double)interval.length / (double)(interval.elements + 1));
    }
    return ans;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    int k;
    cin >> k;
    cout << minimiseMaxDistance(v, k);

    return 0;
}
