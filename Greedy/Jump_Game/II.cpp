#include <iostream>
using namespace std;

int minJumsRequired(int maxJumpSizes[], int n)
{
    int l = 0, r = 0, steps = 0;
    while (r < n - 1)
    {
        int farthestIndex = l;
        for (int i = l; i <= r; i++)
            farthestIndex = max(farthestIndex, i + maxJumpSizes[i]);
        l = r + 1;
        r = farthestIndex;
        steps++;
    }
    return steps;
}

int main()
{
    int maxJumpSizes[] = {2, 3, 1, 4, 1, 1, 1, 2};
    int n = sizeof(maxJumpSizes) / sizeof(maxJumpSizes[0]);
    cout << minJumsRequired(maxJumpSizes, n);

    return 0;
}