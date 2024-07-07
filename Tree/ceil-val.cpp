#include "../Utils/BST.cpp"
#define INF (int)1e7

void ceilVal(Node *root, int &key, int &c)
{
    if (!root)
        return;
    if (key <= root->data)
    {
        c = min(c, root->data);
        ceilVal(root->leftChild, key, c);
    }
    else
        ceilVal(root->rightChild, key, c);
}

int main()
{
    BST t;
    t.build();
    cout << "Key: ";
    int key;
    cin >> key;
    int c = INF;
    ceilVal(t.getRoot(), key, c);
    cout << c;

    return 0;
}
