// A robber wants to rob a street which has houses in cirular fashion. No 2 adjacent houses can be robber (this will alert the police). Given money available in each house, find the max cut he can make safely

#include <iostream>
using namespace std;

int maxNonAdjacentSum(int arr[], int from, int to)
{
    // Subsequence can't have adjacent elements
    int pick, notPick = 0, prev1 = arr[from], prev2;
    for (int i = from + 1; i <= to; i++)
    {
        pick = arr[i];
        if (i > from + 1)
            pick += prev2;
        notPick = prev1;
        prev2 = prev1;
        prev1 = max(pick, notPick);
    }
    return prev1;
}

int maxCut(int moneyinHouse[], int houses)
{
    int leavingFirstHouse = maxNonAdjacentSum(moneyinHouse, 1, houses - 1);
    int leavingLastHouse = maxNonAdjacentSum(moneyinHouse, 0, houses - 2);
    return max(leavingFirstHouse, leavingLastHouse);
}

int main()
{
    int moneyinHouse[] = {1, 3, 2, 1};
    int n = sizeof(moneyinHouse) / sizeof(moneyinHouse[0]);
    cout << maxCut(moneyinHouse, n);

    return 0;
}