#include "../Utils/BinaryTree.cpp"
#include <cstdlib>

inline bool isUnbalanced(int leftSubtreeHeight, int rightSubtreeHeight)
{
    return abs(leftSubtreeHeight - rightSubtreeHeight) > 1;
}

int checkBalance(Node *root)
{
    if (!root)
        return 0;
    if (BinaryTree::isLeafNode(root))
        return 1;
    int leftSubtreeHeight = checkBalance(root->leftChild);
    int rightSubtreeHeight = checkBalance(root->rightChild);
    if (isUnbalanced(leftSubtreeHeight, rightSubtreeHeight))
        return -1;
    return max(leftSubtreeHeight, rightSubtreeHeight) + 1;
}

int main()
{
    BinaryTree t;
    t.build();
    if (checkBalance(t.getRoot()) == -1)
        cout << "Tree is unbalanced\n";
    else
        cout << "Tree is balanced";

    return 0;
}
