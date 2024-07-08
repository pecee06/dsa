#include <iostream>
#include <string>
using namespace std;

typedef pair<int, int> PII;

bool validParentheses(string &s)
{
    PII minMax = {0, 0};
    for (auto c : s)
    {
        if (c == '(')
        {
            minMax.first++;
            minMax.second++;
        }
        else if (c == ')')
        {
            minMax.first--;
            minMax.second--;
        }
        else
        {
            minMax.first--;
            minMax.second++;
        }
        if (minMax.second < 0)
            return false;
        if (minMax.first < 0)
            minMax.first = 0;
    }
    if (minMax.first)
        return false;
    return true;
}

int main()
{
    string s; // string only contains '(', '*' & ')'
    // * can be replaced with '(', ')' or '' to make it a valid string
    cin >> s;
    cout << validParentheses(s);

    return 0;
}