#include <iostream>
using namespace std;

int longestSubarray(int arr[], int n, int k){   // O(n)
    // arr only contains positive numbers
    int sum = 0, len = 0, i, j;
    i = j = 0;
    while (j < n){
        sum += arr[j];
        while (i <= j && sum > k){
            sum -= arr[i];
            i++;
        }
        if (sum == k)
            len = max(len, j-i+1);
        j++;
    }
    return len;
}

int main(){
    int arr[] = {1,2,3,1,7,1,1,4,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cin>>k;
    cout<<longestSubarray(arr, n, k);

    return 0;
}