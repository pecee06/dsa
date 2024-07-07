#include <iostream>
using namespace std;

int uniqueNum(int arr[], int n){    // O(n^2)
    for (int i=0; i<n; i++){
        int count = 0;
        for (int j=0; j<n; j++){
            if (arr[j] == arr[i])
                count++;
        }
        if (count == 1)
            return arr[i];
    }
    return 0;
}

int main(){
    int arr[] = {1,1,2,3,3,4,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<uniqueNum(arr, n);

    return 0;
}