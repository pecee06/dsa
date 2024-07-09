// Given a matrix "points" which stores n rows of points for 3 tasks. Ninja can only do 1 task per day. For best outcomes, ninja has to maximize the training points but can't do the same tasks on alternate days. Find the maximum points ninja can earn

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

// Memoized Solution
/*
int helper(int currentDay, int lastTask, Matrix &points, Matrix &dp)
{
    if (dp[currentDay][lastTask] != -1)
        return dp[currentDay][lastTask];
    int ans = 0;
    if (!currentDay)
    {
        for (int i = 0; i < 3; i++)
        {
            if (i == lastTask)
                continue;
            ans = max(ans, points[currentDay][i]);
        }
        return dp[currentDay][lastTask] = ans;
    }
    for (int i = 0; i < 3; i++)
    {
        if (i == lastTask)
            continue;
        ans = max(ans, points[currentDay][i] + helper(currentDay - 1, i, points, dp));
    }
    return dp[currentDay][lastTask] = ans;
}
*/

// Tabulated Solution
/*
int maxPoints(Matrix &points)
{
    int n = points.size();
    Matrix dp(n, vector<int>(4, -1));
    // return helper(n - 1, 3, points, dp);
    int ans = 0;
    // base cases
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    // building table
    for (int currentDay = 1; currentDay < n; currentDay++)
    {
        for (int lastTask = 0; lastTask <= 3; lastTask++)
        {
            int ans = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task == lastTask)
                    continue;
                ans = max(ans, points[currentDay][task] + dp[currentDay - 1][task]);
            }
            dp[currentDay][lastTask] = ans;
        }
    }
    return dp[n - 1][3];
}
*/

// Space Optimized Solution
int maxPoints(Matrix &points)
{
    int n = points.size();
    vector<int> prev(4);
    int ans = 0;
    // base cases
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][1], points[0][0]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
    // building table
    for (int currentDay = 1; currentDay < n; currentDay++)
    {
        vector<int> current(4);
        for (int lastTask = 0; lastTask <= 3; lastTask++)
        {
            for (int task = 0; task < 3; task++)
            {
                if (task == lastTask)
                    continue;
                current[lastTask] = max(current[lastTask], points[currentDay][task] + prev[task]);
            }
        }
        prev = current;
    }
    return prev[3];
}

int main()
{
    Matrix points = {
        {94, 85, 49},
        {14, 63, 1},
        {35, 6, 80},
        {2, 65, 11},
        {94, 92, 47},
        {99, 97, 51}};
    cout << maxPoints(points);

    return 0;
}