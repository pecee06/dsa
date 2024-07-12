#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>
#define bigNum (int)1e7
using namespace std;

int minSubsetSumDifference(vector<int> &arr)
{
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<int>> dp(n, vector<int>(sum + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (arr[0] <= sum)
        dp[0][arr[0]] = true;
    for (int row = 1; row < n; row++)
    {
        for (int col = 1; col <= sum; col++)
        {
            bool pick = (col >= arr[row]) ? dp[row - 1][col - arr[row]] : false;
            bool notPick = dp[row - 1][col];
            dp[row][col] = (pick || notPick);
        }
    }
    int ans = bigNum;
    for (int i = 0; i <= sum; i++)
    {
        if (dp[n - 1][i])
            ans = min(ans, abs(2 * i - sum));
    }
    return ans;
}

int main()
{
    vector<int> arr = {13, 10, 1, 8, 9, 3, 16};
    cout << minSubsetSumDifference(arr);

    return 0;
}