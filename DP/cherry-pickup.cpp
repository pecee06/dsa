// 2 cherry pickers initially at (0,0) & (0,n-1) in a grid of m*n. They can only move down, either directly or diagonally left or diagonally right. Each cell has a certain number of cherries, once a picker reaches there, he/she picks it all leaving the place vacant. Find the max number of cherries both can collect together

#include <iostream>
#include <vector>
#define smallNum (int)(-1e7)
using namespace std;

typedef pair<int, int> PII;
typedef vector<vector<int>> Matrix;
typedef vector<Matrix> ThreeD;

// Memoized Solution
int helper(int x, int y1, int y2, Matrix &grid, int &R, int &C, ThreeD &dp)
{
    if (y1 < 0 || y2 < 0 || y1 >= C || y2 >= C)
        return smallNum;
    if (x == R - 1)
    {
        if (y1 == y2)
            return grid[x][y1];
        return (grid[x][y1] + grid[x][y2]);
    }
    if (dp[x][y1][y2] != -1)
        return dp[x][y1][y2];
    int ans = smallNum;
    for (int del1 = -1; del1 <= 1; del1++)
    {
        for (int del2 = -1; del2 <= 1; del2++)
        {
            int output = helper(x + 1, y1 + del1, y2 + del2, grid, R, C, dp);
            if (y1 == y2)
                output += grid[x][y1];
            else
                output += (grid[x][y1] + grid[x][y2]);
            ans = max(ans, output);
        }
    }
    return dp[x][y1][y2] = ans;
}
int maxCherries(Matrix &grid)
{
    // Write your code here.
    int m = grid.size(), n = grid[0].size();
    ThreeD dp(m, Matrix(n, vector<int>(n, -1)));
    return helper(0, 0, n - 1, grid, m, n, dp);
}

int main()
{
    Matrix grid = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}};
    cout << maxCherries(grid);

    return 0;
}