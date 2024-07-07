#include "../Utils/BinaryTree.cpp"

int pathSum(Node *root, int &maxPathSum)
{
    if (!root)
        return 0;
    if (BinaryTree::isLeafNode(root))
        return root->data;
    int leftPathSum = pathSum(root->leftChild, maxPathSum);
    int rightPathSum = pathSum(root->rightChild, maxPathSum);
    int ps = leftPathSum + rightPathSum + root->data;
    maxPathSum = max(maxPathSum, ps);
    return ps;
}

int main()
{
    BinaryTree t;
    t.build();
    int maxPathSum = 0;
    pathSum(t.getRoot(), maxPathSum);
    cout << maxPathSum;

    return 0;
}
