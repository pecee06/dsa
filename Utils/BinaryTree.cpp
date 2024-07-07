#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *leftChild, *rightChild;
    Node(int data)
    {
        this->data = data;
        leftChild = rightChild = nullptr;
    }
};

class BinaryTree
{
    Node *root;

public:
    BinaryTree()
    {
        root = nullptr;
    }

    inline Node *getRoot()
    {
        return root;
    }

    static inline bool isLeafNode(Node *n)
    {
        return !n->leftChild && !n->rightChild;
    }

    Node *insertLeftChild(Node *n, int data)
    {
        n->leftChild = new Node(data);
        return n->leftChild;
    }

    Node *insertRightChild(Node *n, int data)
    {
        n->rightChild = new Node(data);
        return n->rightChild;
    }

    void build()
    {
        cout << "root: ";
        int r;
        cin >> r;
        root = new Node(r);
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            bool insertLChild, insertRChild;
            cout << "left child of " << node->data << "? [0/1]: ";
            cin >> insertLChild;
            if (insertLChild)
            {
                int lChild;
                cin >> lChild;
                auto leftChild = new Node(lChild);
                node->leftChild = leftChild;
                q.push(leftChild);
            }
            cout << "right child of " << node->data << "? [0/1]: ";
            cin >> insertRChild;
            if (insertRChild)
            {
                int rChild;
                cin >> rChild;
                auto rightChild = new Node(rChild);
                node->rightChild = rightChild;
                q.push(rightChild);
            }
        }
    }

    ~BinaryTree()
    {
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            if (node->leftChild)
                q.push(node->leftChild);
            if (node->rightChild)
                q.push(node->rightChild);
            delete node;
        }
    }
};