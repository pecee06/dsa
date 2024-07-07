#include "../Utils/printArray.cpp"
#include <algorithm>

void nextPermutation(int arr[], int n){ // O(n)
    int breakPoint = -1;
    for (int i=n-2; i>=0; i--){
        if (arr[i] < arr[i+1]){
            breakPoint = i;
            break;
        }
    }
    if (breakPoint == -1){
        reverse(arr, arr+n);
        return;
    }
    int swappedWith;
    for (int i=n-1; i>=0; i--){
        if (arr[i] > arr[breakPoint]){
            swappedWith = i;
            break;
        }
    }
    swap(arr[breakPoint], arr[swappedWith]);
    reverse(arr+breakPoint+1, arr+n);
}

int main(){
    int arr[] = {2,1,5,4,3,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    nextPermutation(arr, n);
    printArray(arr, n);
    return 0;
}