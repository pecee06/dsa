#include <iostream>
using namespace std;

int majorityElement(int arr[], int n){  // O(n)
    // Moore's Voting Algorithm - Only works if there exists a majority element
    int majorElem = arr[0], count = 0;
    for (int i=0; i<n; i++){
        if (arr[i] == majorElem)
            count++;
        else count--;
        if (!count)
            majorElem = arr[i+1];
    }
    return majorElem;
}

int main(){
    int arr[] = {2,2,3,3,1,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<majorityElement(arr, n);

    return 0;
}