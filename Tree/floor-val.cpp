#include "../Utils/BST.cpp"

void floorVal(Node *root, int &key, int &f)
{
    if (!root)
        return;
    if (key >= root->data)
    {
        f = max(f, root->data);
        floorVal(root->rightChild, key, f);
    }
    else
        floorVal(root->leftChild, key, f);
}

int main()
{
    BST t;
    t.build();
    cout << "Key: ";
    int key;
    cin >> key;
    int f = 0;
    floorVal(t.getRoot(), key, f);
    cout << f;

    return 0;
}
