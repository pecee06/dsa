#include <iostream>
#define INF (int)1e7
using namespace std;

inline int ceilDivision(int dividend, int divisor)
{
    return (dividend / divisor) + (dividend % divisor != 0);
}

int minBananaEatingRate(int piles[], int n, int h)
{
    int low = 1, high = piles[n - 1], rate = INF;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // checking whether mid as the rate would be sufficient
        bool timeExceeded = false;
        int hrsConsumed = 0;
        for (int i = 0; i < n; i++)
        {
            hrsConsumed += ceilDivision(piles[i], mid);
            if (hrsConsumed > h)
            {
                timeExceeded = true;
                low = mid + 1;
                break;
            }
        }
        if (!timeExceeded)
        {
            rate = min(rate, mid);
            high = mid - 1;
        }
    }
    if (rate == INF)
        return -1;
    return rate;
}

int main()
{
    int piles[] = {3, 6, 7, 11};
    int n = sizeof(piles) / sizeof(piles[0]);
    int h;
    cin >> h;
    cout << minBananaEatingRate(piles, n, h);

    return 0;
}