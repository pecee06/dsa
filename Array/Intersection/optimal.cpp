#include "../../Utils/printVector.cpp"
#include <unordered_set>

void intersection(int sortedArr1[], int n1, int sortedArr2[], int n2, vector<int>& result){ // T = O(n); S = O(n)
    unordered_set<int> s(sortedArr1, sortedArr1+n1);
    for (int i=0; i<n2; i++){
        if (s.count(sortedArr2[i]) && (result.size() < 1 || result.back() != sortedArr2[i]))
            result.push_back(sortedArr2[i]);
    }
}

int main()
{
    int sortedArr1[] = {1,2,2,3,3,4,5,6};
    int n1 = sizeof(sortedArr1)/sizeof(sortedArr1[0]);

    int sortedArr2[] = {2,3,3,5,6,6,7};
    int n2 = sizeof(sortedArr2)/sizeof(sortedArr2[0]);

    vector<int> v;
    intersection(sortedArr1, n1, sortedArr2, n2, v);
    printVector(v);
    
    return 0;
}
