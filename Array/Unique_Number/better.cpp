#include <iostream>
#include <unordered_map>
using namespace std;

int uniqueNum(int arr[], int n){    // T = O(n); S = O(n)
    unordered_map<int,int> freq;
    for (int i=0; i<n; i++)
        freq[arr[i]]++;
    for (auto it : freq){
        if (it.second == 1)
            return it.first;
    }
    return 0;
}

int main(){
    int arr[] = {1,1,2,3,3,4,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<uniqueNum(arr, n);

    return 0;
}