#include <iostream>
#include <climits>
using namespace std;

int maxSubarraySum(int arr[], int n){   // O(n^2)
    int globalSum = INT_MIN;
    for (int i=0; i<n; i++){
        int localSum = 0;
        for (int j=i; j<n; j++){
            localSum += arr[j];
            globalSum = max(globalSum, localSum);
        }
    }
    return globalSum;
}

int main(){
    int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSubarraySum(arr, n);

    return 0;
}