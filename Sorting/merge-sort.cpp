#include "../Utils/printArray.cpp"

void merge(int arr[], int from, int mid, int to){
    int* temp = new int[to-from+1];
    int i = mid+1, j = 0;
    while (from <= mid && i <= to){
        if (arr[from] < arr[i])
            temp[j++] = arr[from++];
        else if (arr[from] > arr[i])
            temp[j++] = arr[i++];
        else{
            temp[j++] = arr[from++];
            temp[j++] = arr[i++];
        }
    }

    while (from <= mid)
        temp[j++] = arr[from++];
    while (i <= to)
        temp[j++] = arr[i++];

    while (j)
        arr[to--] = temp[--j];
    
    delete[] temp;
}

void mergeSort(int arr[], int from, int to){
    if (from >= to) return;
    int mid = (from+to)/2;
    mergeSort(arr, from, mid);
    mergeSort(arr, mid+1, to);
    merge(arr, from, mid, to);
}

int main(){
    int arr[] = {7,3,3,7,6,1,1,1,6,9,9,4,0,6,1,9,3,7,1,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, n-1);
    printArray(arr, n);

    return 0;
}