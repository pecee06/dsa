#include <iostream>
#include <vector>
using namespace std;

// Memoized Solution
/*
int maxNonAdjacentSum(int arr[], int index)
{
    // Subsequence can't have adjacent elements
    static vector<int> dp(index + 1, -1);
    if (index < 0)
        return 0;
    if (!index)
        return dp[0] = arr[0];
    if (dp[index] != -1)
        return dp[index];
    int pick = arr[index] + maxNonAdjacentSum(arr, index - 2);
    int notPick = maxNonAdjacentSum(arr, index - 1);
    return dp[index] = max(pick, notPick);
}
*/

// Tabulated Solution
/*
int maxNonAdjacentSum(int arr[], int n)
{
    // Subsequence can't have adjacent elements
    vector<int> dp(n, -1);
    dp[0] = arr[0];
    int pick, notPick = 0;
    for (int i = 1; i < n; i++)
    {
        pick = arr[i];
        if (i > 1)
            pick += dp[i - 2];
        notPick = dp[i - 1];
        dp[i] = max(pick, notPick);
    }
    return dp[n - 1];
}
*/

// Space Optimized Solution
int maxNonAdjacentSum(int arr[], int n)
{
    // Subsequence can't have adjacent elements
    int pick, notPick = 0, prev1 = arr[0], prev2;
    for (int i = 1; i < n; i++)
    {
        pick = arr[i];
        if (i > 1)
            pick += prev2;
        notPick = prev1;
        prev2 = prev1;
        prev1 = max(pick, notPick);
    }
    return prev1;
}

int main()
{
    int arr[] = {4, 0, 8, 1, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxNonAdjacentSum(arr, n);

    return 0;
}