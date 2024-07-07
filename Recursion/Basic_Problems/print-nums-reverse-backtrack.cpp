#include <iostream>
using namespace std;

void printNumsRev(int n){   // T = O(n); S = O(n)
    static int x = n+1;
    if (!n) return;
    printNumsRev(n-1);
    cout<<x-n<<endl;
}

int main(){
    int n;
    cin>>n;
    printNumsRev(n);

    return 0;
}