#include <iostream>
#include <algorithm>
using namespace std;

int maxSeparation(int stableCoordinates[], int n, int cows)
{
    // separation is the min distance between any 2 cows
    sort(stableCoordinates, stableCoordinates + n);
    int low = stableCoordinates[0], high = stableCoordinates[n - 1], ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // check whether mid as the min distance be maintained among cows
        bool cantBeAccomodated = true;
        int cowsAccomodated = 1, lastCowIndex = 0;
        for (int i = 1; i < n; i++)
        {
            if (stableCoordinates[i] - stableCoordinates[lastCowIndex] >= mid)
            {
                cowsAccomodated++;
                lastCowIndex = i;
            }
            if (cowsAccomodated >= cows)
            {
                ans = max(ans, mid);
                low = mid + 1;
                cantBeAccomodated = false;
                break;
            }
        }
        if (cantBeAccomodated)
            high = mid - 1;
    }
    return ans;
}

int main()
{
    // origin's a pole at (0,0)
    int stableCoordinates[] = {4, 3, 1, 7, 10, 9};
    // 0th stable at (4,0), 1st stable at (3,0) and so on...
    int n = sizeof(stableCoordinates) / sizeof(stableCoordinates[0]);
    int cows; // min = 2
    cin >> cows;
    cout << maxSeparation(stableCoordinates, n, cows);

    return 0;
}