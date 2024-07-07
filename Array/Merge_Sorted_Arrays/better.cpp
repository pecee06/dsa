#include "../../Utils/printArray.cpp"
#include <algorithm>

void merge(int arr1[], int n1, int arr2[], int n2)
{
    // O(n1 logn1 + n2 logn2)
    int right = n1 - 1, left = 0;
    // right for arr1 & left for arr2
    while (right >= 0 && left < n2)
    {
        if (arr1[right] > arr2[left])
            swap(arr1[right--], arr2[left++]);
        else
            break;
    }
    sort(arr1, arr1 + n1);
    sort(arr2, arr2 + n2);
}

int main()
{
    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {0, 2, 6, 8, 9};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    merge(arr1, n1, arr2, n2);
    printArray(arr1, n1);
    printArray(arr2, n2);

    return 0;
}