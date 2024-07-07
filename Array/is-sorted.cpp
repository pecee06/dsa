#include <iostream>
using namespace std;

bool isSorted(int arr[], int n){
    for (int i=0; i<n-1; i++){
        if (arr[i] > arr[i+1])
            return false;
    }
    return true;
}

int main(){
    int arr[] = {4,7,8,12,16,49,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<isSorted(arr, n);
    

    return 0;
}