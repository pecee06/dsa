#include "../Utils/List.cpp"

Node *middleNode(Node *head)
{
    if (!head)
        return nullptr;
    auto slow = head, fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    vector<vector<int>> m = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5, 6},
        {},
        {5}};

    for (auto v : m)
    {
        List l(v);
        auto mid = middleNode(l.getHead());
        if (mid)
            cout << mid->data << " ";
        else
            cout << "NA ";
    }

    return 0;
}
