#include <iostream>
#include <vector>
using namespace std;

int count = 0;

void merge(int arr[], int from, int mid, int to)
{
    vector<int> temp;
    int i = from, j = mid + 1;
    while (i <= mid && j <= to)
    {
        if (arr[i] < arr[j])
            temp.push_back(arr[i++]);
        else if (arr[i] > arr[j])
        {
            count += mid - i + 1;
            temp.push_back(arr[j++]);
        }
        else
        {
            temp.push_back(arr[i++]);
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= to)
        temp.push_back(arr[j++]);

    for (auto it : temp)
        arr[from++] = it;
}

void mergeSort(int arr[], int from, int to)
{
    if (from >= to)
        return;
    int mid = (from + to) / 2;
    mergeSort(arr, from, mid);
    mergeSort(arr, mid + 1, to);
    merge(arr, from, mid, to);
}

int inversions(int arr[], int n)
{ // T = O(n logn); S = O(n)
    mergeSort(arr, 0, n - 1);
    return count;
}

int main()
{
    int arr[] = {5, 3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << inversions(arr, n);

    return 0;
}