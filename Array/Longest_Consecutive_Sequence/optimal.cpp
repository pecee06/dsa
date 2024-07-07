#include <iostream>
#include <unordered_set>
using namespace std;

int longestConsecutiveSequence(int arr[], int n){   // T = O(n); S = O(n)
    unordered_set<int> s(arr, arr+n);
    int len = 1;
    for (auto it : s){
        if (s.count(it-1)) continue;
        int count = 1, x = 1;
        while (s.count(it+x)){
            count++;
            x++;
        }
        len = max(len, count);
    }
    return len;
}

int main(){
    int arr[] = {100,102,100,101,101,4,3,2,3,2,1,1,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<longestConsecutiveSequence(arr, n);

    return 0;
}