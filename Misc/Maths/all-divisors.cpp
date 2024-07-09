#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;

unordered_set<int> divisors(int n)
{ // O(sqrt(n))
    unordered_set<int> ans;
    int upperLimit = sqrt(n);
    for (int i = 1; i <= upperLimit; i++)
    {
        if (!(n % i))
        {
            ans.insert(i);
            ans.insert(n / i);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    auto d = divisors(n);
    for (auto it : d)
        cout << it << " ";

    return 0;
}