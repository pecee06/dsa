#include "../Utils/List.cpp"

Node *detectLoop(Node *head)
{
    auto slow = head, fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return slow;
    }
    return nullptr;
}

Node *loopHead(Node *head)
{
    auto n = detectLoop(head);
    if (!n)
        return nullptr;
    while (head != n)
    {
        head = head->next;
        n = n->next;
    }
    return n;
}

int main()
{
    // creating nodes
    auto head = new Node(1);
    auto n1 = new Node(2);
    auto n2 = new Node(3);
    auto n3 = new Node(4);
    auto n4 = new Node(5);

    // creating links
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = head;

    auto lh = loopHead(head);
    if (lh)
        cout << lh->data;
    else
        cout << "NA";

    return 0;
}
