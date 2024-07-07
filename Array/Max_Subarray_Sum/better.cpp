#include <iostream>
#include <climits>
using namespace std;

int maxSubarraySum(int arr[], int n){   // O(n)
    int minSum = INT_MAX, maxSum = INT_MIN, sum = 0;
    for (int i=0; i<n; i++){
        sum += arr[i];
        if (sum < minSum)
            minSum = sum;
        maxSum = max(maxSum, sum-minSum);
    }
    return maxSum;
}

int main(){
    int arr[] = {-2,-3,4,-1,-2,-1,5,-3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxSubarraySum(arr, n);

    return 0;
}