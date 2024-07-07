#include "../../Utils/printArray.cpp"

void sort012(int arr[], int n){ // O(n)
    // Dutch National Flag (DNF) Algorithm
    int low = 0, mid = 0, high = n-1;
    while (mid <= high){
        if (arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 2){
            swap(arr[mid], arr[high]);
            high--;
        }
        else mid++;
    }
}

int main(){
    int arr[] = {0,1,2,0,1,2,1,2,0,0,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort012(arr, n);
    printArray(arr, n);

    return 0;
}