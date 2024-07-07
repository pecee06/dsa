#include <iostream>
#include <algorithm>
using namespace std;

int missingNumber(int arr[], int n){    // O(n^2)
    for (int i=1; i<=n; i++){
        bool present = false;
        for (int j=0; j<n-1; j++){
            if (arr[j] == i){
                present = true;
                break;
            }
        }
        if (!present) return i;
    }
    return 0;
}

int main(){
    int arr[] = {1,2,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<missingNumber(arr, size+1);

    return 0;
}