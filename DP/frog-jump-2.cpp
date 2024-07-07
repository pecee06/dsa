#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define INF (int)1e7
using namespace std;

inline int energyConsumption(vector<int> &heights, int from, int to)
{
    return abs(heights[to] - heights[from]);
}

// Memoized Solution
/*
int minEnergyConsumption(vector<int> &heights, int &k, int curr = 0)
{
    static vector<int> dp(heights.size(), -1), jumps(k, INF);
    if (curr == heights.size() - 1)
        return 0;
    if (dp[curr] != -1)
        return dp[curr];
    for (int i = 0; i < k; i++)
    {
        if (curr + i + 1 < heights.size())
            jumps[i] = energyConsumption(heights, curr, curr + i + 1) + minEnergyConsumption(heights, k, curr + i + 1);
    }
    return dp[curr] = *min_element(jumps.begin(), jumps.end());
}
*/

// Tabulated Solution
int minEnergyConsumption(vector<int> &heights, int &k)
{
    vector<int> dp(heights.size()), jumps(k, INF);
    int init = heights.size() - 1;
    dp[init] = 0;
    int jump1, jump2;
    for (int i = init - 1; i >= 0; i--)
    {
        for (int j = 0; j < k; j++)
        {
            if (i + j + 1 <= init)
                jumps[j] = dp[i + j + 1] + energyConsumption(heights, i, i + j + 1);
        }
        dp[i] = *min_element(jumps.begin(), jumps.end());
    }
    return dp[0];
}

int main()
{
    // vector<int> heights = {10, 20, 30, 10};
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    int k;
    cin >> k;
    cout << minEnergyConsumption(heights, k);

    return 0;
}