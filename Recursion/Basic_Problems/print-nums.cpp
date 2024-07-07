#include <iostream>
using namespace std;

void printNums(int n){  // T = O(n); S = O(n)
    static int x = 1;
    if (!n) return;
    cout<<x++<<endl;
    printNums(n-1);
}

int main(){
    int n;
    cin>>n;
    printNums(n);

    return 0;
}