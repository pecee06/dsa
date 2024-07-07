#include "../Utils/BST.cpp"

void kthSmallest(Node *root, int k, int &ans)
{
    static int elemCount = 0;
    if (!root)
        return;
    kthSmallest(root->leftChild, k, ans);
    elemCount++;
    if (elemCount == k)
        ans = root->data;
    kthSmallest(root->rightChild, k, ans);
}

int main()
{
    BST t;
    t.build();
    cout << "K: ";
    int k, ans;
    cin >> k;
    kthSmallest(t.getRoot(), k, ans);
    cout << ans;

    return 0;
}
