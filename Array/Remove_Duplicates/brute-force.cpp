#include "../../Utils/printArray.cpp"
#include <set>

int removeDuplicates(int sortedArr[], int n){   // T = O(n logn); S = O(n)
    set<int> temp(sortedArr, sortedArr+n);
    int i=0;
    for (auto it : temp)
        sortedArr[i++] = it;
    return temp.size();
}

int main(){
    int sortetdArr[] = {1,1,2,2,2,3,3};
    int n = sizeof(sortetdArr)/sizeof(sortetdArr[0]);
    n = removeDuplicates(sortetdArr, n);
    printArray(sortetdArr, n);

    return 0;
}