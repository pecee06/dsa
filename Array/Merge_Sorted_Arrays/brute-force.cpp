#include "../../Utils/printArray.cpp"
#include <vector>

void merge(int arr1[], int n1, int arr2[], int n2)
{ // T = O(n1 + n2); S = O(n1 + n2)
    vector<int> temp;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
            temp.push_back(arr1[i++]);
        else if (arr1[i] > arr2[j])
            temp.push_back(arr2[j++]);
        else
        {
            temp.push_back(arr1[i++]);
            temp.push_back(arr2[j++]);
        }
    }

    while (i < n1)
        temp.push_back(arr1[i++]);
    while (j < n2)
        temp.push_back(arr2[j++]);

    for (i = 0, j = 0; i < temp.size(); i++)
    {
        if (i >= n1)
            arr2[j++] = temp[i];
        else
            arr1[i] = temp[i];
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