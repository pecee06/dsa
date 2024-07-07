#include <iostream>
#include <algorithm>
#include <numeric>
#define INF (int)1e7
using namespace std;

int minTimeToPaint(int widths[], int n, int painters)
{
    int low = *max_element(widths, widths + n);
    int high = accumulate(widths, widths + n, 0);
    int ans = INF;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        bool paintersExceeded = false;
        int requiredPainters = 1, val = 0;
        for (int i = 0; i < n; i++)
        {
            val += widths[i];
            if (val > mid)
            {
                requiredPainters++;
                val = widths[i];
            }
            if (requiredPainters > painters)
            {
                low = mid + 1;
                paintersExceeded = true;
                break;
            }
        }
        if (!paintersExceeded)
        {
            if (requiredPainters == painters)
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
    int widths[] = {10, 20, 30, 40};
    // widths[i] represent width if ith wall
    // each unit width of wall takes unit time to paint
    int n = sizeof(widths) / sizeof(widths[0]);
    int painters;
    cin >> painters;
    cout << minTimeToPaint(widths, n, painters);

    return 0;
}