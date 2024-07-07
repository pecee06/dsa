#include "../Utils/BST.cpp"
#include <stack>

class BstIterator
{
    stack<Node *> s;

    void populateStack(Node *root)
    {
        if (!root)
            return;
        s.push(root);
        populateStack(root->leftChild);
    }

public:
    BstIterator(Node *root)
    {
        s.push(root);
        populateStack(root->leftChild);
    }

    int next()
    {
        auto node = s.top();
        s.pop();
        if (node->rightChild)
            populateStack(node->rightChild);
        return node->data;
    }

    inline bool hasNext()
    {
        return !s.empty();
    }
};

int main()
{
    BST t;
    t.build();
    BstIterator it(t.getRoot());
    while (it.hasNext())
        cout << it.next() << " ";
    cout << endl;

    return 0;
}
