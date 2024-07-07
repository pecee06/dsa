#include "../Utils/BinaryTree.cpp"
#include <vector>
#define INF (int)1e7

Node *generateBST(vector<int> &preorder, int &index, int upperBound)
{
    if (index >= preorder.size() || preorder[index] >= upperBound)
        return NULL;
    Node *root = new Node(preorder[index]);
    index++;
    root->leftChild = generateBST(preorder, index, root->data);
    root->rightChild = generateBST(preorder, index, upperBound);
    return root;
}

void inorderTraversal(Node *root)
{
    if (!root)
        return;
    inorderTraversal(root->leftChild);
    cout << root->data << " ";
    inorderTraversal(root->rightChild);
}

int main()
{
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    int i = 0;
    auto root = generateBST(preorder, i, INF);
    inorderTraversal(root);

    return 0;
}
