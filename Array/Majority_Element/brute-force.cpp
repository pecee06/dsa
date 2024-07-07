#include <iostream>
using namespace std;

int majorityElement(int arr[], int n){  // O(n^2)
    int count, majorElem = -1;
    for (int i=0; i<n; i++){
        count = 0;
        for (int j=0; j<n; j++){
            if (arr[j] == arr[i])
                count++;
        }
        if (count > n/2){
            majorElem = arr[i];
            break;
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