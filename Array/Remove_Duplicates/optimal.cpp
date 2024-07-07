#include "../../Utils/printArray.cpp"
#include <climits>

int removeDuplicates(int sortedArr[], int n){   // O(n)
    int left = 0, right = 1;

    while (right < n){
        if (sortedArr[right] != sortedArr[left])
            sortedArr[++left] = sortedArr[right];
        right++;
    }
    return left+1;
}

int main(){
    int sortetdArr[] = {1,1,2,2,2,3,3};
    int n = sizeof(sortetdArr)/sizeof(sortetdArr[0]);
    n = removeDuplicates(sortetdArr, n);
    printArray(sortetdArr, n);

    return 0;
}