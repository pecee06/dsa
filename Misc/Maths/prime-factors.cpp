#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;

unordered_set<int> primeFactors(int n)
{ // O(sqrt(n))
    unordered_set<int> ans;
    for (int i = 2; i <= sqrt(n); i++)
    {
        while (!(n % i))
        {
            ans.insert(i);
            n /= i;
        }
    }
    if (n != 1)
        ans.insert(n);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    auto d = primeFactors(n);
    for (auto it : d)
        cout << it << " ";

    return 0;
}