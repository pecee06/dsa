#include <iostream>
#include <string>
using namespace std;

void printName(string& name, int n){  // T = O(n); S = O(n)
  if (!n) return; // base case

  cout<<name<<endl;
  printName(name, n-1);
}

int main(){
  string name;
  cin>>name;
  int n;
  cin>>n;
  printName(name, n);

  return 0;
}