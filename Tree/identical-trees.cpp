#include "../Utils/BinaryTree.cpp"

bool areIdentical(Node *root1, Node *root2)
{
    if (!root1 || !root2)
        return root1 == root2;
    if ((root1->data == root2->data) && areIdentical(root1->leftChild, root2->leftChild) && areIdentical(root1->rightChild, root2->rightChild))
        return true;
    return false;
}

int main()
{
    BinaryTree t1, t2;
    cout << "Tree 1\n";
    t1.build();
    cout << "Tree 2\n";
    t2.build();
    cout << areIdentical(t1.getRoot(), t2.getRoot());

    return 0;
}
