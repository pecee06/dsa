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

Node *reverseInGroups(Node *head, int k)
{
    Node *temp = head, *prevChunkLast = nullptr;
    while (temp)
    {
        auto kthNode = temp;
        for (int i = 1; (i < k) && kthNode; i++)
            kthNode = kthNode->next;
        if (!kthNode)
        {
            if (prevChunkLast)
                prevChunkLast->next = temp;
            break;
        }
        auto next = kthNode->next;
        kthNode->next = nullptr;
        reverseList(temp);
        if (temp == head)
            head = kthNode;
        else
            prevChunkLast->next = kthNode;
        prevChunkLast = temp;
        temp = next;
    }
    return head;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    List l(v);
    int k;
    cin >> k;
    l.setHead(reverseInGroups(l.getHead(), k));
    l.print();

    return 0;
}
