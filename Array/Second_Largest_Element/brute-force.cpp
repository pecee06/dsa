#include <iostream>
#include <algorithm>
using namespace std;

int secondMaxElement(int arr[], int n){ // O(n logn)
    sort(arr, arr+n, greater<int>());
    int max = arr[0];
    for (int i=1; i<n; i++){
        if (arr[i] != max)
            return arr[i];
    }
    return max;
}

int main(){
    int arr[] = {5,6,2,2,44,8,9,7,11,6,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<secondMaxElement(arr, n);

    return 0;
}