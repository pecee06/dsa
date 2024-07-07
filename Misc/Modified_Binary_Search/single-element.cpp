#include <iostream>
using namespace std;

bool isUniqueElem(int index, int arr[])
{
    if (arr[index] == arr[index - 1] || arr[index] == arr[index + 1])
        return false;
    return true;
}

int unique(int arr[], int n)
{
    if (!n)
        return -1;
    if (n == 1 || (arr[n - 1] != arr[n - 2]))
        return n - 1;
    if (arr[0] != arr[1])
        return 0;
    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isUniqueElem(mid, arr))
            return mid;
        bool inLeftPartOfUniqueElem;
        // left part -> even,odd
        // right part -> odd,even
        if (mid % 2)
        {
            // mid is odd
            if (arr[mid] == arr[mid - 1])
                inLeftPartOfUniqueElem = true;
            else
                inLeftPartOfUniqueElem = false;
        }
        else
        {
            // mid is even
            if (arr[mid] == arr[mid - 1])
                inLeftPartOfUniqueElem = false;
            else
                inLeftPartOfUniqueElem = true;
        }
        if (inLeftPartOfUniqueElem)
            low = mid + 1;
        else
            high = mid;
    }
    return -1;
}

int main()
{
    // int arr[] = {1, 1, 2, 2, 3, 3, 4, 4, 6, 7, 7};
    int arr[] = {1, 1, 2, 2, 3, 4, 4, 6, 7, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int uniqueIndex = unique(arr, n);
    if (uniqueIndex == -1)
        cout << "NA";
    else
        cout << arr[uniqueIndex];

    return 0;
}