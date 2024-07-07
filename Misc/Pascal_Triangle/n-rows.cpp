#include <iostream>
#include <vector>
using namespace std;

void prepareTable(vector<long long> &factorials, int n)
{
    factorials.push_back(0);
    long long mul = 1;
    for (int i = 1; i <= n; i++)
    {
        mul *= i;
        factorials.push_back(mul);
    }
}

int nCr(int n, int r, vector<long long> &factorials)
{
    if (r == 0 || n == r)
        return 1;
    return factorials[n] / (factorials[n - r] * factorials[r]);
}

void nthRow(int n)
{ // T = O(n^2); S = O(n)
    vector<long long> factorials;
    prepareTable(factorials, n - 1);
    for (int i = 1; i <= n; i++)
    {
        for (int r = 0; r < i; r++)
            cout << nCr(i - 1, r, factorials) << " ";
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    nthRow(n);

    return 0;
}