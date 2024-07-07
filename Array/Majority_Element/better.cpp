#include <iostream>
#include <unordered_map>
using namespace std;

int majorityElement(int arr[], int n){  // T = O(n); S = O(n)
    unordered_map<int,int> freq;
    for (int i=0; i<n; i++)
        freq[arr[i]]++;
    int maxFreq = 0, majorElem;
    for (auto it : freq){
        if (it.second > maxFreq){
            maxFreq = it.second;
            majorElem = it.first;
        }
    }
    return majorElem;
}

int main(){
    int arr[] = {2,2,3,3,1,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<majorityElement(arr, n);

    return 0;
}