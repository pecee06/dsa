#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int longestConsecutiveSequence(int arr[], int n){   // O(n logn)
    sort(arr, arr+n);
    int lastSmaller = INT_MIN, currentLen = 0, maxLen = 0;
    for (int i=0; i<n; i++){
        if (arr[i] - 1 == lastSmaller){
            currentLen++;
            lastSmaller = arr[i];
        }
        else if (arr[i] - 1 > lastSmaller){
            currentLen = 1;
            lastSmaller = arr[i];
        }
        maxLen = max(maxLen, currentLen);
    }
    return maxLen;
}

int main(){
    int arr[] = {100,102,100,101,101,4,3,2,3,2,1,1,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<longestConsecutiveSequence(arr, n);

    return 0;
}