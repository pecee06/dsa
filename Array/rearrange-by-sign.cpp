#include "../Utils/printArray.cpp"
#include <queue>
typedef queue<int> Q;

void rearrange(int arr[], int n){   // T = O(n); S = O(n)
    pair<Q,Q> store;    // first -> negative, second -> positve
    for (int i=0; i<n; i++){
        if (arr[i] < 0)
            store.first.push(arr[i]);
        else store.second.push(arr[i]);
    }
    
    int i=0, count = 0;
    while (!store.second.empty()){
        arr[i] = store.second.front();
        store.second.pop();
        count++;
        if (count < n/2)
            i += 2;
        else i++;
    }
    
    i=1, count = 0;
    while (!store.first.empty()){
        arr[i] = store.first.front();
        store.first.pop();
        count++;
        if (count < n/2)
            i += 2;
        else i++;
    }
}

int main(){
    int arr[] = {3,1,-2,-5,2,-4,7,8,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    rearrange(arr, n);
    printArray(arr, n);

    return 0;
}