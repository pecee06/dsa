#include "../Utils/BST.cpp"

Node *inSuc(Node *root, int &val)
{
    static Node *node = NULL;
    if (!root)
        return node;
    if (val >= root->data)
        return inSuc(root->rightChild, val);
    if (val < root->data)
    {
        if (node)
        {
            if (root->data < node->data)
                node = root;
        }
        else
            node = root;
    }
    return inSuc(root->leftChild, val);
}

int main()
{
    BST t;
    t.build();
    cout << "Key: ";
    int key;
    cin >> key;
    auto successor = inSuc(t.getRoot(), key);
    if (successor)
        cout << successor->data;

    return 0;
}
