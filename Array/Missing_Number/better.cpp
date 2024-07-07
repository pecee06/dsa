#include <iostream>
#include <vector>
using namespace std;

int missingNumber(int arr[], int n){    // T = O(n); S = O(n)
    vector<bool> present(n, false);
    for (int i=0; i<n-1; i++)
        present[arr[i]] = true;
    for (int i=1; i<=n; i++)
        if (!present[i]) return i;
    return 0;
}

int main(){
    int arr[] = {1,2,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<missingNumber(arr, size+1);

    return 0;
}