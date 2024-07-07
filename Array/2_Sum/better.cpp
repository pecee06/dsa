#include <iostream>
#include <unordered_map>
using namespace std;
typedef pair<int,int> PII;

PII twoSum(int arr[], int n, int k){    // T = O(n); S = O(n)
    unordered_map<int,int> m;
    PII ans = make_pair(-1,-1);
    for (int i=0; i<n; i++){
        int lookingFor = k-arr[i];
        if (m.find(lookingFor) != m.end()){
            ans = make_pair(m[lookingFor], i);
            break;
        }
        m.insert(make_pair(arr[i], i));
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