#include "../../Utils/printArray.cpp"

void sort012(int arr[], int n){ // O(n)
    int freq[3] = {0};
    for (int i=0; i<n; i++)
        freq[arr[i]]++;
    int j = 0;
    for (int i=0; i<3; i++){
        while (freq[i]){
            arr[j++] = i;
            freq[i]--;
        }
    }
}

int main(){
    int arr[] = {0,1,2,0,1,2,1,2,0,0,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort012(arr, n);
    printArray(arr, n);

    return 0;
}