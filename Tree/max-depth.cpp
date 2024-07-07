#include "../Utils/BinaryTree.cpp"

int depth(Node *root)
{
    if (!root)
        return 0;
    if (BinaryTree::isLeafNode(root))
        return 1;
    int depthOfLeftSubtree = depth(root->leftChild);
    int depthOfRightSubtree = depth(root->rightChild);
    return max(depthOfLeftSubtree, depthOfRightSubtree) + 1;
}

int main()
{
    BinaryTree t;
    t.build();
    cout << depth(t.getRoot());

    return 0;
}
