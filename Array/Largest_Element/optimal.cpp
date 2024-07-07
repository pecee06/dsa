#include <iostream>
using namespace std;

int maxElement(int arr[], int n){   // O(n)
    int max = arr[0];
    for (int i=1; i<n; i++){
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main(){
    int arr[] = {5,6,2,2,44,8,9,7,11,6,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxElement(arr, n);

    return 0;
}