#include <iostream>
using namespace std;

void printNumsRev(int n){   // T = O(n); S = O(n)
    if (!n) return;
    cout<<n<<endl;
    printNumsRev(n-1);
}

int main(){
    int n;
    cin>>n;
    printNumsRev(n);

    return 0;
}