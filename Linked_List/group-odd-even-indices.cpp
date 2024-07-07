#include "../Utils/List.cpp"

void group(Node *head)
{
    auto odd = head, even = head->next;
    auto evenHead = even;
    while ((odd && odd->next) && (even && even->next))
    {
        auto temp = odd->next->next;
        odd->next = temp;
        odd = odd->next;
        temp = even->next->next;
        even->next = temp;
        even = even->next;
    }
    odd->next = evenHead;
}

int main()
{
    vector<int> v = {1, 3, 4, 2, 5, 6, 10};
    List l(v);
    group(l.getHead());
    l.print();

    return 0;
}
