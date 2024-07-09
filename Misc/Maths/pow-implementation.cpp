#include <iostream>
using namespace std;

double power(int x, int n)
{ // O(log n)
    if (n < 0)
        return 1.0 / power(x, -n);
    if (!n)
        return 1;
    if (n == 1)
        return x;
    double ans = 1;
    if (n % 2)
    {
        ans *= x;
        ans *= power(x, n - 1);
    }
    else
        ans *= power(x * x, n / 2);
    return ans;
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << power(x, n);

    return 0;
}