// Kid with a higher rating should get more candies than 2 of its adjacent kids and each kid should get atleast 1 candy

#include <iostream>
#include <vector>
using namespace std;

int minCandiesRequired(int kidsRating[], int n)
{
    if (!n)
        return 0;
    vector<int> temp(n);
    temp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (kidsRating[i] > kidsRating[i - 1])
            temp[i] = 1 + temp[i - 1];
        else
            temp[i] = 1;
    }
    int ans = temp[n - 1], prev = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (kidsRating[i] > kidsRating[i + 1])
            prev++;
        else
            prev = 1;
        ans += max(prev, temp[i]);
    }
    return ans;
}

int main()
{
    int kidsRating[] = {0, 2, 4, 7, 6, 5, 4, 3, 2, 1, 1, 1, 2, 3, 4, 2, 1, 1, 1};
    int n = sizeof(kidsRating) / sizeof(kidsRating[0]);
    cout << minCandiesRequired(kidsRating, n);

    return 0;
}