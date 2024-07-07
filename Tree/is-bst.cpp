#include "../Utils/BinaryTree.cpp"

bool validBSTNode(Node *n)
{
    if (!n->leftChild)
        return n->rightChild->data > n->data;
    if (!n->rightChild)
        return n->leftChild->data < n->data;
    return (n->leftChild->data < n->data) && (n->rightChild->data > n->data);
}

bool isBST(Node *root)
{
    if (!root || BinaryTree::isLeafNode(root))
        return true;
    if (validBSTNode(root))
    {
        bool leftAns = isBST(root->leftChild);
        bool rightAns = isBST(root->rightChild);
        return leftAns && rightAns;
    }
    return false;
}

int main()
{
    BinaryTree t;
    t.build();
    cout << isBST(t.getRoot());

    return 0;
}
