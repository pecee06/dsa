#include "../../../Utils/printArray.cpp"
#include <deque>

void rotateByOnePlace(int arr[], int n){    // T = O(n); S = O(n)
    deque<int> dq(arr, arr+n);
    dq.pop_front();
    dq.push_back(arr[0]);
    int i=0;
    for (auto it : dq)
        arr[i++] = it;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    rotateByOnePlace(arr, n);
    printArray(arr, n);

    return 0;
}