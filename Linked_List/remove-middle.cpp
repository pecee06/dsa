#include "../Utils/List.cpp"

Node *prevToMiddleNode(Node *head)
{
    auto slow = head, fast = head->next;
    if (!fast)
        return nullptr;
    fast = fast->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void removeMiddle(List &l)
{
    if (l.empty())
        return;
    auto prev = prevToMiddleNode(l.getHead());
    l.pop(prev);
}

int main()
{
    vector<vector<int>> m = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5, 6},
        {6, 8},
        {},
        {5}};

    for (auto v : m)
    {
        List l(v);
        removeMiddle(l);
        if (l.empty())
            cout << "NA\n";
        else
            l.print();
    }

    return 0;
}
