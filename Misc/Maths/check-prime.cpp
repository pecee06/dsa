#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{ // O(sqrt(n))
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    int upperLimit = sqrt(n);
    for (int i = 2; i <= upperLimit; i++)
    {
        if (!(n % i))
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    cout << isPrime(n);

    return 0;
}