#include <iostream>
using namespace std;

int uniqueNum(int arr[], int n){    // O(n)
    int unique = 0;
    for (int i=0; i<n; i++)
        unique = unique ^ arr[i];
    return unique;
}

int main(){
    int arr[] = {1,1,2,3,3,4,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<uniqueNum(arr, n);

    return 0;
}