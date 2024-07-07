#include <iostream>
using namespace std;

typedef struct Node
{
    int missing, repeating;
} Node;

Node findMissingAndRepeating(int arr[], int n)
{ // O(n^2)
    Node ans;
    int x = 0;
    bool foundRepeating = false;
    for (int i = 0; i < n; i++)
    {
        x = x ^ (i + 1) ^ arr[i];
        if (foundRepeating)
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                ans.repeating = arr[i];
                foundRepeating = true;
                break;
            }
        }
    }
    ans.missing = x ^ ans.repeating;
    return ans;
}

int main()
{
    int arr[] = {4, 3, 6, 2, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    auto node = findMissingAndRepeating(arr, n);
    cout << node.missing << "," << node.repeating << endl;

    return 0;
}