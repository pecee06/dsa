#include "../Utils/BinaryTree.cpp"

void rightView(Node *root)
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
            if (node->rightChild)
                q.push(node->rightChild);
            if (node->leftChild)
                q.push(node->leftChild);
        }
    }
}

int main()
{
    BinaryTree t;
    t.build();
    rightView(t.getRoot());

    return 0;
}
