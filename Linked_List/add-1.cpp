#include "../Utils/List.cpp"

int carry(Node *head)
{
    if (!head)
        return 1;
    int sum = head->data + carry(head->next);
    head->data = sum % 10;
    return sum / 10;
}

void addOne(List &l)
{
    int hasNewHead = carry(l.getHead());
    if (hasNewHead)
        l.pushHead(1);
}

int main()
{
    vector<vector<int>> m = {
        {9, 9, 9, 9},
        {1, 2, 3},
        {}};

    for (auto v : m)
    {
        List l(v);
        addOne(l);
        l.print();
    }

    return 0;
}
