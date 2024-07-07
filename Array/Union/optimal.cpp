#include "../../Utils/printVector.cpp"
#include <unordered_set>

void Union(int sortedArr1[], int n1, int sortedArr2[], int n2, vector<int>& result){  // T = O(n); S = O(n)
    unordered_set<int> s;
    int i = 0, j = 0;
    while (i < n1 && j < n2){
        if (sortedArr1[i] <= sortedArr2[j]){
            if (!s.count(sortedArr1[i])){
                result.push_back(sortedArr1[i]);
                s.insert(sortedArr1[i]);
            }
            if (sortedArr1[i] == sortedArr2[j]) j++;
            i++;
        }
        else if (sortedArr1[i] > sortedArr2[j]){
            if (!s.count(sortedArr2[j])){
                result.push_back(sortedArr2[j]);
                s.insert(sortedArr2[j]);
            }
            j++;
        }
    }
    while (i < n1){
        if (!s.count(sortedArr1[i])){
            result.push_back(sortedArr1[i]);
            s.insert(sortedArr1[i]);
        }
        i++;
    }
    while (j < n2){
        if (!s.count(sortedArr2[j])){
            result.push_back(sortedArr2[j]);
            s.insert(sortedArr2[j]);
        }
        j++;
    }
}

int main()
{
    int sortedArr1[] = {1,1,2,3,4,5};
    int n1 = sizeof(sortedArr1)/sizeof(sortedArr1[0]);

    int sortedArr2[] = {2,3,4,4,10};
    int n2 = sizeof(sortedArr2)/sizeof(sortedArr2[0]);

    vector<int> v;
    Union(sortedArr1, n1, sortedArr2, n2, v);
    printVector(v);
    
    return 0;
}
