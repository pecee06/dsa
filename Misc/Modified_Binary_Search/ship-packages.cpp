#include <iostream>
#include <algorithm>
#include <numeric>
#define INF (int)1e7
using namespace std;

int minShipCapacity(int weights[], int n, int days)
{
    int low = *max_element(weights, weights + n);
    int high = accumulate(weights, weights + n, 0);
    int ans = INF;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int daysReq = 1, val = 0;
        bool lowCapacity = false;
        for (int i = 0; i < n; i++)
        {
            if (val + weights[i] > mid)
            {
                daysReq++;
                val = weights[i];
            }
            else
                val += weights[i];
            if (daysReq > days)
            {
                low = mid + 1;
                lowCapacity = true;
                break;
            }
        }
        if (!lowCapacity)
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
    }
    if (ans == INF)
        return -1;
    return ans;
}

int main()
{
    int weights[] = {8, 6, 10, 4, 1, 5, 3, 2, 7, 9};
    int n = sizeof(weights) / sizeof(weights[0]);
    int days;
    cin >> days;
    cout << minShipCapacity(weights, n, days);

    return 0;
}