#include <iostream>
using namespace std;

int intSqrt(int x)
{
    int low = 1, high = x, ans = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int squaredVal = mid * mid;
        if (squaredVal > x)
            high = mid - 1;
        else
        {
            ans = max(ans, mid);
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int x;
    cin >> x;
    cout << intSqrt(x);

    return 0;
}