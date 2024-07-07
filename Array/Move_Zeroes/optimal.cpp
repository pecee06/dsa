#include "../../Utils/printArray.cpp"

void moveZeroesToEnd(int arr[], int n){ // O(n)
    int left = 0;
    while (left < n && arr[left])
        left++;
    if (left == n) return;
    int right = left+1;
    while (right < n){
        if (arr[right])
            swap(arr[left++], arr[right]);
        right++;
    }
}

int main()
{
    int arr[] = {1,0,2,3,2,0,0,4,5,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    moveZeroesToEnd(arr, n);
    printArray(arr, n);
    
    return 0;
}
