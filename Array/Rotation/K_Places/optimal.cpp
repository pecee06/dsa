#include "../../../Utils/printArray.cpp"
#include <algorithm>

void rotateByKPlaces(int arr[], int n, int k){  // O(n)
    k = k%n;
    reverse(arr, arr+k);
    reverse(arr+k, arr+n);
    reverse(arr, arr+n);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cin>>k;
    rotateByKPlaces(arr, n, k);
    printArray(arr, n);
    
    return 0;
}