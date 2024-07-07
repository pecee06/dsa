#include "../Utils/List.cpp"

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

Node *middleNode(Node *head)
{
    auto slow = head, fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool isPalindrome(Node *head)
{
    if (!head)
        return true;
    auto head2 = reverseList(middleNode(head)->next);
    while (head2)
    {
        if (head->data != head2->data)
            return false;
        head = head->next;
        head2 = head2->next;
    }
    return true;
}

int main()
{
    vector<vector<int>> m = {
        {1, 2, 3, 3, 2, 1},
        {1, 2, 3, 2, 1},
        {1, 3, 2, 5, 8},
        {1, 3, 2, 5, 8, 6},
        {},
        {1},
        {5, 8},
        {3, 3}};
    for (auto v : m)
    {
        List l(v);
        cout << isPalindrome(l.getHead()) << endl;
    }

    return 0;
}
