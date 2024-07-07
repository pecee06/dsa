#include <iostream>
#include <algorithm>
using namespace std;

int maxElement(int arr[], int n){   // O(n logn)
    sort(arr, arr+n);
    return arr[n-1];
}

int main(){
    int arr[] = {5,6,2,2,44,8,9,7,11,6,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxElement(arr, n);

    return 0;
}