#include "../Utils/List.cpp"

Node *merge(Node *first, Node *second)
{
    // Write your code here.
    Node *head = NULL, *temp = NULL;
    while (first && second)
    {
        if (first->data <= second->data)
        {
            auto n = new Node(first->data);
            if (!head)
                head = temp = n;
            else
            {
                temp->next = n;
                temp = n;
            }
            first = first->next;
        }
        else
        {
            auto n = new Node(second->data);
            if (!head)
                head = temp = n;
            else
            {
                temp->next = n;
                temp = n;
            }
            second = second->next;
        }
    }
    while (first)
    {
        auto n = new Node(first->data);
        if (!head)
            head = temp = n;
        else
        {
            temp->next = n;
            temp = n;
        }
        first = first->next;
    }
    while (second)
    {
        auto n = new Node(second->data);
        if (!head)
            head = temp = n;
        else
        {
            temp->next = n;
            temp = n;
        }
        second = second->next;
    }
    return head;
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

Node *mergeSort(Node *head)
{
    if (!head || !head->next)
        return head;
    auto mid = middleNode(head);
    auto second = mid->next;
    mid->next = nullptr;
    auto leftHead = mergeSort(head);
    auto rightHead = mergeSort(second);
    return merge(leftHead, rightHead);
}

int main()
{
    vector<int> v = {7, 6, 2, 9, 1, 0, 0, 7, 8, 4, 6, 12};
    List l(v);
    l.setHead(mergeSort(l.getHead()));
    l.print();

    return 0;
}
