#include "../../../Utils/printArray.cpp"

void rotateByOnePlace(int arr[], int n){    // O(n)
    int firstElem = arr[0];
    for (int i=0; i<n-1; i++)
        arr[i] = arr[i+1];
    arr[n-1] = firstElem;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    rotateByOnePlace(arr, n);
    printArray(arr, n);
    
    return 0;
}
