#include <iostream>
#include <vector>
#define garbage (int)(-1e6)
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class List
{
    Node *head;

public:
    List()
    {
        head = nullptr;
    }

    List(vector<int> &items)
    {
        if (items.empty())
        {
            head = nullptr;
            return;
        }
        head = new Node(items[0]);
        auto temp = head;
        for (int i = 1; i < items.size(); i++)
        {
            temp->next = new Node(items[i]);
            temp = temp->next;
        }
    }

    inline Node *getHead()
    {
        return head;
    }

    inline void setHead(Node *head)
    {
        this->head = head;
    }

    inline bool empty()
    {
        return !head;
    }

    void build()
    {
        cout << "Nodes: ";
        int n, x;
        cin >> n;
        Node *temp = nullptr;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (!i)
            {
                head = new Node(x);
                temp = head;
            }
            else
            {
                temp->next = new Node(x);
                temp = temp->next;
            }
        }
    }

    Node *findNode(int key)
    {
        auto temp = head;
        while (temp)
        {
            if (temp->data == key)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void pushHead(int data)
    {
        auto temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    void pushBack(int data)
    {
        if (empty())
        {
            pushHead(data);
            return;
        }
        auto temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = new Node(data);
    }

    void pushAt(int index, int data)
    {
        if (index < 0)
            return;
        if (!index)
            pushHead(data);
        auto temp = head;
        int i = 1;
        while (temp && i < index)
        {
            temp = temp->next;
            i++;
        }
        if (!temp || !temp->next)
        {
            pushBack(data);
            return;
        }
        Node *n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }

    int popHead()
    {
        if (empty())
            return garbage;
        auto temp = head;
        int data = temp->data;
        head = head->next;
        delete temp;
        return data;
    }

    int popTail()
    {
        if (empty())
            return garbage;
        auto temp = head;
        while (temp->next->next)
            temp = temp->next;
        if (temp == head)
            return popHead();
        int data = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        return data;
    }

    int popAt(int index)
    {
        if (index < 0)
            return garbage;
        if (!index)
            return popHead();
        auto temp = head;
        int i = 1;
        while (temp && i < index)
        {
            temp = temp->next;
            i++;
        }
        if (!temp)
            return garbage;
        if (!temp->next)
            return popTail();
        auto n = temp->next;
        int data = n->data;
        temp->next = n->next;
        delete n;
        return data;
    }

    int pop(int key)
    {
        if (empty())
            return garbage;
        if (key == head->data)
            return popHead();
        auto temp = head;
        while (temp->next && temp->next->data != key)
            temp = temp->next;
        if (!temp->next)
            return garbage;
        auto n = temp->next;
        int data = n->data;
        temp->next = n->next;
        delete n;
        return data;
    }

    int pop(Node *prev)
    {
        if (empty())
            return garbage;
        if (!prev)
        {
            popHead();
            return head->data;
        }
        auto n = prev->next;
        int data = n->data;
        prev->next = n->next;
        delete n;
        return data;
    }

    int size()
    {
        int l = 0;
        auto temp = head;
        while (temp)
        {
            l++;
            temp = temp->next;
        }
        return l;
    }

    void print()
    {
        auto temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~List()
    {
        while (head)
        {
            auto temp = head;
            head = head->next;
            delete temp;
        }
    }
};