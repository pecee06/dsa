#include <iostream>
#include <vector>
#define vacant '\0'
using namespace std;

typedef vector<char> BinaryTree;

void levelorderTraversal(BinaryTree &t)
{ // O(n)
    for (auto it : t)
    {
        if (it)
            cout << it << " ";
    }
    cout << endl;
}

int main()
{
    BinaryTree t = {'a', 'b', 'f', 'c', 'd', vacant, 'g', vacant, vacant, vacant, 'e'};

    levelorderTraversal(t);

    return 0;
}