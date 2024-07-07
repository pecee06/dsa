#include "../Utils/printVector.cpp"

void leaders(int arr[], int n, vector<int>& result){    // O(n)
    int max = arr[n-1];
    result.push_back(arr[n-1]);
    for (int i=n-2; i>=0; i--){
        if (arr[i] > max){
            max = arr[i];
            result.push_back(max);
        }
    }
}

int main(){
    int arr[] = {10,22,12,3,0,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> result;
    leaders(arr, n, result);
    printVector(result);

    return 0;
}