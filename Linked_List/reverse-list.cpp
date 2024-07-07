#include "../Utils/List.cpp"

Node *reverseListRecursive(Node *head, Node *prev = nullptr)
{
    if (!head)
        return prev;
    auto next = head->next;
    head->next = prev;
    return reverseListRecursive(next, head);
}

Node *reverseList(Node *head)
{
    if (!head)
        return nullptr;
    Node *curr = head, *prev1, *prev2;
    prev1 = prev2 = nullptr;
    while (curr)
    {
        prev2 = prev1;
        prev1 = curr;
        curr = curr->next;
        prev1->next = prev2;
    }
    prev1->next = prev2;
    return prev1;
}

int main()
{
    vector<int> v = {1, 3, 2, 5, 8, 9, 7};
    List l(v);
    l.setHead(reverseListRecursive(l.getHead()));
    l.print();
    l.setHead(reverseList(l.getHead()));
    l.print();

    return 0;
}
