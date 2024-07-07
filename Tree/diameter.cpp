#include "../Utils/BinaryTree.cpp"

int diameter(Node *root, int &d)
{
    if (!root)
        return 0;
    if (BinaryTree::isLeafNode(root))
        return 1;
    int leftAns = diameter(root->leftChild, d);
    int rightAns = diameter(root->rightChild, d);
    int height = max(leftAns, rightAns) + 1;
    int pathLen = leftAns + rightAns;
    d = max(d, pathLen);
    return height;
}

int main()
{
    BinaryTree t;
    t.build();
    int d = 0;
    diameter(t.getRoot(), d);
    cout << d;

    return 0;
}
