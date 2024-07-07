#include <iostream>
#include <queue>
#include <vector>
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

class BST
{
    Node *root;

    void insert(Node *n, Node *prev, int &data)
    {
        if (!n)
        {
            if (data < prev->data)
                prev->leftChild = new Node(data);
            else
                prev->rightChild = new Node(data);
            return;
        }
        if (data == n->data)
            return;
        if (data < n->data)
            insert(n->leftChild, n, data);
        else
            insert(n->rightChild, n, data);
    }

    void inorderTraversal(Node *n, vector<int> &v)
    {
        if (!n)
            return;
        inorderTraversal(n->leftChild, v);
        v.push_back(n->data);
        inorderTraversal(n->rightChild, v);
    }

    Node *leftmostChild(Node *n)
    {
        if (!n)
            return nullptr;
        if (!n->leftChild)
            return n;
        return leftmostChild(n->leftChild);
    }

    Node *rightmostChild(Node *n)
    {
        if (!n)
            return nullptr;
        if (!n->rightChild)
            return n;
        return rightmostChild(n->rightChild);
    }

    Node *pop(Node *n, int key)
    {
        if (!n)
            return nullptr;
        if (isLeafNode(n))
        {
            delete n;
            return nullptr;
        }
        if (key < n->data)
            n->leftChild = pop(n->leftChild, key);
        else if (key > n->data)
            n->rightChild = pop(n->rightChild, key);
        else
        {
            auto inPre = rightmostChild(n->leftChild);
            if (!inPre)
            {
                auto inSuc = leftmostChild(n->rightChild);
                n->data = inSuc->data;
                n->rightChild = pop(n->rightChild, n->data);
            }
            else
            {
                n->data = inPre->data;
                n->leftChild = pop(n->leftChild, n->data);
            }
        }
    }

public:
    BST()
    {
        root = nullptr;
    }

    inline bool empty()
    {
        return !root;
    }

    inline Node *getRoot()
    {
        return root;
    }

    void insert(int data)
    {
        if (empty())
            root = new Node(data);
        else
            insert(root, nullptr, data);
    }

    void build()
    {
        cout << "No of nodes: ";
        int n, x;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            insert(x);
        }
    }

    vector<int> inorderTraversal()
    {
        vector<int> v;
        inorderTraversal(root, v);
        return v;
    }

    void pop(int key)
    {
        root = pop(root, key);
    }

    static inline bool isLeafNode(Node *n)
    {
        return !n->leftChild && !n->rightChild;
    }

    ~BST()
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