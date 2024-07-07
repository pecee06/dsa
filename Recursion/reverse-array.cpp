#include <iostream>
using namespace std;

void reverseArray(int arr[], int n){    // T = O(n); S = O(n)
    static int index = 0;
    if (index == n || index == n-1) return;
    swap(arr[index++], arr[n-1]);
    reverseArray(arr, n-1);
}

void printArray(int arr[], int n){
    for (int i=0; i<n; i++)
        cout<<arr[i]<<endl;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    reverseArray(arr, n);
    printArray(arr, n);

    return 0;
}