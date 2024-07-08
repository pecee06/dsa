#include <iostream>
using namespace std;

bool canCross(int maxJumpSizes[], int n)
{
    int maxReachableIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > maxReachableIndex)
            return false;
        maxReachableIndex = max(maxReachableIndex, i + maxJumpSizes[i]);
    }
    return true;
}

int main()
{
    int maxJumpSizes[] = {1, 2, 4, 1, 1, 0, 2, 5};
    // int maxJumpSizes[] = {1, 2, 3, 1, 1, 0, 2, 5};
    int n = sizeof(maxJumpSizes) / sizeof(maxJumpSizes[0]);
    cout << canCross(maxJumpSizes, n);

    return 0;
}