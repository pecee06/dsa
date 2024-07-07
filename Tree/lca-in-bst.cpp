#include "../Utils/BST.cpp"

int lca(Node *root, int &node1, int &node2)
{
    if (!root)
        return -1;
    if (root->data == node1 || root->data == node2)
        return root->data;
    if (node1 < root->data && node2 < root->data)
        return lca(root->leftChild, node1, node2);
    if (node1 > root->data && node2 > root->data)
        return lca(root->rightChild, node1, node2);
    return root->data;
}

int main()
{
    BST t;
    t.build();
    cout << "Nodes\n";
    int node1, node2;
    cin >> node1 >> node2;
    cout << lca(t.getRoot(), node1, node2);

    return 0;
}
