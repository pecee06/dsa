#include <iostream>
using namespace std;

int nCr(int n, int r)
{
    int iterations = min(n, n - r);
    long long ans = 1;
    for (int i = 0; i < iterations; i++)
    {
        ans *= (n - i);
        ans /= i + 1;
    }
    return ans;
}

int main()
{
    int row, elem;
    cin >> row >> elem;
    cout << nCr(row - 1, elem - 1);

    return 0;
}