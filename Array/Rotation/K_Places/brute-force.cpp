#include "../../../Utils/printArray.cpp"
#include <deque>

void rotateByKPlaces(int arr[], int n, int k){  // T = O(n); S = O(n)
    k = k%n;
    deque<int> dq(arr, arr+n);
    for (int i=0; i<k; i++){
        dq.pop_front();
        dq.push_back(arr[i]);
    }
    int i=0;
    for (auto it : dq)
        arr[i++] = it;
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
