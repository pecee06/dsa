#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string& str, int index=0){    // T = O(n); S = O(n)
    static int n = str.size();
    if (index == n || index == n-1) return true;
    bool ans = str[index] == str[--n];
    return ans && isPalindrome(str, index+1);
}

int main(){
    string str;
    cin>>str;
    cout<<isPalindrome(str);

    return 0;
}