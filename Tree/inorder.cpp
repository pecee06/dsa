#include <iostream>
#include <stack>
#include <vector>
#define vacant '\0'
using namespace std;

typedef vector<char> BinaryTree;

void inorderTraversal(BinaryTree &t)
{ // T = O(n); S = O(n)
    t.insert(t.begin(), vacant);
    stack<int> s;
    int node = 1;
    while (t[node] || !s.empty())
    {
        while (t[node])
        {
            s.push(node);
            node = 2 * node; // left child
        }
        node = s.top();
        s.pop();
        cout << t[node] << " ";
        node = 2 * node + 1; // right child
    }
}

int main()
{
    BinaryTree t = {'a', 'b', 'f', 'c', 'd', vacant, 'g', vacant, vacant, vacant, 'e'};

    inorderTraversal(t);

    return 0;
}