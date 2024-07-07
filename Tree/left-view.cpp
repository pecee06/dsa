#include "../Utils/BinaryTree.cpp"

void leftView(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            auto node = q.front();
            q.pop();
            if (!i)
                cout << node->data << " ";
            if (node->leftChild)
                q.push(node->leftChild);
            if (node->rightChild)
                q.push(node->rightChild);
        }
    }
}

int main()
{
    BinaryTree t;
    t.build();
    leftView(t.getRoot());

    return 0;
}
