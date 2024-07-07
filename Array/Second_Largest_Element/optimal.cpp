#include <iostream>
#include <climits>
using namespace std;

int secondMaxElement(int arr[], int n){ // O(n)
    int max = arr[0], secondMax = INT_MIN;
    for (int i=1; i<n; i++){
        if (arr[i] > max){
            secondMax = max;
            max = arr[i];
        }
        else if (arr[i] < max && arr[i] > secondMax)
            secondMax = arr[i];
    }
    return secondMax;
}

int main(){
    int arr[] = {5,6,2,2,44,8,9,7,11,6,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<secondMaxElement(arr, n);

    return 0;
}