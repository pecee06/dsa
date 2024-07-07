#include <iostream>
using namespace std;

void printNums(int n){  // T = O(n); S = O(n)
    if (!n) return;
    printNums(n-1);
    cout<<n<<endl;
}

int main(){
    int n;
    cin>>n;
    printNums(n);

    return 0;
}