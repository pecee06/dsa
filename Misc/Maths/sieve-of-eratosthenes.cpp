#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define bigNum (int)1e5

vector<bool> prepareSieve(int n)
{
    // O(n log(log n))
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;
    int upperLimit = sqrt(n);
    for (int i = 2; i <= upperLimit; i++)
    {
        for (int j = i * i; j <= n; j += i)
            sieve[j] = false;
    }
    return sieve;
}

int main()
{
    auto sieve = prepareSieve(bigNum);
    int x;
    do
    {
        cin >> x;
        if (x >= 0)
            cout << sieve[x] << endl;
    } while (x >= 0);

    return 0;
}