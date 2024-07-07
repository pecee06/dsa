#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubarray(int arr[], int n, int k){   // T = O(n); S = O(n)
    // arr only contains positive numbers
    unordered_map<int,int> prefixSum;
    prefixSum.insert(make_pair(0,-1));
    int sum = 0, len = 0;
    for (int i=0; i<n; i++){
        sum += arr[i];
        prefixSum.insert(make_pair(sum, i));
        if (prefixSum.find(sum-k) != prefixSum.end())
            len = max(len, i-prefixSum[sum-k]);
    }
    return len;
}

int main(){
    int arr[] = {1,2,3,1,1,1,1,4,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cin>>k;
    cout<<longestSubarray(arr, n, k);

    return 0;
}