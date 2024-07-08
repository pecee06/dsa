// Each lemonade costs 5 units
// Purpose - To sell as many lemonades as possible
// Initial balance = 0

#include <iostream>
using namespace std;

int lemonadesSold(int customerWithDenomination[], int n)
{
    int balance5 = 0, balance10 = 0, sales = 0;
    for (int i = 0; i < n; i++)
    {
        if (customerWithDenomination[i] == 5)
        {
            balance5++;
            sales++;
        }
        else if (customerWithDenomination[i] == 10)
        {
            if (balance5)
            {
                balance5--;
                balance10++;
                sales++;
            }
        }
        else
        {
            if (balance5 && balance10)
            {
                balance5--;
                balance10--;
                sales++;
            }
            else if (balance5 >= 3)
            {
                balance5 -= 3;
                sales++;
            }
        }
    }
    return sales;
}

int main()
{
    int customerWithDenomination[] = {5, 5, 5, 10, 20, 10, 10, 5, 10, 20, 5, 5, 20};
    // Only 3 denominations are possible, i.e., 5, 10 & 20
    int n = sizeof(customerWithDenomination) / sizeof(customerWithDenomination[0]);
    cout << lemonadesSold(customerWithDenomination, n);

    return 0;
}