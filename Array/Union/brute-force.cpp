#include "../../Utils/printVector.cpp"
#include <set>

void Union(int sortedArr1[], int n1, int sortedArr2[], int n2, vector<int>& result){  // T = O(n logn); S = O(n)
    set<int> s(sortedArr1, sortedArr1+n1);
    for (int i=0; i<n2; i++)
        s.insert(sortedArr2[i]);
    for (auto it : s)
        result.push_back(it);
}

int main()
{
    int sortedArr1[] = {1,1,2,3,4,5};
    int n1 = sizeof(sortedArr1)/sizeof(sortedArr1[0]);

    int sortedArr2[] = {2,3,4,4,5};
    int n2 = sizeof(sortedArr2)/sizeof(sortedArr2[0]);

    vector<int> v;
    Union(sortedArr1, n1, sortedArr2, n2, v);
    printVector(v);
    
    return 0;
}
