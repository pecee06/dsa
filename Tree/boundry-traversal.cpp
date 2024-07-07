#include "../Utils/BinaryTree.cpp"
#include <stack>

void preorder(Node *root, queue<int> &q)
{
    if (!root || BinaryTree::isLeafNode(root))
        return;
    q.push(root->data);
    preorder(root->leftChild, q);
    preorder(root->rightChild, q);
}

void dfs(Node *root, stack<int> &s)
{
    if (!root || BinaryTree::isLeafNode(root))
        return;
    s.push(root->data);
    dfs(root->rightChild, s);
    dfs(root->leftChild, s);
}

void levelOrder(Node *root, queue<int> &q)
{
    if (!root)
        return;
    levelOrder(root->leftChild, q);
    if (BinaryTree::isLeafNode(root))
        q.push(root->data);
    levelOrder(root->rightChild, q);
}

void boundryTraversal(Node *root)
{
    queue<int> q;
    q.push(root->data);
    preorder(root->leftChild, q);
    levelOrder(root, q);
    stack<int> s;
    dfs(root->rightChild, s);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    BinaryTree t;
    t.build();
    boundryTraversal(t.getRoot());

    return 0;
}
