#include "../../Utils/printArray.cpp"

void moveZeroesToEnd(int arr[], int n){ // T = O(n); S = O(n)
    int* temp = new int[n];
    int j = 0;
    for (int i=0; i<n; i++){
        if (arr[i])
            temp[j++] = arr[i];
    }
    for (int i=0; i<n; i++){
        if (i < j)
            arr[i] = temp[i];
        else arr[i] = 0;
    }
    delete[] temp;
}

int main()
{
    int arr[] = {1,0,2,3,2,0,0,4,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    moveZeroesToEnd(arr, n);
    printArray(arr, n);
    
    return 0;
}
