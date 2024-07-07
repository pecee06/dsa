#include <iostream>
#include <unordered_map>
using namespace std;

void majorElements(int arr[], int n)
{
    // Moore's Voting Algorithm
    int major1, major2, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        int currentElem = arr[i];
        if (!count1 || major1 == currentElem)
        {
            count1++;
            if (major2 != currentElem)
                major1 = currentElem;
        }
        else if (!count2 || major2 == currentElem)
        {
            count2++;
            if (major1 != currentElem)
                major2 = currentElem;
        }
        // else if (major1 == currentElem)
        //     count1++;
        // else if (major2 == currentElem)
        //     count2++;
        else
        {
            count1--;
            count2--;
        }
    }
    count1 = count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == major1)
            count1++;
        else if (arr[i] == major2)
            count2++;
    }
    if (count1 > n / 3)
        cout << major1 << " ";
    if (count2 > n / 3)
        cout << major2 << endl;
}

int main()
{
    int arr[] = {1, 1, 1, 3, 3, 2, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    majorElements(arr, n);

    return 0;
}