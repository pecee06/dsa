#include <iostream>
using namespace std;

int fibonacciTerm(int n){   // T = O(2^n); S = O(2^n)
    if (n < 1) return 0;
    if (n <= 2) return n-1;

    return fibonacciTerm(n-1) + fibonacciTerm(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<fibonacciTerm(n);

    return 0;
}