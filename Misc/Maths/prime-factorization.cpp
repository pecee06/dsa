#include <iostream>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> spf(int n)
{
    vector<int> sieve(n + 1);
    iota(sieve.begin(), sieve.end(), 0);
    sieve[0] = sieve[1] = -1;
    int upperLimit = sqrt(n);
    for (int i = 2; i <= upperLimit; i++)
    {
        for (int j = i * i; j <= n; j += i)
        {
            if (sieve[j] == j)
                sieve[j] = i;
        }
    }
    return sieve;
}

void primeFactorization(vector<int> &inputs)
{
    int Max = *max_element(inputs.begin(), inputs.end());
    auto sieve = spf(Max);
    for (auto it : inputs)
    {
        while (it != 1)
        {
            cout << sieve[it] << " ";
            it /= sieve[it];
        }
        cout << endl;
    }
}

int main()
{
    vector<int> inputs = {8, 2, 6, 100, 406, 37, 18, 64};
    primeFactorization(inputs);

    return 0;
}