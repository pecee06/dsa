#include <iostream>
using namespace std;
typedef pair<int,int> PII;

PII longestSubarray(int arr[], int n, int k){   // O(n^2)
    // arr only contains positive numbers
    int len = 0;
    PII ans = make_pair(-1,-1);
    for (int i=0; i<n; i++){
        int sum = 0;
        for (int j=i; j<n; j++){
            sum += arr[j];
            if (sum == k && j-i+1 > len){
                len = j-i+1;
                ans = make_pair(i,j);
            }
            else if (sum > k) break;
        }
    }
    return ans;
}

int main(){
    int arr[] = {1,2,3,1,1,1,1,4,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cin>>k;
    auto p = longestSubarray(arr, n, k);
    cout<<"("<<p.first<<","<<p.second<<")\n";

    return 0;
}