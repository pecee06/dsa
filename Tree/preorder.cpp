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

void preorderTraversal(BinaryTree &t)
{                                // T = O(n); S = O(n)
    t.insert(t.begin(), vacant); // this is to start the indexing of BT from 1
    // left child -> 2i & right child -> 2i+1
    stack<int> s;
    s.push(1);
    while (!s.empty())
    {
        int nodePos = s.top();
        int leftPos = 2 * nodePos;
        int rightPos = leftPos + 1;
        s.pop();
        cout << t[nodePos] << " ";
        if (validPos(t, rightPos))
            s.push(rightPos);
        if (validPos(t, leftPos))
            s.push(leftPos);
    }
}

int main()
{
    BinaryTree t = {'a', 'b', 'f', 'c', 'd', vacant, 'g', vacant, vacant, vacant, 'e'};

    preorderTraversal(t);

    return 0;
}