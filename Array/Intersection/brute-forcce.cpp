#include "../../Utils/printVector.cpp"

void intersection(int sortedArr1[], int n1, int sortedArr2[], int n2, vector<int>& result){ // T = O(n^2); S = O(n)
    vector<bool> visited(n2, false);
    for (int i=0; i<n1; i++){
        int j=0;
        while (j < n2 && sortedArr2[j] < sortedArr1[i]) j++;
        if (j < n2 && sortedArr2[j] == sortedArr1[i] && !visited[j] && (result.size() < 1 || result.back() != sortedArr1[i])){
            result.push_back(sortedArr1[i]);
            visited[j] = true;
        }
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
