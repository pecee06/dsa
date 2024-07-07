#include "../../Utils/printArray.cpp"

void conditionalSwap(int arr1[], int index1, int arr2[], int index2)
{
    if (arr1[index1] > arr2[index2])
        swap(arr1[index1], arr2[index2]);
}

void merge(int arr1[], int n1, int arr2[], int n2)
{
    // O(N log N)
    // Gap Method
    int N = n1 + n2;
    int gap = N / 2 + N % 2;
    while (true)
    {
        int left = 0, right = gap;
        while (right < N)
        {
            if (right < n1)
            {
                // left & right in arr1
                conditionalSwap(arr1, left, arr1, right);
            }
            else if (left < n1 && right >= n1)
            {
                // left in arr1 & right in arr2
                conditionalSwap(arr1, left, arr2, right - n1);
            }
            else
            {
                // left & right in arr2
                conditionalSwap(arr2, left - n1, arr2, right - n1);
            }
            left++;
            right++;
        }
        if (gap == 1)
            break;
        gap = gap / 2 + gap % 2;
    }
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