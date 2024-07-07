#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII;

PII twoSum(int arr[], int n, int k){    // T = O(n logn)
    sort(arr, arr+n);
    int i = 0, j = n-1;
    PII ans = make_pair(-1,-1);
    while (i < j){
        int sum = arr[i] + arr[j];
        if (sum == k){
            ans = make_pair(arr[i], arr[j]);
            break;
        }
        else if (sum < k) i++;
        else j--;
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