#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

inline int energyConsumption(vector<int> &heights, int from, int to)
{
    return abs(heights[to] - heights[from]);
}

// Memoized Solution
/*
int minEnergyConsumption(vector<int> &heights, int curr = 0)
{
    static vector<int> dp(heights.size(), -1);
    if (curr == heights.size() - 1)
        return 0;
    if (dp[curr] != -1)
        return dp[curr];
    int jump1 = energyConsumption(heights, curr, curr + 1) + minEnergyConsumption(heights, curr + 1), jump2;
    if (curr + 2 < heights.size())
        jump2 = energyConsumption(heights, curr, curr + 2) + minEnergyConsumption(heights, curr + 2);
    else
        jump2 = jump1;
    return dp[curr] = min(jump1, jump2);
}
*/

// Tabulated Solution
/*
int minEnergyConsumption(vector<int> &heights)
{
    vector<int> dp(heights.size());
    int init = heights.size() - 1;
    dp[init] = 0;
    int jump1, jump2;
    for (int i = init - 1; i >= 0; i--)
    {
        jump1 = dp[i + 1] + energyConsumption(heights, i, i + 1);
        if (i < init - 1)
            jump2 = dp[i + 2] + energyConsumption(heights, i, i + 2);
        else
            jump2 = jump1;
        dp[i] = min(jump1, jump2);
    }
    return dp[0];
}
*/

// Space Optimized Solution
int minEnergyConsumption(vector<int> &heights)
{
    int init = heights.size() - 1;
    int jump1, jump2, next1 = 0, next2;
    for (int i = init - 1; i >= 0; i--)
    {
        jump1 = next1 + energyConsumption(heights, i, i + 1);
        if (i < init - 1)
            jump2 = next2 + energyConsumption(heights, i, i + 2);
        else
            jump2 = jump1;
        next2 = next1;
        next1 = min(jump1, jump2);
    }
    return next1;
}

int main()
{
    // vector<int> heights = {10, 20, 30, 10};
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    cout << minEnergyConsumption(heights);

    return 0;
}