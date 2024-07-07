#include <iostream>
using namespace std;
typedef pair<int,int> PII;

PII twoSum(int arr[], int n, int k){    // O(n^2)
    PII ans = make_pair(-1,-1);
    for (int i=0; i<n; i++){
        bool foundPair = false;
        for (int j=i+1; j<n; j++){
            if (arr[i] + arr[j] == k){
                ans = make_pair(i,j);
                foundPair = true;
                break;
            }
        }
        if (foundPair) break;
    }
    return ans;
}

int main(){
    int arr[] = {2,6,5,8,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cin>>k;
    auto p = twoSum(arr, n, k);
    cout<<p.first<<","<<p.second<<endl;

    return 0;
}