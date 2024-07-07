#include <algorithm>
#include "../Utils/printArray.cpp"

void selectionSort(int arr[], int n){
    if (!n) return;
    int maxIndex = max_element(arr, arr+n) - arr;
    swap(arr[maxIndex], arr[n-1]);
    selectionSort(arr, n-1);
}

int main(){
    int arr[] = {7,3,3,7,6,1,1,1,6,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}