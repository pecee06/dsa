#include "../Utils/printArray.cpp"

void bubbleSort(int arr[], int n){
    if (!n) return;
    for (int i=0; i<n-1; i++){
        if (arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
    }
    bubbleSort(arr, n-1);
}

int main(){
    int arr[] = {7,3,3,7,6,1,1,1,6,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printArray(arr, n);

    return 0;
}