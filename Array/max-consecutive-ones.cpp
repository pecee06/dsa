#include <iostream>
using namespace std;

int maxConsecutiveOnes(int arr[], int n){   // O(n)
    int maxOnes = 0, temp = 0;
    for (int i=0; i<n; i++){
        if (arr[i]) temp++;
        else{
            maxOnes = max(maxOnes, temp);
            temp = 0;
        }
    }
    return maxOnes;
}

int main(){
    int arr[] = {1,1,0,1,1,1,0,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxConsecutiveOnes(arr, n);

    return 0;
}