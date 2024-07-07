#include <iostream>
#define INF (int)1e7
using namespace std;

void minMax(int arr[], int n, int &Min, int &Max)
{
    Min = Max = arr[0];
    for (int i = 1; i < n; i++)
    {
        Min = min(Min, arr[i]);
        Max = max(Max, arr[i]);
    }
}

int minTimeToPrepareBouquets(int bloomingTime[], int n, int bouquets, int flowers)
{
    if (bouquets * flowers > n)
        return -1;
    int low, high, ans = INF;
    minMax(bloomingTime, n, low, high); // O(n)
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int bloomedFlowers = 0, possibleBouquets = 0;
        for (int i = 0; i < n; i++)
        {
            if (mid < bloomingTime[i])
                bloomedFlowers = 0;
            else
                bloomedFlowers++;
            if (bloomedFlowers == flowers)
            {
                possibleBouquets++;
                bloomedFlowers = 0;
            }
        }
        if (possibleBouquets < bouquets)
            low = mid + 1;
        else
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
    int bloomingTime[] = {7, 7, 6, 7, 13, 11, 12, 7, 3};
    int n = sizeof(bloomingTime) / sizeof(bloomingTime[0]);
    int bouquets, flowers;
    cin >> bouquets >> flowers;
    cout << minTimeToPrepareBouquets(bloomingTime, n, bouquets, flowers);

    return 0;
}