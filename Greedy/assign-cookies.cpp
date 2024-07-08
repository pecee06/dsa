// Purpose - To feed max number of children

#include <iostream>
#include <algorithm>
using namespace std;

int maxChildrenFed(int greedFactors[], int n1, int cookieSizes[], int n2)
{ // O(n1 logn1) + O(n2 logn2)
    sort(greedFactors, greedFactors + n1);
    sort(cookieSizes, cookieSizes + n2);
    int p1 = 0, p2 = 0;
    while (p1 < n1 && p2 < n2)
    {
        if (cookieSizes[p2] >= greedFactors[p1])
        {
            p1++;
            p2++;
        }
        else
            p2++;
    }
    return p1;
}

int main()
{
    int greedFactors[] = {1, 5, 3, 3, 4};
    int n1 = sizeof(greedFactors) / sizeof(greedFactors[0]);
    int cookieSizes[] = {4, 2, 1, 2, 1, 3};
    int n2 = sizeof(cookieSizes) / sizeof(cookieSizes[0]);
    cout << maxChildrenFed(greedFactors, n1, cookieSizes, n2);

    return 0;
}