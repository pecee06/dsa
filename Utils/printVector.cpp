#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& v){
    for (auto it : v)
        cout<<it<<" ";
    cout<<endl;
}