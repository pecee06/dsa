#include <iostream>
#include <stack>
#include <vector>
#define vacant '\0'
using namespace std;

typedef vector<char> BinaryTree;

inline bool validPos(BinaryTree &t, int pos)
{
    return pos < t.size() && t[pos] != vacant;
}

void postorderTraversal(BinaryTree &t)
{ // T = O(n); S = O(n)
    t.insert(t.begin(), vacant);
    stack<int> s1, s2;
    s1.push(1);
    while (!s1.empty())
    {
        int nodePos = s1.top();
        s1.pop();
        s2.push(nodePos);
        int leftPos = 2 * nodePos;
        int rightPos = leftPos + 1;
        if (validPos(t, leftPos))
            s1.push(leftPos);
        if (validPos(t, rightPos))
            s1.push(rightPos);
    }
    while (!s2.empty())
    {
        cout << t[s2.top()] << " ";
        s2.pop();
    }
}

int main()
{
    BinaryTree t = {'a', 'b', 'f', 'c', 'd', vacant, 'g', vacant, vacant, vacant, 'e'};

    postorderTraversal(t);

    return 0;
}