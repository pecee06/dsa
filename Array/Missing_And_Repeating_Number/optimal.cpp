#include <iostream>
#include <unordered_set>
using namespace std;

typedef struct Node
{
    int missing, repeating;
} Node;

Node findMissingAndRepeating(int arr[], int n)
{ // O(n)
    Node ans;
    long sigmaN = n * (n + 1) / 2, actualSigmaN = 0;
    long sigmaNSquare = n * (n + 1) * (2 * n + 1) / 6, actualSigmaNSquare = 0;
    for (int i = 0; i < n; i++)
    {
        actualSigmaN += arr[i];
        actualSigmaNSquare += arr[i] * arr[i];
    }
    int xMinusY = sigmaN - actualSigmaN;
    int xsqMinusYsq = sigmaNSquare - actualSigmaNSquare;
    int xPlusY = xsqMinusYsq / xMinusY;
    ans.missing = (xPlusY + xMinusY) / 2;
    ans.repeating = xPlusY - ans.missing;
    return ans;
}

int main()
{
    int arr[] = {4, 3, 6, 2, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    auto node = findMissingAndRepeating(arr, n);
    cout << node.missing << "," << node.repeating << endl;

    return 0;
}