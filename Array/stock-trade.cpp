#include <iostream>
#include <climits>
using namespace std;

int maxProfit(int prices[], int n){ // O(n)
    int profit = 0, minPrice = INT_MAX;
    for (int i=0; i<n; i++){
        minPrice = min(minPrice, prices[i]);
        profit = max(profit, prices[i]-minPrice);
    }
    return profit;
}

int main(){
    int prices[] = {7,1,5,3,6,4};
    int n = sizeof(prices)/sizeof(prices[0]);
    cout<<maxProfit(prices, n);

    return 0;
}