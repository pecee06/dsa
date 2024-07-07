#include <iostream>
using namespace std;

int nthRoot(int x, int n)
{
    int low = 1, high = x, ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        long val = 1;
        bool valExceeded = false;
        for (int i = 0; i < n; i++)
        {
            val *= mid;
            if (val > x)
            {
                high = mid - 1;
                valExceeded = true;
                break;
            }
        }
        if (!valExceeded)
        {
            ans = max(ans, mid);
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << nthRoot(x, n);

    return 0;
}