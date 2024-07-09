#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define bigNum (int)1e5

vector<int> prepareSieve(int n)
{
    vector<int> sieve(n + 1, 1);
    sieve[0] = sieve[1] = 0;
    int upperLimit = sqrt(n);
    for (int i = 2; i <= upperLimit; i++)
    {
        for (int j = i * i; j <= n; j += i)
            sieve[j] = 0;
    }
    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        count += sieve[i];
        sieve[i] = count;
    }
    return sieve;
}

int countPrimes(int l, int r)
{
    auto sieve = prepareSieve(r);
    return sieve[r] - sieve[l];
}

int main()
{
    int l, r;
    cin >> l >> r;
    cout << countPrimes(l, r);

    return 0;
}
