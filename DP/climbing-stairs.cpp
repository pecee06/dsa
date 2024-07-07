#include <iostream>
#include <vector>
using namespace std;

// Memoized Solution
/*
int waysToClimb(int stairs)
{
    static vector<int> ways(stairs + 1, -1);
    if (!stairs || stairs == 1)
        return 1;
    if (ways[stairs] != -1)
        return ways[stairs];
    return ways[stairs] = waysToClimb(stairs - 1) + waysToClimb(stairs - 2);
}
*/

// Tabulated Solution
/*
int waysToClimb(int stairs)
{
    vector<int> ways(stairs + 1);
    ways[0] = 1, ways[1] = 1;
    for (int i = 2; i <= stairs; i++)
        ways[i] = ways[i - 1] + ways[i - 2];
    return ways[stairs];
}
*/

// Space Optimized Solution
int waysToClimb(int stairs)
{
    if (!stairs || stairs == 1)
        return 1;
    int prev1 = 1, prev2 = 1, curr;
    for (int i = 2; i <= stairs; i++)
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
    cout << waysToClimb(n);

    return 0;
}