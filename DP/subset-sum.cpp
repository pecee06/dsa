#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

bool helper(int to, int k, vector<int> &arr, Matrix &dp)
{
    if (!k)
        return true;
    if (!to)
        return arr[0] == k;
    if (to < 0 || k < 0)
        return false;
    if (dp[to][k] != -1)
        return dp[to][k];
    bool pick = helper(to - 1, k - arr[to], arr, dp);
    bool notPick = helper(to - 1, k, arr, dp);
    return dp[to][k] = (pick || notPick);
}

bool subsetSumToK(int k, vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    Matrix dp(n, vector<int>(k + 1, -1));
    return helper(n - 1, k, arr, dp);
}

int main()
{
    // vector<int> arr = {29, 26, 2, 6, 69, 65, 37, 13, 88, 45, 14, 48, 51, 91, 39, 92, 74, 29, 67, 64};
    vector<int> arr = {1, 1, 1, 1};

    // int k = 183;
    int k = 4;
    cout << subsetSumToK(k, arr);

    return 0;
}