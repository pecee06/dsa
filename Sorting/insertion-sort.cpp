#include "../Utils/printArray.cpp"

void insert(int sortedArr[], int lastIndex, int elem){
    while (lastIndex >= 0 && sortedArr[lastIndex] > elem)
        sortedArr[lastIndex+1] = sortedArr[lastIndex--];
    sortedArr[lastIndex+1] = elem;
}

void insertionSort(int arr[], int n){
    for (int i=0; i<n-1; i++)
        insert(arr, i, arr[i+1]);
}

int main()
{
    int arr[] = {7,3,3,7,6,1,1,1,6,9,9,7,5,4,3,7,5,2,2,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
    printArray(arr, n);
    
    return 0;
}
