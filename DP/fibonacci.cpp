#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

// Memoized Solution
/*
ll fib(int n)
{
    // T = O(n); S = O(n)
    // Returns nth term of fibonacci sequence
    static vector<ll> fibonacci(n, -1);
    if (n == 1 || n == 2)
        return n - 1;
    if (fibonacci[n - 1] != -1)
        return fibonacci[n - 1];
    fibonacci[n - 1] = fib(n - 1);
    fibonacci[n - 1] += fib(n - 2);
    return fibonacci[n - 1];
}
*/

// Tabulated Solution
/*
ll fib(int n)
{
    // T = O(n); S = O(n)
    vector<ll> fibonacci(n);
    fibonacci[0] = 0, fibonacci[1] = 1;
    for (int i = 3; i <= n; i++)
    {
        fibonacci[i - 1] = fibonacci[i - 2];
        fibonacci[i - 1] += fibonacci[i - 3];
    }
    return fibonacci[n - 1];
}
*/

// Space Optimized Solution
ll fib(int n)
{
    // O(n)
    if (n == 1 || n == 2)
        return n - 1;
    ll prev1 = 1, prev2 = 0, curr;
    for (int i = 3; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n);

    return 0;
}