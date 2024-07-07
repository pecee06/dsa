#include <iostream>
#include <climits>
using namespace std;

int maxSubarraySum(int arr[], int n){   // O(n)
    // Kadane's Algorithm
    int sum = 0, maxSum = INT_MIN;
    for (int i=0; i<n; i++){
        sum += arr[i];
        maxSum = max(maxSum, sum);
        if (sum < 0) sum = 0;
    }
    return maxSum;
}

int main(){
    int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSubarraySum(arr, n);

    return 0;
}