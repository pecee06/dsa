#include "../Utils/BST.cpp"

Node *findNode(Node *root, int &key)
{
    if (!root)
        return NULL;
    if (key == root->data)
        return root;
    if (key < root->data)
        return findNode(root->leftChild, key);
    findNode(root->rightChild, key);
}

int main()
{
    BST t;
    t.build();
    cout << "Key: ";
    int key;
    cin >> key;
    auto node = findNode(t.getRoot(), key);
    if (node)
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}
