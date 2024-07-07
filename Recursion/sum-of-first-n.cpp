#include <iostream>
using namespace std;

int sumOfFirstN(int n){ // T = O(n); S = O(n)
    static int sum = 0;
    if (!n) return sum;
    sum += n;
    sumOfFirstN(n-1);
}

int main(){
    int n;
    cin>>n;
    cout<<sumOfFirstN(n);

    return 0;
}