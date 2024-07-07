#include <iostream>
#include <algorithm>
using namespace std;

int majorityElement(int arr[], int n){  // O(n logn)
    sort(arr, arr+n);
    return arr[n/2];
}

int main(){
    int arr[] = {2,2,3,3,1,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<majorityElement(arr, n);

    return 0;
}