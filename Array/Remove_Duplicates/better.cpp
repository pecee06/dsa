#include "../../Utils/printArray.cpp"
#include <climits>

int removeDuplicates(int sortedArr[], int n){   // T = O(n); S = O(n)
    int* temp = new int[n];
    int newSize = 0;
    for (int i=0; i<n-1; i++){
        if (sortedArr[i] != sortedArr[i+1])
            temp[newSize++] = sortedArr[i];
    }
    temp[newSize++] = sortedArr[n-1];
    for (int i=0; i<n; i++){
        if (i < newSize)
            sortedArr[i] = temp[i];
        else sortedArr[i] = INT_MAX;
    }
    delete[] temp;
    return newSize;
}

int main(){
    int sortetdArr[] = {1,1,2,2,2,3,3};
    int n = sizeof(sortetdArr)/sizeof(sortetdArr[0]);
    n = removeDuplicates(sortetdArr, n);
    printArray(sortetdArr, n);

    return 0;
}