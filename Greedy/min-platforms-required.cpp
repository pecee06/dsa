#include <iostream>
#include <algorithm>
using namespace std;

int minPlatformsRequired(int arrivals[], int departures[], int n)
{
    sort(departures, departures + n);
    int p1 = 0, p2 = 0, platform = 0, ans = 0;
    while (p1 < n && p2 < n)
    {
        if (arrivals[p1] < departures[p2])
        {
            p1++;
            platform++;
        }
        else if (arrivals[p1] > departures[p2])
        {
            p2++;
            platform--;
        }
        else
        {
            p1++;
            p2++;
            platform++;
        }
        ans = max(ans, platform);
    }
    return ans;
}

int main()
{
    int arrivals[] = {900, 945, 955, 1100, 1500, 1800}; // already sorted
    int n = sizeof(arrivals) / sizeof(arrivals[0]);
    int departures[] = {920, 1200, 1130, 1150, 1900, 2000};

    cout << minPlatformsRequired(arrivals, departures, n);

    return 0;
}